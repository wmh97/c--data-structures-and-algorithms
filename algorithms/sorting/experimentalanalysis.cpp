#include<iostream>
#include <sys/time.h>
using namespace std;

long getTimeInMicroSeconds()
{
	struct timeval currentTime;
	gettimeofday(&currentTime, NULL);
	return currentTime.tv_sec * (int)1e6 + currentTime.tv_usec;
}

void mergeArrays(int x[], int y[], int a[], int s, int e)
{
    int mid = (s + e)/2;
    int i = s;
    int j = mid + 1;
    int k = s;

    while(i <= mid && j <= e)
    {
        if(x[i] < y[j])
        {
            a[k] = x[i];
            i++;
            k++;
        }
        else
        {
            a[k] = y[j];
            j++;
            k++;
        }
    }

    while(i <= mid)
    {
        a[k] = x[i];
        k++;
        i++;
    }
    while(j <= e)
    {
        a[k] = y[j];
        k++;
        j++;
    }
}

int *x = new int[10000000];
int *y = new int[10000000];

void mergeSort(int a[], int s, int e)
{
    if(s >= e)
    {
        return;
    }

    int mid = (s + e)/2;

    for(int i = s; i <= mid; i++)
    {
        x[i] = a[i];
    }

    for(int i = mid + 1; i <= e; i++)
    {
        y[i] = a[i];
    }
    
    mergeSort(x, s, mid);
    mergeSort(y, mid + 1, e);
    mergeArrays(x, y, a, s, e);
}

void selectionSort(int a[], int n)
{
    for(int i=0; i <= n - 2; i++)
    {
        int smallest = i;
        for(int j = i + 1; j <= n - 1; j++)
        {
            if(a[j] < a[smallest])
            {
                smallest = j;
            }
        }
        swap(a[i], a[smallest]);
    }
}

int main()
{

    /*
        A good algorithm is one that takes less time and
        less memory. As in this example, time taken for
        execution of an algorithm is a function of input size.

        We could, if we wanted, plot a graph of time taken vs inputsize
        (e.g. t vs n), and the shape of the curve would give us
        the time dependency on input size. .e.g. first order
        polynomial, second order, log and so on.
    */

  // Testing sorting algorithms by getting them to sort arrays
  // with sizes increasing an order of magnitude per iteration.
  // starting at 10 --> 100 --> 1000 and so on.
  for(int n = 10; n <= 10000000; n *= 10)
  {
        // initialising new array of that size at runtime.
        // this way we can delete the array from memory at the
        // end of this iteration in this enclosing scope.
        int *arr = new int[n];
        
        long startTime, endTime;

        // populating the array - to be in descending order.
        // our sorting algorithms will them sort to ascending order.
        for(int i = 0; i < n; i++)
        {
            arr[i] = n - i;
        }

        // time the execution time of the sort per array size
        // for each type of sort.
        startTime = getTimeInMicroSeconds();

        mergeSort(arr, 0, n-1);
        // selectionSort(arr, n);

        endTime = getTimeInMicroSeconds();


        // print the time taken.
        cout << "Merge sort n = " << n << " time = " << endTime - startTime << endl;
        // cout << "Selection sort n = " << n << " time = " << endTime - startTime << endl;
        
        delete []arr; //cleanup of runtime memory allocated to arrays.
  }

  return 0;
}

// RESULTS: time in microseconds (10^-6)
//
// Selection sort n = 10 time = 0
// Selection sort n = 100 time = 0
// Selection sort n = 1000 time = 2990
// Selection sort n = 10000 time = 166848
// Selection sort n = 100000 time = 11870991
// ...
//
// Merge sort n = 10 time = 0
// Merge sort n = 100 time = 0
// Merge sort n = 1000 time = 39
// Merge sort n = 10000 time = 1973
// Merge sort n = 100000 time = 38865
// Merge sort n = 1000000 time = 223274
// Merge sort n = 10000000 time = 1474059
//
// Therefore merge sort is significantly faster.