#include <stdlib.h>
#include <stdio.h>


typedef struct Node {
    int value;
    struct Node *next;
} Node;


Node node_head = {0, NULL};

void AppendNode(Node *head, Node *node)
{
    // Checking weirdness
    if(node == NULL) return;

    node->next = NULL;

    
    Node *current = head;

    // Looking for the last Node
    while(current->next != NULL) {
        current = current->next;
    }

    current->next = node;
}


void CreateNode(int value)
{
    // Creating the node (obviously xd)
    Node* newNode = malloc(sizeof(Node));
    newNode->value = value;
    newNode->next = NULL;
    AppendNode(&node_head, newNode);
}

int main() {

    // Creating 10 nodes to see if it works correctly
    for(int i=0;i<10;i++){
        CreateNode(i*2);
    }


    // Looping the nodes, using node_head.next so it wouldn't print the head itself lol
    Node *temp = node_head.next;
    while (temp != NULL) {
        printf("Node data: %d \n",temp->value);
        temp = temp->next;
    }

    return 0;
}