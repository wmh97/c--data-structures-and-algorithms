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

    ListNode* mergeTwoSortedLists(ListNode* l1, ListNode* l2) {

       if(l1==NULL) return l2;
       if(l2==NULL) return l1;
        
       ListNode* mergedHead = NULL;

       if(l1->val < l2->val)
       {
           mergedHead = l1;
           l1 = l1->next;
       }
       else
       {
           mergedHead = l2;
           l2 = l2->next;
       }

       ListNode* mergedList = mergedHead; 
       while(l1 && l2)
       {
            if(l1->val < l2->val)
            {
                mergedList->next = l1; 
                l1 = l1->next;
            }
            else
            {
                mergedList->next = l2;
                l2 = l2->next;
            }
            mergedList = mergedList->next;
       }

       if(l1)
       {
            mergedList->next = l1;
       }
       else
       {
            mergedList->next = l2;
       }

       return mergedHead;
    }


    ListNode* mergeTwoSortedListsRecursive(ListNode* l1, ListNode* l2) {
        
        if(l1==NULL) return l2;
        if(l2==NULL) return l1;
        
        ListNode* mergedHead = NULL;
        if(l1->val < l2->val)
        {
            mergedHead = l1;
            mergedHead->next = mergeTwoSortedListsRecursive(l1->next, l2);
        }
        else
        {
            mergedHead = l2;
            mergedHead->next = mergeTwoSortedListsRecursive(l1, l2->next);
        }
        
        return mergedHead;
    }

    // Since we are using merge sort, T = O(NlogN). Better to use iterative
    // functions rather than recursive where possible to get S=O(1).
    ListNode* mergeSortListRecursive(ListNode* head) 
    {
        // If list has no elements or only one element, it doesn't need sorting.
        if(head == NULL || head->next == NULL) return head; // base case
        
        // break list into two using fast and slow pointers
        ListNode* slow = head;
        ListNode* fast = head->next;
        while(fast && fast->next) // to make sure we are not doing NULL->next, as usual
        {
            slow = slow->next;
            fast = fast->next->next; // slow will be at midpoint when fast gets to the end
        }
        // In order to properly split up the linked list we should
        // have two halves that each point to NULL at the tail.
        //
        // The second half will do this automatically.
        // For the first half we make sure the element before our
        // midpoint points to NULL.
        ListNode* midpointHead = slow->next; 
        slow->next = NULL;
        
        // making recursive calls until we return head at the top condition when we have
        // split into one element lists...
        ListNode* firstHalfOfList = mergeSortListRecursive(head);
        ListNode* secondHalfOfList = mergeSortListRecursive(midpointHead);
        
        // ... then as those recursive calls finish executing they will be merged back
        // together up to the top level here - and we will have a fully sorted list.
        head = mergeTwoSortedLists(firstHalfOfList, secondHalfOfList);
        
        return head; // return head of our sorted LL.
    }

};

int main()
{
  
  // Making our list:
  // 10-->5-->1-->3-->9-->7-->2-->4-->8-->
  ListNode* head = new ListNode(10);
  ListNode* n2 = new ListNode(5);
  ListNode* n3 = new ListNode(1);
  ListNode* n4 = new ListNode(3);
  ListNode* n5 = new ListNode(9);
  ListNode* n6 = new ListNode(7);
  ListNode* n7 = new ListNode(2);
  ListNode* n8 = new ListNode(4);
  ListNode* n9 = new ListNode(8);
  head->next = n2;
  n2->next = n3;
  n3->next = n4;
  n4->next = n5;
  n5->next = n6;
  n6->next = n7;
  n7->next = n8;
  n8->next = n9;

  Solution soln;

  head = soln.mergeSortListRecursive(head);

  ListNode* tempHead = head;
  while(tempHead)
  {
    std::cout << tempHead->val << "-->";
    tempHead = tempHead->next;
  }
  std::cout << std::endl; // 1-->2-->3-->4-->5-->7-->8-->9-->10-->

  return 0;
}