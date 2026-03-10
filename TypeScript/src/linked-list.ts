class ListNode<T> {
  next?: ListNode<T>;
  constructor(public value: T) {}
}

class LinkedList<T> {
  private head?: ListNode<T>;
  private tail?: ListNode<T>;
  private length = 0;

  add(val: T) {
    const tempNode = new ListNode(val);
    if (!this.head || !this.tail) {
      this.head = tempNode;
      this.tail = tempNode;
    } else {
      this.tail.next = tempNode;
      this.tail = tempNode;
    }
    this.length++;
  }
  get getHead() {
    return this.head;
  }
  get getLength() {
    return this.length;
  }

  // add insert at a specific positoinn function
  // add delete a node at a specific position function.

  print() {
    let t = this.head;
    while (t) {
      console.log(t.value);
      t = t.next;
    }
  }
}

let l = new LinkedList<number>();

l.add(1);
l.add(2);
l.add(3);
l.add(4);

l.print();
