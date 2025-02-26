/* Function to remove elements from a linked list */
struct ListNode* removeElements(struct ListNode* head, int val) {
    // Create a dummy node that points to head
    struct ListNode dummy;
    dummy.next = head;
    
    // Use a pointer to traverse the list
    struct ListNode *current = &dummy;
    
    while (current->next != NULL) {
        if (current->next->val == val) {
            // Remove the node
            struct ListNode *temp = current->next;
            current->next = current->next->next;
            free(temp);
        } else {
            current = current->next;
        }
    }
    
    return dummy.next;  // Return new head 
