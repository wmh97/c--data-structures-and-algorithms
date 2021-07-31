#include<iostream>
using namespace std;

template<typename T> // type T is the data type of the contents fo our stack. Replace below as well.
class Stack
{
   T* arr; //
   
   int nextIndex;
   int capacity;
   
   public:

       Stack()
       {
          capacity = 4;
          arr = new T[capacity]; //
          nextIndex = 0;
       }

       Stack(int cap)
       {
         capacity = cap;
         arr = new T[capacity]; //
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
  
       void push(T element) //
       {
          if(nextIndex==capacity)
          {
            T* newArr = new T[2*capacity]; //
            for(int i=0; i<capacity; i++)
            {
                newArr[i] = arr[i];
            }
            delete []arr;
            arr = newArr;
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
       T top() //
       {
         if(isEmpty())
         {
            cout<<"Stack empty"<<endl;
            
            // NOTE - cant return -1 for type T as -1 is an int. Instead return 0.
            // This is because 0 can be an int,double,bool,char,NULL pointer and so on.
            return 0; 
         }
         return arr[nextIndex-1];
       }  
};

int main()
{
  Stack<int> stack; // initialise and specify which data type we want to use.
  
  cout << stack.top() << endl; // 0

  stack.push(1);
  stack.push(2);
  stack.push(3);
  stack.push(4);
  stack.push(5);

  cout << stack.top() << endl; // 5

  Stack<char> stack2;

  stack2.push('H');
  stack2.push('e');
  stack2.push('l');
  stack2.push('l');
  stack2.push('o');

  cout << stack2.top() << endl; // o




  return 0;
}
