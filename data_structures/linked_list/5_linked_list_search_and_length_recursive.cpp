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

// int lengthOfLinkedList(Node *head)
// {
//     int length = 0;
//     while(head) 
//     {
//         length++;
//         head = head->next;
//     }
//     return length;
// }


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

Node* insertAtithPos(Node* head, int data, int i)
{
      if(i < 0)
      {
        return head;
      }

      if(i == 0)
      {
        
        Node* newNode = new Node(data);
        newNode->next = head;
        head = newNode;

        return head;
      }

      Node* listHead = head;

      int count = 1;
      while(count <= i-1 && head != NULL)
      {        
        head = head->next;
        count++;
      }

      if(head)
      {
        Node* newNode = new Node(data);

        newNode->next = head->next; 
        head->next = newNode; 
    
        return listHead; 
      }

      return listHead;
}


Node* deleteithPos(Node* head, int i)
{
      if(i < 0)
      {
        return head;
      }

      Node* toDelete;
      if(i == 0 && head) 
      {
        
        toDelete = head;
        head = head->next;

        toDelete->next = NULL; 
        delete toDelete; 

        return head;
      }

      Node* listHead = head;
      int count = 1;
      while(count <= i-1 && head != NULL)
      {        
        head = head->next;
        count++;
      }

      if(head && head->next) 
      {
        toDelete = head->next;
        head->next = head->next->next;

        toDelete->next = NULL;
        delete toDelete;

        return listHead;
      }

      return listHead;
}

// This will keep calling recursively until the
// end of the list where the return value is zero:
// return 1+1+1+1+...+0 then sum up as the nested recursive calls
// finish from inner to outer.
int lengthRecursive(Node* head)
{
  if(head == NULL) return 0; // base case - list does not exist
  return 1 + lengthRecursive(head->next);
}

// checking to see if a value is present, returns
// true if it is and false if we get to the end of
// the list where head==NULL and we haven't found our
// value.
bool isPresent(Node* head, int data)
{
  Node* currentNode = head;
  while(currentNode != NULL)
  {
    if(currentNode->data == data)
    {
      return true;
    }
    currentNode = currentNode->next;
  }
  return false;
}

bool isPresentRecursive(Node* head, int data)
{
  // two simple conditions - false if there is no linked
  // list. true if we've found our data.
  if(head == NULL) return false;
  if(head->data == data) return true;

  // keep calling recursively until we meet one of the
  // two above conditions.
  return isPresentRecursive(head->next, data);
}

int main()
{
  
  // 1 2 7 3 -1
  Node* head = takeInputAtTail();

  // Call Stack:
  // NULL - base case
  // 3
  // 7
  // 2
  // 1
  // main() - here
  //
  // T = O(N) because we need to go through every node.
  // So T is the same as the iterative function.
  // The difference is in the space complexity. Iterative has S=O(1)
  // For recursive we have a number of calls in the call
  // stack equal to number of elements N. So S=O(N).
  //
  // So the ITERATIVE function is BETTER.
  cout << lengthRecursive(head) << endl; // return 4

  // T = O(N), S=O(1)
  cout << "(Iterative) 1 is present: " << isPresent(head, 1) << endl; // --> 1 which means true
  
  // call stack:
  // NULL (reach this if our data isnt present)
  // 3 --> returns true and passes through 7,2,1 to main.
  // 7
  // 2
  // 1
  // main()
  //
  // T = O(N), S = O(N)
  // Again ITERATIVE solution is BETTER
  cout << "(Recursive) 3 is present: " << isPresentRecursive(head, 3) << endl; // --> 1 which means true
  cout << "(Recursive) 9 is present: " << isPresentRecursive(head, 9) << endl; // --> 0 which means false

  return 0;
}
