#include<bits/stdc++.h>
using namespace std;

int BinarySearch(int a[],int n,int key)
{
    int start_index = 0, end_index = n-1;
    
    // the value is not in our array when the start index is
    // greater than the end index (i.e. we can no longer calculate a midpoint)
    //
    // If we don't find the key after a certain number of iterations
    // we will end up with our start and end point on the final or first index.
    // In these cases the midpoint is calculated to be that same element.
    // (1) if we are at the first element the value will be lower so 
    //     the end pos will be set to lower than the start pos and we will
    //     break the loop
    // (2) if we are at the last element the value will be higher so the
    //     start pos will be set higher than the end pos and we will break
    //     the loop.
    while(start_index <= end_index) 
    {
        
        // We are calculating the midpoint by ((s+e)/2). However in the case that
        // we have a very big array, the numbers of start and end will can get very
        // large.
        //
        // If the sum of s and e are too large, we might exceed the maximum allowed
        // value for an integer (INT_MAX = 2^31 - 1), in which case there will be
        // integer overflow, and the wrap around value will be negative so we will be
        // searching for a negative index and we would get a runtime error.
        // (note that the opposite of integer overflow, where the value is less than
        // INT_MIN, is known as integer underflow).
        //
        // Therefore we write in the style below as when expanded it gives the same
        // expression. Therefore the contents of the brackets will be small and we
        // will not encounter integer overflow.
        int midpoint = start_index + ( (end_index - start_index)/2 );

        if(a[midpoint] == key)
        {
            return midpoint;
        }
        else if(a[midpoint] > key)
        {
            // We know that from the midpoint, the values increase in size so we
            // discard right hand side of array including current midpoint
            end_index = midpoint - 1; 
        }
        else
        {
            // as above, the LHS is decreasing in value, so we can discard it
            // and set the start to the element after the midpoint.
            start_index = midpoint + 1;
        }
    }

    return -1; // return -1 to show we dont have the value in our array.

}

int main()
{


   int SIZE = 20;
   int a[SIZE] = {
       1, 2, 3, 4, 5,
       6, 7, 8, 9, 10,
       11, 12, 13, 14, 15, 
       16, 17, 18, 19, 20
   };

   cout << "enter key" << endl;
   int key;
   cin >> key;

   // Note that sort is from the std namespace
   std::sort(a,a+SIZE);

   int pos = BinarySearch(a,SIZE,key);
   if(pos == -1)
   {
        cout << "key not found" << endl;
   }
   else
   {
        cout << "key found at index " << pos << endl;
   }

   return 0;
}

