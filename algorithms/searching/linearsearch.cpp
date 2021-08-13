#include<bits/stdc++.h>
using namespace std;

int linearSearch(int a[],int n,int key)
{

   for(int i=0; i<n; i++)
   {

        if(a[i] == key) // looking at each element and checking if it matches
        {
            return i;
        }
   }

   return -1; // return -1 to show key not found

}

int main()
{

   int a[] = {1, 2, 3, 4, 5};
   int SIZE = sizeof(a)/sizeof(int);

   cout << "enter key" << endl;
   int key;
   cin >> key;

   /*
        The time complexity is O(n) for both
        unsorted and sorted arrays. Linear search
        doesn't take into account if the array is sorted.

        We want to take log(n) steps when we are searching
        over an array that is already sorted. 
        
        For log(n)
        steps we have something called BINARY SEARCH
   */
   int pos = linearSearch(a, SIZE, key);
   
   if(pos == -1)
   {
        cout<<"key not found"<<endl;
   }
   else
   {
        cout<<"key found at index " << pos << endl;
   }

   return 0;
}
