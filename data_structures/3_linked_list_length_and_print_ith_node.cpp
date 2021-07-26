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

// T = O(N) as we are just traversing the linked list.
int lengthOfLinkedList(Node *head)
{
    int length = 0;

    // incrementing over every node in our list, 
    // incrementing the length for each one that we find.
    // while head exists - same as head!=NULL
    while(head) 
    {
        length++;
        head = head->next;
    }
    return length;
}


void printIthNode(Node *head, int i)
{
      // handling for negative index search.
      //
      // NOTE: We do not want to call the length function
      //       to check for index out of bounds
      //       "... || i > lengthOfLinkedList(head)-1"
      //       because that is including T=O(n) to our
      //       print function making the total time complexity
      //       O(n) + O(i) [from while loop below] = O(n+i) = o(n) as n >>> i
      //       which would mean if we had a 10^3 n size list
      //       and wanted to find eg the 3rd element, it would
      //       be a waste - so we use the head != NULL below.
      if(i < 0)
      {
        cout << "-1" << endl;
        return;
      }

      // iterate over the array up to the ith element,
      // and only while head is not NULL. When we get to the
      // ith element we move head along to the ith node 
      // (and increment count).
      //
      // We start i at 1 because if we search at 0th index
      // we dont want to go through the while loop, we just
      // want to return the head we are currently on.
      int count = 1;
      while(count <= i && head != NULL) // T = O(i) on avg, T=O(n) for worst case - very large i
      {
        // if head is null the loop will break on the NEXT iteration
        // which is why we want the below if(head) condition
        head = head->next; 
        count++;
      }

      // if head exists is not NULL at the ith element (that we have
      // just iterated to above), then print it, otherwise
      // return -1 to show it doesn't exist. This check avoids the
      // runtime error that would arise from NULL->data
      if(head)
      {
        cout << head->data << endl;
      }
      else
      {
        cout << "-1" << endl;
      }
}


int main()
{
    // 1 2 3 4 5 -1
    Node* head = takeInputAtTail();
    int length = lengthOfLinkedList(head);

    cout << length << endl; // 5


    printIthNode(head, 0); // 1
    printIthNode(head, 8); // -1
    printIthNode(head, 4); // 5

    return 0;
}
