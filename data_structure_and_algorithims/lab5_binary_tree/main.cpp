#include <iostream>


using namespace std;

struct node
{
    int data;
    node* left = nullptr;
    node*right = nullptr;
};

node* createNode(int val)
{
    node* tmp = new node;
    tmp->data = val;
    tmp->left = nullptr;
    tmp->right = nullptr;
    return tmp;
}


// 1 >> inorder, 2 >> preorder, 3 >> postorder
void display(node* root, int type)
{
    if (!root)
    {
        return;
    }
    switch (type)
    {
    case 1: // inorder left , root, right
        display(root->left, 1);
        cout << root->data << " , ";
        display(root->right, 1);
        break;
    case 2: // preorder  root, left, right
        cout << root->data << " , ";
        display(root->left, 2);
        display(root->right, 2);
        break;
    case 3: // postorder left, right, root
        display(root->left, 3);
        display(root->right, 3);
        cout << root->data << " , ";
        break;
    default:
        break;
    }
}

node* insertNode(node* root, int val)
{
    if (root == nullptr)
        return createNode(val);
    if (val >= root->data)
    {
        root->right = insertNode(root->right, val);
    }
    else if (val < root->data)
    {
        root->left = insertNode(root->left, val);
    }
    return root;
}

node* searchNode(node* root, int val)
{
    if (!root)
        return nullptr;
    if (root->data == val)
        return root;
    if (root->data > val)
    {
        // go left
        searchNode(root->left, val);

    }
    else if (root->data < val)
    {
        // go right
        searchNode(root->right, val);
    }
}

node* findMin(node* root)
{
    while (root && root->left != nullptr)
        root = root->left;
    return root;
}

node* deleteNode(node* root, int val)
{
    if (!root)
        return nullptr;

    if (val < root->data)
    {
        root->left = deleteNode(root->left, val);
    }
    else if (val > root->data)
    {
        root->right = deleteNode(root->right, val);
    }
    else
    {

        if (!root->left)
        {
            node* temp = root->right;
            delete root;
            return temp;
        }
        else if (!root->right)
        {
            node* temp = root->left;
            delete root;
            return temp;
        }

        node* temp = findMin(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

int main()
{
    node* root = nullptr;

    root = insertNode(root, 10);
    root = insertNode(root, 5);
    root = insertNode(root, 20);
    root = insertNode(root, 3);
    root = insertNode(root, 7);

    //display(root, 1);
    //display(root, 2);
    //display(root, 3);

    node* tmp = searchNode(root, 5);
    display(tmp, 1);

    deleteNode(root, 20);
    display(root, 1);
    return 0;
}

