#include <iostream>
#include <string>
#include <stack>

// https://leetcode.com/problems/valid-parentheses/
class Solution 
{
public:
    bool isValid(std::string bracketString) 
    {
        std::stack<char> s;
        
        // looking at each character in the bracket string.
        for(int i=0; i<bracketString.size(); i++)
        {
            // If the character is an open bracket then push it to the top of the stack
            if(bracketString[i]=='(' || bracketString[i]=='{' || bracketString[i]=='[')
            {
                s.push(bracketString[i]);
            }
            else
            {    
                // ... otherwise return false if the stack is empty - ie we come across a non
                // opening bracket and we havent already pushed an opening bracket.
                //
                // This avoids runtime error in such cases.
                if(s.empty()) return false;

                // Check if the closing bracket we encounter matches the opening bracket at the
                // top of the stack. If it does then pop the opening bracket as it has now been closed.
                // Otherwise return false as it is a valid input.
                else if(bracketString[i]==')')
                {
                    if(s.top() == '(') s.pop();
                    else return false;
                }
                else if(bracketString[i]=='}')
                {
                    if(s.top() == '{') s.pop();
                    else return false;
                }
                else if(bracketString[i]==']')
                {
                    if(s.top() == '[') s.pop();
                    else return false;
                }   
            }
        }
        
        // if the stack is empty by the time we have finished then 
        // reutrn true as we have a valid string.
        if(s.empty()) return true;
        return false;
    }
};

int main()
{
    /*
        Time complexity is linear and space complexity S=O(1).
    */
    
    Solution soln;
    std::cout << soln.isValid("([{}])") << std::endl; // 1
    std::cout << soln.isValid("([{})") << std::endl; // 0

    return 0;
}