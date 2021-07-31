#include<iostream>
using namespace std;

class Stack
{
   // These members are private.
   
   // We don't know the size of our array so
   // we need to use a dynamic array. 
   int *arr;
   
   int nextIndex;
   int capacity;
   
   public:

       // default constructor for when user doesn't give the size
       // of the stack.
       Stack()
       {
          arr = new int[4];
          nextIndex = 0;
       }
       Stack(int cap)
       {
         capacity = cap;
         arr = new int[capacity]; // dynamically create array of size specified
         nextIndex = 0; // next index defaults to zero as we are at beginning of stack.
       }
       
       int size()
       {
          // return no of elements present in stack which is the value of nextIndex.
          // i.e. 0 for empty, 1 for one element, etc.
          return nextIndex; 
       }
       bool isEmpty()
       {
         return nextIndex==0; // will evaluate expression and then return.
       }
  
       void push(int element)
       {
          // If we are at capacity then we are full.
          // E.g. if we specify capacity is 4 then the next 
          if(nextIndex == capacity)
          {
            cout<<"Stack full"<<endl;
            return;
          }
          
          // push element to top of stack and
          // increment the nextIndex value that points
          // to the top.
          // E.g. if capcity is 4 then the top element
          // is at element 3 and the nextIndex will be 4.
          arr[nextIndex] = element;
          nextIndex++;
       }
       void pop() // remove the top element.
       {
          if(isEmpty()) // stop nextIndex going to negative
          {
            cout<<"Stack empty"<<endl;
            return;
          }

          // decrement the nextIndex - this doesn't
          // delete that element but makes it so we will
          // automatically overwrite it on next push().
          nextIndex--;
       }
       int top()
       {
         if(isEmpty()) // cant return top if the stack is empty.
         {
            cout<<"Stack empty"<<endl;
            return -1;
         }
         return arr[nextIndex-1]; // return value at index before nextIndex
       }  
};

int main()
{
  Stack stack(4);

  cout << stack.isEmpty() << endl; // 1

  stack.push(1);
  stack.push(2);
  stack.push(3);
  stack.push(4);

  cout << stack.top() << endl; // 4
  cout << stack.isEmpty() << endl; // 0

  stack.push(0); // stack full

  return 0;
}
