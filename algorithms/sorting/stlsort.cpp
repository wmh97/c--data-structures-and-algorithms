#include<bits/stdc++.h>
using namespace std;

int main(){

    int n = 5;
    int a[n] = {5, 4, 3, 2, 1};

    // C++ has a built in sort function as this is a very
    // common functionality and it takes time to implement
    // ourselves.
    //
    // sort is from the algorithm.h header file.
    // We can include this by doing:
    // #include<algorithm>
    //
    // OR, as we have done above,
    // we can include the master header file,
    // "bits/stdc++.h" which contains all of the
    // header files in C++ ie cmath, iostream, vector,
    // etc
    sort(a, a+n); 


    for(int i=0; i<n; i++)
    {
        cout << a[i] << " ";
    }


   return 0;
}
