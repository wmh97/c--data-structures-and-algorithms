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

    // if l1 contains n nodes and l2 contains m nodes,
    // in the worst case: T = O(n+m) (see the while loop below).
    // S = O(1) as we are not creating new nodes,  we are just
    // changing the pointers.
    ListNode* mergeTwoSortedLists(ListNode* l1, ListNode* l2) {
       
       // If one of the lists doesn't exist, the merged
       // list is just the one that does.
       if(l1==NULL) return l2;
       if(l2==NULL) return l1;
        
       ListNode* mergedHead = NULL;   /// head of the list to return
        
       // for the case of the HEAD:
       // use the smaller value of the first node
       // of the two lists and then move up a position in that lists nodes.
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

       // pointer to construct the new merged list - starting at head.
       // As we go through this will be pointing to the tail of the list.
       ListNode* mergedList = mergedHead; 
        
       // Looping over the lists until one of them reaches NULL.
       // Each iteration check the current node of l1 against the current node of l2.
       // Put the smaller of the two values at the tail of the merged list (mergedList->next),
       // move that list node position along one and then move the merged list position along one.
       //
       // Then do the same - check the current node of l1 vs current node of l2 and store
       // the smaller of the two in the merged list at the tail. Move position of the list thats value was stored
       // up one and move the merged list position up one.
       while(l1 && l2)
       {
            if(l1->val < l2->val)
            {
                mergedList->next = l1; // inseting at tail
                l1 = l1->next;
            }
            else
            {
                mergedList->next = l2;
                l2 = l2->next;
            }
            mergedList = mergedList->next;
       }

       // Eventually one list will reach NULL, in which case you just take the list that
       // not still null and put it at the tail of the merged list, thus completing the
       // list with all nodes linked properly.
       if(l1)
       {
            mergedList->next = l1;
       }
       else
       {
            mergedList->next = l2;
       }

       // return the head of the merged list.
       return mergedHead;
    }

    
    ListNode* mergeTwoSortedListsRecursive(ListNode* l1, ListNode* l2) {
        
        if(l1==NULL) return l2;
        if(l2==NULL) return l1;
        
        ListNode* mergedHead = NULL;
        if(l1->val < l2->val)
        {
            mergedHead = l1;

            // if l1 value is smaller, add to the tail the 'head' returned
            // by merging the lists l1 (starting from the next node along) and l2.
            mergedHead->next = mergeTwoSortedListsRecursive(l1->next, l2);
        }
        else
        {
            mergedHead = l2;

            // if l2 value is smaller, add to the tail the 'head' returned
            // by merging the lists l1 and l2 (starting from the next node along).
            mergedHead->next = mergeTwoSortedListsRecursive(l1, l2->next);
        }
        
        return mergedHead;
    }

};

int main()
{
  // Creating list1
  ListNode* head = new ListNode(1);
  ListNode* n2 = new ListNode(3);
  ListNode* n3 = new ListNode(5);
  ListNode* n4 = new ListNode(7);
  ListNode* n5 = new ListNode(9);
  head->next = n2;
  n2->next = n3;
  n3->next = n4;
  n4->next = n5;

  // Creating list2
  ListNode* head2 = new ListNode(2);
  ListNode* n6 = new ListNode(4);
  ListNode* n7 = new ListNode(6);
  ListNode* n8 = new ListNode(8);
  ListNode* n9 = new ListNode(10);
  head2->next = n6;
  n6->next = n7;
  n7->next = n8;
  n8->next = n9;

  Solution soln;

  // **** CALL EITHER OR OF THESE MERGE FUNCTIONS *****
  head = soln.mergeTwoSortedLists(head, head2); // successfully merges the above two lists (head and head2)
  //head = soln.mergeTwoSortedListsRecursive(head, head2);

  ListNode* tempHead = head;
  while(tempHead)
  {
    std::cout << tempHead->val << "-->";
    tempHead = tempHead->next;
  }
  std::cout << std::endl; // 1-->2-->3-->4-->5-->6-->7-->8-->9-->10-->

  return 0;
}