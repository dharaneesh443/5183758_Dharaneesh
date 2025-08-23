 DoublyLinkedListNode* curr = llist;
    DoublyLinkedListNode* temp = NULL;

   
    while (curr != NULL) {
     
        temp = curr->prev;
        curr->prev = curr->next;
        curr->next = temp;
        
        curr = curr->prev;
    }
    
    if (temp != NULL)
        llist = temp->prev;
    return llist;