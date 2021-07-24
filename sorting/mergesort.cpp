#include <iostream>
using namespace std;

/*
    This solution is good because we are never copying the
    array, we are always performing modifications on the
    original array.
*/

// passing array as a pointer - an arrays name *is* a pointer
// anyway. Could also do void merge(int a[], ...)
void merge(int *a, int startpos, int endpos)
{

    int mid = (startpos + endpos) / 2;

    int lhs_pos = startpos; // lhs array ckecking position
    int rhs_pos = mid + 1; // rhs array checking position
    int merged_pos = startpos; // position in merged array - starts at start of overall array

    int temp[100]; // to store what the merged array will be.

    // looking at each part of the array to be merged:
    // ie from lhs start pos --> mid and from mid --> rhs end pos.
    //
    // NOTE: By the time we are merging these, the arrays are sorted,
    //       and ranging from size 1 upwards.
    while (lhs_pos <= mid && rhs_pos <= endpos)
    {
        // checking values of lhs array against rhs array.
        // if the lhs array has the smaller value put it in the
        // temp array. Then move the lhs pos up one, and check
        // that against the rhs pos value. Then the rhs might be
        // smaller so move the rhs pos up one and check the new
        // rhs value against that lhs pos value...
        // and so on.
        //
        // of course when we assign a value to temp, increment
        // the temp pos counter.
        if (a[lhs_pos] < a[rhs_pos])
        {
            temp[merged_pos++] = a[lhs_pos++]; // performs assignment and THEN increments
        }
        else
        {
            temp[merged_pos++] = a[rhs_pos++];
        }

    }

    // the above loop will be executed if EITHER lhs_pos gets
    // to mid, or rhs_pos gets to end. In that case we need
    // to copy across the remaining elements.
    while (lhs_pos <= mid)
    {
        temp[merged_pos++] = a[lhs_pos++];
    }
    while (rhs_pos <= endpos)
    {
        temp[merged_pos++] = a[rhs_pos++];
    }

    //We need to copy all element from temp to original arrays
    for (int i = startpos; i <= endpos; i++)
    {
        a[i] = temp[i];
    }
}

void mergeSort(int a[], int startpos, int endpos)
{

    //Base case - 1 or 0 elements
    if (startpos >= endpos)
    {
        return;
    }

    //Follow 3 steps
    //1. Divide
    int mid = (startpos + endpos) / 2;

    //2. Recursively the arrays - s,mid and mid+1,e
    //
    // If we have got down to one element arrays, these
    // recursive calls just return, and we then go on to the
    // call to merge.
    //
    // Then all the recursive calls to merge execute until we
    // get to this top level call to merge below.
    mergeSort(a, startpos, mid);
    mergeSort(a, mid + 1, endpos);

    //3. Merge the two parts given their start and end indexes
    merge(a, startpos, endpos);
}

int main()
{
    int a[] = {7, 3, 10, 5, 6, 2, -5};
    
    // startpos 0, endpos 6 because there are 7 elements
    // in total.
    mergeSort(a, 0, 6);

    // printing sorted array.
    for (int i = 0; i < 7; i++)
    {
        cout << a[i] << " ";
    }
    // --> -5 2 3 5 6 7 10

    return 0;
}