#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <string.h>


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

LinkedListNode* addNode(LinkedListNode* headNode, const char* newWord) {
    LinkedListNode* newNode = (LinkedListNode*)malloc(sizeof(LinkedListNode));
    if (newNode == NULL) {
        printf("ERROR: Unable to allocate memory\n");
        exit(1);
    }
    
    // Add given word into new node
    strncpy(newNode->word, newWord, MAX_WORD_LENGTH - 1);
    newNode->word[MAX_WORD_LENGTH - 1] = '\0';
    newNode->pNext = NULL;

    // Start of new list, list is already empty or the new word to be inserted
    // comes after the head node/we update the new node as the head.
    if (headNode == NULL || strcmp(newWord, headNode->word) < 0) {
        newNode->pNext = headNode;
        return newNode;
    }

    // Compare the word to be inserted to each node to determine the insertion / update point
    // within the list.
    LinkedListNode* currentNode = headNode;
    while (currentNode->pNext != NULL && strcmp(newWord, currentNode->pNext->word) >= 0) {
        currentNode = currentNode->pNext;
    }

    // Add the new node after the current node found above.
    newNode->pNext = currentNode->pNext;
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