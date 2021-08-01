#include<iostream>
using namespace std;

// Normal node class with value and pointer.
template <typename T>
class Node
{
public:
  T data;
  Node<T>* next; // because we are using templates we must specify <T> here.
      Node(T data)
      {
       this->data = data;
       next = NULL;
      }
} ;

template<typename T> // we have to write this above every class that uses T.
class Stack
{
   Node<T>* head; // keep track of the head as we will be inserting here when we push().
   int size; // size counter.

   public:
       Stack() // default to empty linked list upon construction.
       {
          head = NULL;
          size = 0;
       }

       int getSize()
       {
          return size; // simply return size counter.
       }

       bool isEmpty()
       {
          return size==0; // expr evaluated to true/false then returned
       }

       void push(T ele)
       {
          Node<T>* n = new Node<T>(ele); // make a new node containing the new element of data.
          n->next = head; // point the new node to the previous head.
          head = n; // assign the new node to be the new head.
          size++; // increment the size counter.
       }

       void pop()
       {
          if(isEmpty())
          {
            cout<<"Stack empty"<<endl;
            return;
          }

          Node<T>* temp = head; // store head in temp
          head = head->next; // move head to the next node along so we are not pointing to (now)old head.
          temp->next = NULL; // isolate the old head node we have stored in temp.
          delete temp; // delete the old head. Can do this through temp as they are pointers to the original address.
          size--;  // decrease the size.
       }

       T top()
       {
         if(isEmpty())
         {
            cout<<"Stack empty"<<endl;
            return 0;
         }
         return head->data; // return the value at head.
       }
};

int main(){
  
  /*
    The time complexity of all our functions is T=O(1)
    The LL method is prefereable to array as you do not need to
    worry about copying all the data to increase the size.
  */
  Stack<int> s;

  s.push(100);
  s.push(101);
  s.push(102);
  s.push(103);
  s.push(104);

  cout<<s.top()<<endl;
  s.pop();

  cout<<s.top()<<endl;
  s.pop();

  cout<<s.top()<<endl;
  s.pop();

  cout<<s.getSize()<<endl; // from 5, pop 3, --> 2
  cout<<s.isEmpty()<<endl; // 0
   return 0;
}
