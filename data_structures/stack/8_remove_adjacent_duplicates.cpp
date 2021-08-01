#include <iostream>
#include <string>

// https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string/
// https://www.hackerrank.com/challenges/reduced-string/problem
class Solution 
{
public:
    std::string removeDuplicates(std::string A) 
    {
         /*
            BELOW is the S=O(n) solution but we want
            to optimise this to get S=O(1).
            
            stack<char> s;
            for(int i=0;i<A.size();i++){
                if(s.empty() || A[i] != s.top()){
                    s.push(A[i]);
                } else {
                    s.pop();
                }
            }
            string ans="";
            while(!s.empty()){
                ans.push_back(s.top());
                s.pop();
            }
            
            reverse(ans.begin(),ans.end());
            if(ans.sizer()==0) return "Empty String";
            return ans;
        */
        
        // simulate inplace stack - overwriting the string as we 
        // look through the elements in it,
        // T=O(n), S=O(1) because we are not actually creating a stack.
        //
        // A stack is just something with a pointer to the
        // top element.
        int stptr = -1; // -1 to mean empty stack
        for(int i = 0; i < A.size(); i++)
        {
             if(stptr ==-1 || A[i] != A[stptr] )
             {
                 stptr++; // counter for pushing to stack, pushing is below.
                 
                 // setting the top of the stack to the current character.
                 // This will overwrite the string characters in place.
                 A[stptr] = A[i];
             } 
             else 
             {
                 stptr--; // if our char is same as top of stack, pop it.
             }
        }
        std::string ans = "";
        for(int i = 0; i <= stptr; i++)
        {
            ans.push_back(A[i]);
        }
        return ans; // unlike the other solution there is no need to reverse
    }
};


int main()
{
    Solution soln;

    std::cout << soln.removeDuplicates("aabbaca") << std::endl; // aca
    std::cout << soln.removeDuplicates("Mississippi") << std::endl; // M

    return 0;
}