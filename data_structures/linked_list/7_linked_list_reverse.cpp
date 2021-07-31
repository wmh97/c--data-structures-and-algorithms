#include<iostream>

// Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {} // lambda constructor - assings the val to x and the pointer to NULL
};

class Solution 
{
public:
    ListNode* middleNode(ListNode* head)
    {
        ListNode* slow = head;
        ListNode* fast = head->next;

        while(fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        if(fast != NULL)
        {  
            std::cout << "Midpoint (Even): " << slow->next->val << std::endl;
            return slow->next; // even
        }
        std::cout << "Midpoint (Odd): " << slow->val << std::endl;
        return slow;  // odd
    }

    // T = O(N), S=O(1)
    ListNode* reverseList(ListNode* head)
    {
      ListNode* prev = NULL;
      ListNode* current = head;

      while(current != NULL)
      {
        // store the next node along so we can iterate current over
        // the list.
        ListNode* next = current->next; 
        
        // Make the current node point to the one before it (to NULL for head)
        // Move the previous node up to be the current node
        // Move the current node up to be the next node.
        current->next = prev;
        prev = current;
        current = next;
      }

      return prev;
    }
};

int main()
{
  ListNode* head = new ListNode(1);
  ListNode* n2 = new ListNode(2);
  ListNode* n3 = new ListNode(3);
  ListNode* n4 = new ListNode(4);
  ListNode* n5 = new ListNode(5);
  head->next = n2;
  n2->next = n3;
  n3->next = n4;
  n4->next = n5;

  Solution soln;

  // REVERSE LIST
  head = soln.reverseList(head);

  // print the reversed list: 6-->5-->4-->3-->2-->1-->
  ListNode* tempHead = head;
  while(tempHead)
  {
    std::cout << tempHead->val << "-->";
    tempHead = tempHead->next;
  }
  std::cout << std::endl;

  delete head;
  delete n2;
  delete n3;
  delete n4;
  delete n5;
  head = NULL;
  n2 = NULL;
  n3 = NULL;
  n4 = NULL;
  n5 = NULL;

  return 0;
}