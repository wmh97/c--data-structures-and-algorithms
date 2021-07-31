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
    // requires only one traversal of the list so this is better than the length/2
    // approach (although T=O(N) for both).
    //
    // Also note that slow and fast pointers are used in many other places too.
    ListNode* middleNode(ListNode* head)
    {
        
        // slow pointer starts at the first
        // element. Fast pointer starts at the second
        // element.
        ListNode* slow = head;
        ListNode* fast = head->next;
        
        // Keep iterating slow and fast pointers until the fast pointer reaches NULL,
        // or the end of the list, where its ->next is NULL.
        while(fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        // When we have reached one of the two above breaking conditions:
        //
        // If fast != NULL we know we are at the even case and can return
        // slow->next.
        //
        // We check this instead of fast->next==NULL because we want
        // to avoid runtime errors, as we know that fast will not be NULL
        // for the even case, and NULL for the odd case. This would mean
        // fast->next would give a runtime error for the odd case.
        if(fast != NULL)
        {  
            std::cout << "Midpoint (Even): " << slow->next->val << std::endl;
            return slow->next; // even
        }

        // Otherwise we know that we are at the odd case and can return slow;
        std::cout << "Midpoint (Odd): " << slow->val << std::endl;
        return slow;  // odd
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

  soln.middleNode(head); // 3 (Odd)

  delete head, n2, n3, n4, n5;
  head = new ListNode(1);
  n2 = new ListNode(2);
  n3 = new ListNode(3);
  n4 = new ListNode(4);
  n5 = new ListNode(5);
  ListNode* n6 = new ListNode(6);
  head->next = n2;
  n2->next = n3;
  n3->next = n4;
  n4->next = n5;
  n5->next = n6;

  soln.middleNode(head); // 4 (Even)

  // delete memory pointers are pointing to and then 
  // get rid of the hanigng pointers.
  delete head;
  delete n2;
  delete n3;
  delete n4;
  delete n5;
  delete n6;
  
  head = NULL;
  n2 = NULL;
  n3 = NULL;
  n4 = NULL;
  n5 = NULL;
  n6 = NULL;

  return 0;
}