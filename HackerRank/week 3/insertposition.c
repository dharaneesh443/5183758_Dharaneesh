SinglyLinkedListNode* insertNodeAtPosition(SinglyLinkedListNode* llist, int data, int position) {
 SinglyLinkedListNode* newNode = malloc(sizeof(SinglyLinkedListNode));
    newNode->data = data;
    
    if(position == 0) {
        newNode->next = llist;
        return newNode;
    }
    
    SinglyLinkedListNode* curr = llist;
    for(int i = 0; i < position - 1 && curr != NULL; i++) {
        curr = curr->next;
    }
    if(curr == NULL) return llist;
    
    newNode->next = curr->next;
    curr->next = newNode;
    return llist;
}
