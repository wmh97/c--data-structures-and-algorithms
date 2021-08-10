#include<iostream>
#include<vector>
#include<algorithm>

int main()
{
   std::vector<int> v;

   v.push_back(1);
   v.push_back(2);
   v.push_back(3);

   v[1] = 100;

   std::cout << v[0] << std::endl; // 1
   std::cout << v[1] << std::endl; // 100
   std::cout << v[2] << std::endl; // 3

   v[3] = 5; // assign elements using [] to indexes
   v[4] = 6; // that dont yet exist.

   v.push_back(9); // Then push back two values which will
   v.push_back(10); // overlap with the two above.

   // We might think we would get an output like this:
   // 1, 100, 3, 5, 6, 9, 10
   // BUT
   // when we assign values with square brackets, the
   // vector does not know this should be the back of the
   // vector. SO when we go to print them, the values we
   // assigned with [] are essentially lost and instead
   // we print past the end of the vector, and get garbage values.
   //
   // Here we get two garbage values (0, 7012688) to 'represent' the two
   // lost values we inserted in square brackets
   //
   // ACTUAL:
   // 1, 100, 3, 9, 10, 0, 7012688
   //
   // So, NEVER insert using square brackets [].
   std::cout << v[0] << std::endl;
   std::cout << v[1] << std::endl;
   std::cout << v[2] << std::endl;
   std::cout << v[3] << std::endl;
   std::cout << v[4] << std::endl;
   std::cout << v[5] << std::endl; // by here we are simply reaching
   std::cout << v[6] << std::endl; // beyond the memory address of the array.

   // We can see our above method of insertion with []
   // did not change the brackets.
   // 1, 100, 3, 9, 10
   for(int i : v) std::cout << i << std::endl;

   // the at() function gets the value in the vector
   // at a given index.
   //
   // so at() is much safer to access values in the
   // vector as it will actually check if the index is 
   // valid, unlike above.
   std::cout << v.at(4) << std::endl; // 10
   //std::cout << v.at(6) << std::endl; // not a valid index --> error

   // size() give the current number of elements.
   // capacity() gives the maximum size (no of elements)
   // that the vector can have before it needs to be resized.
   std::cout << v.size() << std::endl; // 5
   std::cout << v.capacity() << std::endl; // 8

   // Can assign size of vector upfront. Second line
   // show second argument meaning assign all values
   // in vector of size 10 to -2.
   std::vector<int> v2(10);
   std::vector<int> v3(10, -2);

   // We can also sort vectors by using inbuilt sort and
   // giving the beginning and end iterators, as we would have
   // to do for arrays.
   std::sort(v.begin(), v.end());

   return 0;
}
