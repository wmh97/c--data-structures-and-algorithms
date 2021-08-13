#include<iostream>
using std::cout;
using std::cin;
using std::endl;

int partition(int a[],int start, int end)
{
     
     // use this variable to determine the pivot index.
     // starting at the start of the array
     int pivot_index = start;

     // The pivot element is the element at the end of
     // the array.
     int pivot = a[end];

     for(int j = start; j <= end-1; j++)
     {
        // checking each element of the array against the
        // pivot value. If the value is smaller than the pivot
        // value we swap it with the value currently at the
        // pivot index, and move the pivot index up one.
        if(a[j] < pivot)
        {
            std::swap(a[pivot_index], a[j]);
            pivot_index++;
        }
     }

     // once we have looped over the whole array, we have
     // found the true pivot index so put the pivot value
     // there, swapping it with the value that it contains.
     // (By the above, we would be swapping the pivot value
     // with a value greater than it).
     std::swap(a[pivot_index], a[end]);
     
     // Now we have elements smaller than the pivot value on
     // the LHS, and those greater on the RHS.
     // We return the pivot index (the pos in the array of the
     // pivot value).
     return pivot_index;
}

void quickSort(int a[],int start,int end)
{
    if(start >= end)
    {
        return;
    }

    int pivot_index = partition(a, start, end);

    // With recursion we then perform quicksorts on the
    // LHS and RHS of the array, the elements either side of
    // the pivot element.
    //
    // i.e. the LHS and RHS excluding the pivot element.
    //
    // NOTE: unlike many diagrams, with this method we are
    //       always editing the original array so we do not
    //       have to merge the arrays together again.
    quickSort(a, start, pivot_index-1); // LHS
    quickSort(a, pivot_index+1, end); // RHS
}

int main()
{

   int unsorted_array[] = {8, 5, 2, 1, 3, 7, 4};

   for (int i = 0; i < sizeof(unsorted_array)/sizeof(int); i++)
   {
       cout << unsorted_array[i];
   }
   cout << endl;

   quickSort(unsorted_array, 0, 6);

   for (int i = 0; i < sizeof(unsorted_array)/sizeof(int); i++)
   {
       cout << unsorted_array[i];
   }
   cout << endl;

   return 0;
}
