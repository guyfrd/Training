#ifndef LIMKLIST_H
#define LIMKLIST_H 

typedef enum{
    OK,
    FAIL
}RET;

typedef struct node 
{
    struct node * next; 
    int * data; 
}node_t;

typedef struct 
{
    node_t* first; 

}linkList_t;


node_t* createNode(int* data); 
RET insertNode(linkList_t* head, int* data); 
int * removeNode(linkList_t* head, int* data); 
void printList(linkList_t* head);
void freeLn(linkList_t* head);
#endif //LIMKLIST_H