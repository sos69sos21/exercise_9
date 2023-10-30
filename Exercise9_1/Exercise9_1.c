#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_WORD_LENGTH 30

typedef struct _listNode {
    char word[MAX_WORD_LENGTH];
    struct _listNode* pNext;
} LinkedListNode;

LinkedListNode* addNode(LinkedListNode* head, const char* newWord);
void printList(LinkedListNode* head);
void freeList(LinkedListNode* head);

int main(int argc, char *argv[]) {
    FILE *inputFile = fopen(argv[1], "r");

    LinkedListNode* head = NULL;
    char word[MAX_WORD_LENGTH];

    // Read all words from given file and adds them to our linked list structure
    while (fscanf(inputFile, "%s", word) == 1) {
        head = addNode(head, word);
    }
    
    fclose(inputFile);
    printList(head);
    freeList(head);

    return 0;
}

//Adds a new node/word to the linked list
LinkedListNode* addNode(LinkedListNode* headNode, const char* newWord) {
    LinkedListNode* newNode = (LinkedListNode*)malloc(sizeof(LinkedListNode));
    if (newNode == NULL) {
        printf("ERROR: Unable to allocate memory\n");
        exit(1);
    }
    
    // Add given word into new node
    strncpy(newNode->word, newWord, MAX_WORD_LENGTH - 1);
    newNode->word[MAX_WORD_LENGTH - 1] = '\0';

    //Update the next pointer to NULL / end of list.
    newNode->pNext = NULL;

    // Start of new list. List is already empty.
    if (headNode == NULL) {
        return newNode;
    }

    // Iterate through the list in order to locate the last node in the list.
    LinkedListNode* currentNode = headNode;
    while (currentNode->pNext != NULL) {
        currentNode = currentNode->pNext;
    }

    // Add out new node / word to the end of the list.
    currentNode->pNext = newNode;

    return headNode;
}

// Prints all of the nodes in the list
void printList(LinkedListNode* head) {
    LinkedListNode* current = head;
    while (current != NULL) {
        printf("%s\n", current->word);
        current = current->pNext;
    }
}

// Frees up memory for the list
void freeList(LinkedListNode* head) {
    LinkedListNode* current = head;
    while (current != NULL) {
        LinkedListNode* next = current->pNext;
        free(current);
        current = next;
    }
}