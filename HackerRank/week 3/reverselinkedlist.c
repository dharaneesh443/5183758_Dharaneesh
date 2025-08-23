SinglyLinkedListNode* reverse(SinglyLinkedListNode* llist) {
  SinglyLinkedListNode* prev = NULL;
    SinglyLinkedListNode* curr = llist;
    SinglyLinkedListNode* next = NULL;

    while (curr != NULL) {
        next = curr->next;    
        curr->next = prev;    
        prev = curr;         
        curr = next;          
    }
    return prev;  
}
