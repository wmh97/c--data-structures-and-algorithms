#include<iostream>
using namespace std;

class Stack
{
   // These members are private.
   
   // We don't know the size of our array so
   // we need to use a dynamic array. 
   int* arr;
   
   int nextIndex;
   int capacity;
   
   public:

       // our default constructor sets our capacity varaible
       // at a default value of 4.
       Stack()
       {
          capacity = 4;
          arr = new int[capacity];
          nextIndex = 0;
       }

       // When our stack is dynamic we no longer need to
       // define our capcaity ourself, unless we want it
       // to start at a large value to avoid copying.
       Stack(int cap)
       {
         capacity = cap;
         arr = new int[capacity];
         nextIndex = 0; 
       }
       
       int size()
       {
          return nextIndex; 
       }

       bool isEmpty()
       {
         return nextIndex==0;
       }
  
       void push(int element)
       {
          if(nextIndex==capacity)
          {
            
            // making a new array with twice the capacity.
            // We do this using a dynamic array as weve seen before.
            int* newArr = new int[2*capacity];
            
            // using a loop to copy our old array to the new one.
            for(int i=0;i<capacity;i++)
            {
                newArr[i] = arr[i];
            }

            // deallocating the memory taken by our old array.
            delete []arr;

            // pointing the pointer to the old array, to the new array.
            arr = newArr;

            // updating our capacity variable as our array size has now doubled.
            capacity = 2*capacity;
          }

          arr[nextIndex] = element;
          nextIndex++;
       }
       void pop()
       {
          if(isEmpty())
          {
            cout<<"Stack empty"<<endl;
            return;
          }

          nextIndex--;
       }
       int top()
       {
         if(isEmpty())
         {
            cout<<"Stack empty"<<endl;
            return -1;
         }
         return arr[nextIndex-1];
       }  
};

int main()
{
  Stack stack;

  stack.push(1);
  stack.push(2);
  stack.push(3);
  stack.push(4);
  stack.push(5);
  stack.push(6);
  stack.push(7);
  stack.push(8);
  stack.push(9);
  stack.push(10);

  cout << stack.top() << endl; // 10
  stack.pop();
  cout << stack.top() << endl; // 9



  return 0;
}
