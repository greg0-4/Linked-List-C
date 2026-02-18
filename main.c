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

void DeleteNode(Node *head, Node *node)
{

    // Checking weirdness 
    if(node == NULL) return;

    Node *current = head->next;
    Node *previous = head;

    // finding the target node
    while(current != NULL && current != node) 
    {
        previous = current;
        current = current->next;
    }

    // fixing the linked list so there will be no segfault
    previous->next = node->next;
    // removing the node
    free(node);
}

void LoopNodes()
{
    Node *temp = node_head.next;
    while (temp != NULL) {
        printf("Node data: %d \n",temp->value);
        Node *next = temp->next;
        if(temp->value == 10) {
            printf("Deleted the node that had the value of 10\n");
            DeleteNode(&node_head, temp);
        }
        temp = next;
    }
}

int main() {

    // Creating 10 nodes to see if it works correctly
    for(int i=0;i<10;i++){
        CreateNode(i*2);
    }


    // Looping the nodes, using node_head.next so it wouldn't print the head itself lol
    LoopNodes();
    printf("Doing the loop again...\n");
    LoopNodes();


    return 0;
}
