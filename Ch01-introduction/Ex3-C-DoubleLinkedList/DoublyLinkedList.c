// Doubly Linked List of heap allocated strings
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node{
    struct Node *next;
    struct Node *prev;
    char* value;
} Node;

Node *head = NULL;
Node *tail = NULL;

void insert(char *input) {
    Node *n = malloc(sizeof(Node));
    n->value = strdup(input);
    n->next = head;
    n->prev = NULL;
    if (head) {
        head->prev = n;
    }
    if (tail == NULL) {
        tail = n;
    }
    head = n;
}

Node *find(char *input) {
    Node *current = head;

    for (current; current!=NULL; current=current->next) {
        if (!strcmp(current->value, input))
            return current;
    }

    return NULL;
}

int delete(char *input) {
    Node *deleted = find(input);
    if(!deleted)
        return -1;
    
    if(deleted == head){
        if (deleted == tail) {
            head = NULL;
            tail = NULL;
        } else {
            head = deleted->next;
            deleted->next->prev = NULL;
        }
    } else if(deleted == tail) {
        deleted->prev->next = NULL;
        tail = deleted->prev;
    } else {
        deleted->prev->next = deleted->next;
        deleted->next->prev = deleted->prev;
    }
    
    free(deleted->value);
    free(deleted);
    return 0;
}

void printList(){
    Node *current = head;

    for (current; current!=NULL; current=current->next) {
        printf("%s, ", current->value);
    }

    printf("\n");
}


int main () {
    
    insert("Faiq");
    insert("Rohaan");
    insert("Hassan");
    Node* found = find("Hasssadan");
    if(found){
        printf("Yayy\n");
    }

    printList();

}