#include<iostream>
using namespace std;

class Node 
{
   public:
     int data;
     Node *next; // type Node as it contains address of next Node

     Node(int data)
     {
       this->data = data;
       next = NULL;  // initially next is null.
     }
};

// passing the pointer itself BY REFERENCE so that when
// we move head along, we are modifying the original
// head pointer.
//
// NOTE: we want to be able to call the print function multiple
// times, so we want to make sure we are passing by value rather than
// by reference. That way when we move our head pointer to the end,
// it does not move the original pointer and thereby preventing us from
// doing further calls as the pointer would start at NULL and exit the
// loop.
//
// (for ref, passing by reference looks like: printLinkedList(Node *&head))
void printLinkedList(Node *head)
{

    // in order to print the linked list we only need
    // to know the head. Then we can iteratre the pointer
    // to following nodes until our head pointer reaches
    // NULL, i.e. the last element.
    while(head != NULL)
    {
        cout << head->data << "-->"; // print the data associated with that node
        head = head->next; // move the head along to the next node.
    }
    cout<<"NULL"<<endl;

    // NOTE: a possible way to emphasise that we are not modifying
    // the original pointer is to use a temp variable.
    // Node *temp = head;
    // while(temp!=NULL){
    //     cout<<temp->data<<" ";
    //     temp = temp->next;
    // }
    // cout<<endl;
}


int main()
{
    //------------------------------------------------
    // USING 2 NODES:
    //------------------------------------------------


    // Statically creating the objects, passing the data:
    Node n1(1);
    Node n2(2);

    // store address of n2 in pointer in n1 to connect the
    // two nodes.
    n1.next = &n2; 

    // The first node is called the head and the last node
    // is called the tail. Create pointers to these:
    //
    // Note that these are simply pointers to nodes, and not
    // nodes themselves.
    // Note that the size of a pointer is 8 bytes.
    Node *head = &n1; 
    Node *tail = &n2;
    
    // The below lines all print the values of node 1 and 2.
    // 'head->data' is a short way of writing:
    // (*head).data
    cout << n1.data << " " << n2.data << endl;
    cout << head->data << " " << n2.data << endl;
    cout << (*head).data << " " << n2.data << endl;


    //---------------------------------------------
    // CREATING ANOTHER 3 NODES AND THEIR POINTERS:
    //---------------------------------------------

    // Dynamically Allocating Nodes Example:
    //
    // The pointer will be assigned in the STACK
    // and the nodes themselves will be stored in the HEAP.
    Node* n3 = new Node(3);
    Node* n4 = new Node(4);
    Node* n5 = new Node(5);
    
    n2.next = n3; // Setting n2 so it is no longer null as we have more nodes.
    
    // assigning the "next" pointer. Note we dont need to use &
    // because it already contains an address.    
    n3->next = n4;
    n4->next = n5;  
    tail = n5; // setting tail as it has changed with more nodes.

    // We can make multiple calls to print as we are passing head by value.
    printLinkedList(head); // 1-->2-->3-->4-->5-->NULL
    printLinkedList(head); // 1-->2-->3-->4-->5-->NULL

    cout << head << endl;

    return 0;
}
