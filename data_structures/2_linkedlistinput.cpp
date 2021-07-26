#include<iostream>
using namespace std;

class Node 
{
   public:
     int data;
     Node *next; 

     Node(int data)
     {
       this->data = data;
       next = NULL; 
     }
};

void printLinkedList(Node *head)
{
    // It is good practice to use a temp variable
    // when dealing with a linked list.
    Node *temp = head;
    while(temp!=NULL){
        cout << temp->data << "-->";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

// We want to create a linked list using this
// function and return the head of the linked list.
// To return the head we need to make this function
// type Node*.
Node* takeInputAtTail()
{
   // In this case take user input for values 
   int data;
   cin >> data;

   Node *head = NULL; // These are null as the LL is empty
   Node *tail = NULL;

   // We use -1 as the terminator - we continue taking input
   // at the bottom of the while loop as long as the user
   // doesn't enter -1.
   //
   // NOTE: This has the obvious drawback of not being able
   //       to put -1 in the list.
   while(data != -1)
   {
        // DYNAMICALLY creating the nodes with the data
        // input from the user. This is because the scope
        // for static memory is just one iteration.
        Node *n = new Node(data);

        // Head is NULL when we create our first node.
        // So, upon creation of the first node we assign
        // both the head and tail to that node, as the list
        // contains one node at this point.
        if(head == NULL)
        {
            head = n;
            tail = n;
        }

        // If we have already got at least one node, we update
        // the tail to be the latest node. Note that the head
        // doesn't change.
        else 
        {
            tail->next = n;   // Inserting the node at the tail (end).
            tail = n;            
        }

        cin >> data;

   }

   // return the pointer to the head as that is all we need
   // for printing etc.
   return head; 

}


Node* takeInputAtHead()
{
   int data;
   cin >> data;

   Node *head = NULL;
   Node *tail = NULL;

   while(data != -1)
   {
        Node* n = new Node(data);

        if(head == NULL)
        {
            head = n;
            tail = n;
        }

        else 
        {
            // Inserting the node at the head (start).
            n->next = head; // new node points to previous head
            head = n; // head moved to new node.
        }

        cin >> data;

   }
   return head;   
}

int main()
{
    
    // Can insert data as "1 2 3 4 5" all on one line
    // as cin will take one integer at a time as our data is
    // integers.
    //
    Node* head = takeInputAtTail();
    printLinkedList(head); // 1-->2-->3-->4-->5-->NULL

    // Can also do...
    printLinkedList(takeInputAtTail());

    /*
        What is our time complexity for our takeInput functions?
        Each time we call it we do a constant amount of work to
        make the node. If we create N nodes this will take
        kN amount of work.

        So, T=O(N)
    */

    // If we give input "1 2 3 4 5"
    Node* head2 = takeInputAtHead();
    printLinkedList(head2); // 5-->4-->3-->2-->1-->NULL

    return 0;
}
