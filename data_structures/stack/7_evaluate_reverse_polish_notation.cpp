#include <string>
#include <vector>
#include <stack>
#include <iostream>

/// https://leetcode.com/problems/evaluate-reverse-polish-notation/
class Solution 
{
public:

    /*
        T=O(n), S=O(n)
    */
    int evalRPN(std::vector<std::string>& tokens) 
    {
        std::stack<int> st;
        
        // looking at each string in our tokens vector.
        for(int i=0;i<tokens.size();i++)
        {
            
            // if the string is an operator:
            if(tokens[i]=="+" || tokens[i]=="-" || tokens[i]=="*" || tokens[i]=="/")
            {
                // store the top two elements of the stack
                // and pop them.
                int v1 = st.top();
                st.pop();
                int v2 = st.top();
                st.pop();
                
                // push the result of the two elements operated on
                // with the operator we are on:
                if(tokens[i]=="+")
                {
                    st.push(v2+v1);  // push result inside stack
                } 
                else if(tokens[i]=="-")
                {
                    st.push(v2-v1);  // push result inside stack
                }
                else if(tokens[i]=="*")
                {
                    st.push(v2*v1);  // push result inside stack
                }
                else if(tokens[i]=="/")
                {
                    st.push(v2/v1);  // push result inside stack
                }
            }
            
            else 
            {
                // operands

                // atoi(): Parses the C-string str interpreting its content 
                // as an integral number, which is returned as a value 
                // of type int.
                //
                // e.g. atoi("45") --> 45
                //
                // NOTE: atoi() takes input of a c style string not the 
                // C++ string class. That means we need to use the c_str()
                // method to convert our string into a c style string in order
                // to call the function.
                st.push(std::atoi(tokens[i].c_str()));
            }
        }
        
        // at then end we will have only one element inside the stack
        // and that will be our answer.
        return st.top();
    }       
            
};

int main()
{

    Solution soln;

    std::vector<std::string> rpn;
    rpn.push_back("4");
    rpn.push_back("13");
    rpn.push_back("5");
    rpn.push_back("/");
    rpn.push_back("+");

    std::cout << soln.evalRPN(rpn) << std::endl; // 6
    
    return 0;
}