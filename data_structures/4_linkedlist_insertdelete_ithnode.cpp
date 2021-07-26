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
    Node *temp = head;
    while(temp!=NULL)
    {
        cout << temp->data << "-->";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

Node* takeInputAtTail()
{
   int data;
   cin >> data;

   Node *head = NULL;
   Node *tail = NULL;

   while(data != -1)
   {
        Node *n = new Node(data);

        if(head == NULL)
        {
            head = n;
            tail = n;
        }
        else 
        {
            tail->next = n; 
            tail = n;            
        }

        cin >> data;

   }
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
            n->next = head;
            head = n;
        }

        cin >> data;

   }
   return head;   
}

int lengthOfLinkedList(Node *head)
{
    int length = 0;
    while(head) 
    {
        length++;
        head = head->next;
    }
    return length;
}


void printIthNode(Node *head, int i)
{
      if(i < 0)
      {
        cout << "-1" << endl;
        return;
      }

      int count = 1;
      while(count <= i && head != NULL)
      {
        head = head->next; 
        count++;
      }
      
      if(head)
      {
        cout << head->data << endl;
      }
      else
      {
        cout << "-1" << endl;
      }
}

// T = O(i) as we only have one loop iterating over i and the
// rest is constant work. Worst case T = O(N)
Node* insertAtithPos(Node* head, int data, int i)
{
      // return head of list if index input is invalid.
      if(i < 0)
      {
        return head;
      }

      // for index == 0, make a new node that points to the head, and then
      // make that new node the head of the list and return it.
      if(i == 0)
      {
        
        Node* newNode = new Node(data);
        newNode->next = head;
        head = newNode;

        return head;
      }

      Node* listHead = head; // store pointer to the head of the whole list

      // iterate up to i-1th node. 
      //
      // NOTE: This while loop will not be entered when i = 1. In the case
      // where i=1, we are already pointing to the i-1th node as it is the
      // head of the list that we are starting on.
      int count = 1;
      while(count <= i-1 && head != NULL)
      {        
        head = head->next; // move head along to the index denoted by count
        count++;
      }
      // At this point head will have moved along to point at the i-1th node.

      // if i-1th node exists (ie the address that head now points to is not NULL)
      if(head)
      {
        Node* newNode = new Node(data); // create new node

        newNode->next = head->next; // make the new node point to the node the i-1th node was pointing to
        head->next = newNode; // make the i-1th node now point to the new node
    
        return listHead; // *** NOTE: return the head of the whole list. ***
      }

      // deafult case - return head of list if index is otherwise too high.
      return listHead;
}

// T= O(i), or worst case T=O(N)
Node* deleteithPos(Node* head, int i)
{
      if(i < 0)
      {
        return head;
      }

      // make sure our head exists - otherwise 
      // NULL->next will give a runtime error.
      // Need to make sure we are handling these cases in our
      // code.
      Node* toDelete;
      if(i == 0 && head) 
      {
        
        toDelete = head;
        head = head->next;

        // Avoiding memory leak where we have memory
        // allocated to an address but we dont have 
        // any way to access that address.
        toDelete->next = NULL; // isolate the node.
        delete toDelete; // delete the thing that is at the address the pointer is pointing at
        
        // NOTE: for deleting memory pointed to by pointers - we only need
        // to NULL the pointer itself when the pointer has been dynamically assigned with the
        // *new* keyword.
        // toDelete = NULL; // the pointer is still pointing to that old address so clear it.

        return head;
      }

      Node* listHead = head;
      int count = 1;
      while(count <= i-1 && head != NULL)
      {        
        head = head->next;
        count++;
      }

      // again making sure head->next is not NULL so we 
      // don't get a runtime error from NULL->next.
      // So we need to make sure we are not already at the end of
      // the linked list.
      //
      // We we have something->next we have to make sure that
      // something exists. This is what we have been doing so far
      // with our !=NULL conditions.
      if(head && head->next) 
      {
        toDelete = head->next;
        head->next = head->next->next;

        // make sure we have isolated the first node before we
        // deallocate the memory. If we lose our first node we cannot
        // find the other nodes if we havent stored their address.
        toDelete->next = NULL; // isolating from other nodes - it is not not pointing to anything
        delete toDelete;
        
        // NOTE: for deleting memory pointed to by pointers - we only need
        // to NULL the pointer itself when the pointer has been dynamically assigned with the
        // *new* keyword.
        // toDelete = NULL; // the pointer is still pointing to that old address so clear it.

        return listHead;
      }

      return listHead;
}

int main()
{

    Node* head = takeInputAtTail();
    printLinkedList(head);
    
    // We can insert at index 5 as that is one after index 4 which is
    // our greatest, as in this case we have an i-1th node to point to the
    // new node.
    //
    // Otherwise we have no i-1th node to point to the new node.
    printLinkedList(insertAtithPos(head, 99, 6));
    printLinkedList(insertAtithPos(head, 99, 5));
    printLinkedList(insertAtithPos(head, 99, 1));
    
    // We cant call the print function successively like above when our function
    // is changine the head pointer. This is because the head pointer is passed
    // by value, and we return the new head pointer. So, we need to store our new head
    // pointer in our head variable to make sure it updates.
    //
    // We can still modify the list nodes by passing head by value because we use
    // the address that is in head to make the modifications - the only thing is that
    // the address stored in head doesn't get changed unless we reassign it here.
    head = insertAtithPos(head, 99, 0);
    head = insertAtithPos(head, 99, 0);

    printLinkedList(head);

    cout << head << endl;

    head = deleteithPos(head, 0);
    printLinkedList(head);

    cout << head << endl;

    return 0;
}
