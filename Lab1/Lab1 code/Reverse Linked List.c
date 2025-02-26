

/* Function to reverse a linked list */
struct ListNode* reverseList(struct ListNode* head) {
    struct ListNode *prev = NULL;
    struct ListNode *curr = head;
    
    while (curr != NULL) {
        // Temporarily store the next node
        struct ListNode *nextNode = curr->next;
        
        // Reverse the link
        curr->next = prev;
        
        // Move forward
        prev = curr;
        curr = nextNode;
    }
    
    // 'prev' will be the new head after the loop finishes
    return prev;
}

