#include<iostream>

struct ListNode
{
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
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
            return slow->next;
        }
        std::cout << "Midpoint (Odd): " << slow->val << std::endl;
        return slow;
    }

    ListNode* reverseList(ListNode* head)
    {
      ListNode* prev = NULL;
      ListNode* current = head;

      while(current != NULL)
      {
        ListNode* next = current->next; 
        
        current->next = prev;
        prev = current;
        current = next;
      }

      return prev;
    }

    ListNode* deleteKthNodeFromEnd(ListNode* head, int k)
    {
        
        ListNode* pointerOne = head;
        ListNode* pointerTwo = head;

        while(k--)
        {
            pointerTwo = pointerTwo->next;
        }

        if(pointerTwo == NULL)
        {
            return pointerOne->next;
        }
        
        while(pointerTwo->next)
        {
            pointerOne = pointerOne->next;
            pointerTwo = pointerTwo->next;
        }
        ListNode* toDelete = pointerOne->next;
        pointerOne->next = pointerOne->next->next; 
        
        delete toDelete; 
        toDelete = nullptr; 

        return head;
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

  head = soln.deleteKthNodeFromEnd(head, 3); // deletes "3"
  ListNode* tempHead = head;
  while(tempHead)
  {
    std::cout << tempHead->val << "-->";
    tempHead = tempHead->next;
  }
  std::cout << std::endl; // 1-->2-->4-->5-->

  return 0;
}