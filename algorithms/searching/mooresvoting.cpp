#include <iostream>
#include <vector>

// https://leetcode.com/problems/majority-element/
class Solution 
{
public:
    // making sure we are passing by reference so the vector
    // doesnt need to be copied in.
    int majorityElement(std::vector<int>& A)
    {
        int majority_candidate = A[0];
        int count = 1;
        
        // loop over all elements in the vector
        int n = A.size();
        for(int i = 1; i < n; i++)
        {
            // +1 when the current iteration is on an element
            // that is the same as our candidate.
            if(A[i] == majority_candidate)
            {
                count++;
            }

            // -1 when the current iteration element is any
            // other element than the candidate.
            else
            {
                count--;

                // If we have decremented the count to zero
                // that means we switch the candidate for majority
                // element to the element we are currently on.
                if(count == 0)
                {
                    majority_candidate = A[i];

                    // Once we have set the new candidate we can
                    // set its count to 1 as we start off from it.
                    count = 1;
                }
            }
        }
        // By the end of the loop above we will be at the end of
        // the array with either:
        // 1) count >0 and a majority element candidate
        // 2) count ==0 so we set the candidate and count++
        // Both should result in finding the correct majority candidate,
        // ASSUMING that it always exists.

        // in case the majority element does not exist, 
        // we double check by counting the ocurrences of the majority
        // element found above and making sure they are
        // greater than n/2.
        int count2 = 0;
        for(int i = 0; i < n; i++)
        {
            if(A[i] == majority_candidate)
            {
                count2++;
            }
        }
        if(count2 > n/2) return majority_candidate;
        else return -1; // return -1 for no majority element present.
    }
};

int main()
{
    Solution soln;

    std::vector<int> testVector;
    testVector.push_back(4);
    testVector.push_back(7);
    testVector.push_back(4);
    testVector.push_back(4);
    testVector.push_back(7);
    testVector.push_back(4);
    testVector.push_back(4);
    testVector.push_back(9);
    testVector.push_back(4);
    testVector.push_back(3);

    // T = O(n), S = O(1)
    int majority_element = soln.majorityElement(testVector);
    std::cout << "Majority Element: " << majority_element << std::endl; // --> 4

}