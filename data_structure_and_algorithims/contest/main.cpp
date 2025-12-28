#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
   int t ;
   cin >> t;
   while(t--)
   {
        int m,n;
        cin >> n >> m;

        vector<int> arr(n, 1);
        int itr = 0;
        for (int i = 0; i < n - m ; i++)
        {
            itr = (itr + 2) % n;
            while (arr[itr] == 0)
            {
                itr++;
            }
            arr[itr] = 0;

        }

    for (int i = 0; i < n; i++)
        if (arr[i])
            cout << i + 1 << endl;
   }

    return 0;
}
