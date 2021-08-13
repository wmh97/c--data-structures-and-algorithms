#include<iostream>
using namespace std;

void bubblesort(int a[],int n)
{

    int step_counter = 0;

    // number of passes we need to do. If we do n-1 passes then
    // we have sorted n-1 out of n elements in the array, and so
    // by definition n is also sorted in the correct position.
    //
    // After each pass, the largest element goes to the right most
    // position
    for(int count=1; count<=n-1 ;count++)
    {
        step_counter++;

        // start off with setting sorted flag to true as we
        // have not yet done any checking.
        bool sorted = true;

        // For each pass we go up to the (n-2)th element. Since
        // n is the size, this is the penultimate element.
        for(int j=0; j<=n-2 ;j++)
        {
            step_counter++;
            
            // We are looking at adjacent elements - note we have
            // j+1 here so when we get to the penultimate element
            // we are indeed comparing it to the final element.
            if(a[j] > a[j+1])
            {
                swap(a[j], a[j+1]);
                
                // When we discover an element to swap, indicate that on this
                // pass our array is not sorted.
                sorted = false;
            }
        }

        // If we have done a whole pass through the array and sorted has
        // not been set to false, our array is sorted, and we can break the
        // loop after at least one pass.
        if (sorted)
        {
            cout << "Steps Taken: " << step_counter << endl;
            return; // or break;
        }
    }

    cout << "Steps Taken: " << step_counter << endl;

}

int main()
{

   // ----------------------------------------------------------
   // ------------Starting with unsorted array: ----------------
   // ----------------------------------------------------------

   int SIZE = 20;
   int a[SIZE] = {
       20, 19, 18, 17, 16, 
       15, 14, 13, 12, 11, 
       10, 9, 8, 7, 6, 
       5, 4, 3, 2, 1
   };

   for(int i = 0; i < SIZE; i++)
   {
        cout << a[i] << " ";
   }
   cout << endl;

   /*
        Steps taken to complete bubble sort:
        (n-1) * (n-2) = n^2 + n + c

        If we had n = 10^6 we would have
        10^12 + 10^6 + c ... and since 10^12 dominates
        then then we can say
        (n-1)*(n-2) == n^2

        This is the TIME COMPLEXITY (number of steps)
        the program takes to execute. The notation for
        this is big O.

        So the time complexity of bubble sort is
        O(n^2). Note that selection sort was also O(n^2)

        The best algorithm is the one which takes
        least time - ie has the lowest time complexity.

        ALSO we want to make sure that when we start
        with a sorted array, or a partially/mostly sorted
        array, we do not go through the full amount of
        steps that we would had it been unsorted. To do this
        we introduce a 'sorted' flag so that the program
        identifies when the array is sorted and drops out.
        
        This is called OPTIMISED BUBBLE SORT and means that
        our time complexity is O(n) when starting with a
        sorted array.
   */

   bubblesort(a, SIZE); // --> 380 steps ~= O(n^2)

   for(int i = 0; i < SIZE; i++)
   {
        cout << a[i] << " ";
   }
   cout << endl << endl;

   // ----------------------------------------------------------
   // -------------Starting with sorted array: -----------------
   // ----------------------------------------------------------

   int b[SIZE] = {
       1, 2, 3, 4, 5, 
       6, 7, 8, 9, 10, 
       11, 12, 13, 14, 15, 
       16, 17, 18, 19, 20
    };

   for(int i = 0; i < SIZE; i++)
   {
        cout << b[i] << " ";
   }
   cout << endl;

   bubblesort(b, SIZE); // --> 20 steps = O(n)

   for(int i = 0; i < SIZE; i++)
   {
        cout << b[i] << " ";
   }
   cout << endl;



   return 0;
}
