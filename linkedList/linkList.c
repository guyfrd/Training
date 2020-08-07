#include<stdio.h> 
#include<stdlib.h>

#include"linkList.h" 



RET insertNode(linkList_t* head, int * data){
    
    node_t* it = head->first; 

    if (it == NULL){
        //FIRST node_t
        head->first = createNode(data); 
        if (head->first)
            return OK;
    }

    while (it->next != NULL)
    {
        it = it->next; 
    }
    it->next = createNode(data); 
    if(it->next == NULL){
        return FAIL; 
    }
    
    return OK; 
}



node_t* createNode(int* data){

    node_t* n = malloc(sizeof(node_t)); 
    if(n == NULL){
        printf("Error while malloc\n");
        return NULL;  
    }
    n->data = data; 
    return n; 
}


void printList(linkList_t* head){
    
    node_t* it = head->first; 

    while (it->next)
    {
        printf(" %d ->", *(it->data)); 
        it = it->next;
    }
    printf(" %d \n", *(it->data));
    
}

void freeLn(linkList_t* head)
{
    node_t* it = head->first; 
    node_t* next = it->next; 

    while (it)
    {
        next = it->next; 
        free(it); 
        it = next; 
    }
    
}

int* removeNode(linkList_t* head, int* data){

    node_t* prev = head->first; 
    int* ret; 
    node_t* it = head->first;

    //empty list
    if (it == NULL)
    {
        printf("empty list\n"); 
        return NULL;
    }
    //first node match
    if(*(it->data) == *data){
        head->first = it->next; 
        ret = it->data; 
        free(it); 
        return ret; 
    }
    
    it = it->next; 

    //1 -> 2 -> 3 -> 4
    while (it)
    {
        if(*(it->data) == *data){
            prev->next = it->next;
            ret = it->data; 
            free(it); 
            return  ret; 
        }
        prev = it; 
        it = it->next; 
    }
    return NULL;
}


RET remove_dup(linkList_t* l){
    //duplicate mean same node with same pointer to data
    node_t* prev = l->first; 
    node_t* curr = prev->next;
    node_t* runner = NULL; 
    node_t* tmp = NULL; 
    
    //printf("curr %d\n", *(curr->data));

    while (curr != NULL)
    {
        runner = l->first;
        
        while (runner != curr)
        {
           // printf("runner -> %d ", *(runner->data));
            if(*(runner->data) == *(curr->data))
            {
                tmp = curr->next;
                prev->next = tmp; 
                free(curr); 
                curr = tmp; 

            }
            runner = runner->next; 
        }
        prev = curr; 
        curr = curr->next; 

    }
     
    return OK; 
}


int nthRec(node_t* curr,node_t** nth_node, int n){
    int count; 

    if(curr == NULL){
        return 1; 
    }
    printf("curr:%d\n",*(curr->data));
    count = nthRec(curr->next ,nth_node, n); 

    printf("count: %d\n", count);
    if ((count) == n){
        *nth_node = curr; 
    }
    return count +1; 
}

RET nthFromEnd(linkList_t* ln, int n){
    
    node_t* ret = NULL; 
    printf("nthFromEnd n: %d\n", n);
    nthRec(ln->first, &ret, n);

    if(ret == NULL){
        printf("n: %d not exsit\n",n ); 
    } else {
        printf("n: %d data:%d\n",n , *(ret->data)); 
    }
    return OK;
}

RET removeMyself(node_t* n){


    printf("next data:%d\n",*(n->next->data));
    n->data = n->next->data; 
    printf("n->next data:%d\n",*(n->next->data));

    n->next = n->next->next; 

    free(n);

    return OK;
}


int plusLinkList(linkList_t* ln_1,linkList_t* ln_2){
    node_t* it_1 = ln_1->first; 
    node_t* it_2 = ln_2->first; 
    int carry = 0; 
    int tmp_calc = 0;
    int  res = 0; 
    int i = 1; 

    while (it_1 != NULL || it_2 != NULL)
    {
        if(NULL == it_1){
            tmp_calc +=  *(it_2->data) + carry; 
            printf("%d  i:%d  tmp_calc:%d\n",  *(it_2->data), i, tmp_calc); 
            it_2 = it_2->next; 
        } else if (NULL == it_2) {
            printf("%d + i:%d  tmp_calc:%d\n", *(it_1->data), i, tmp_calc); 
            tmp_calc += *(it_1->data)+ carry; 
            it_1 = it_1->next; 
        } else {
            tmp_calc += (*(it_1->data) + *(it_2->data))+ carry; 
            printf("%d + %d i:%d  tmp_calc:%d\n", *(it_1->data), *(it_2->data), i, tmp_calc); 
            it_1 = it_1->next; 
            it_2 = it_2->next;
        }
        carry = 0; 

        if(tmp_calc >= 10)
        {
            carry = 1; 
            tmp_calc = (tmp_calc % 10); 
        }
         res += tmp_calc * i; 
        printf("red:%d tmp_calc: %d\n", res, tmp_calc);
        tmp_calc = 0;
      
        i *= 10;  
    }
    return res;
}

node_t* circularLinkList(linkList_t* ln){
    node_t* n1 = ln->first; 
    node_t* n2 = ln->first; 

    //find the meeting point
    while (n2 != NULL)
    {
        n1= n1->next; 
        n2= n2->next->next;
        if(n1 == n2){
            break; 
        } 
    }
    
}

int main(int argc, char* argv[]){
    int data[] = {1,2,3,4,5,6,7}; 

    int data_dup[] = {1,1,2,3,4,2,5,6,7}; 
    RET ret; 
    
    linkList_t* ln;
    ln = malloc(sizeof(linkList_t)); 
    for (int i = 0; i < 7; i++){
        ret = insertNode(ln, &data[i]);
    }

    linkList_t* ln_dup; 
    ln_dup = malloc(sizeof(linkList_t)); 
    for (int i = 0; i < 9; i++){
        ret = insertNode(ln_dup, &data_dup[i]);
    }

    int data_nth[] = {1,2,3,4,5,6,7}; 
    linkList_t* ln_nth; 
    ln_nth = malloc(sizeof(linkList_t)); 
    for (int i = 0; i < 7; i++){
        ret = insertNode(ln_nth, &data_nth[i]);
    }   



    int data_add_1[] = {3, 1, 5, 6}; 
    int data_add_2[] = {5, 9, 2}; 
    linkList_t* ln_add_1; 
    linkList_t* ln_add_2; 
    ln_add_1 = malloc(sizeof(linkList_t)); 
    ln_add_2 = malloc(sizeof(linkList_t)); 
    for (int i = 0; i < 4; i++){
        ret = insertNode(ln_add_1, &data_add_1[i]);
    }   
    for (int i = 0; i < 3; i++){
        ret = insertNode(ln_add_2, &data_add_2[i]);
    }   

    printList(ln);
    removeNode(ln, &data[2]);
    printList(ln);
    removeNode(ln, &data[0]);
    printList(ln);
    printf("remove %d: \n",data[5] );
    removeNode(ln, &data[5]);
    printList(ln);
    printf("remove %d: \n",data[6] );
    removeNode(ln, &data[6]);
    printList(ln);

    printf("duplicate before\n");
    printList(ln_dup);
    remove_dup(ln_dup);
    printf("duplicate after\n");
    printList(ln_dup);
   
   nthFromEnd(ln_nth, 1);

   nthFromEnd(ln_nth, 7);
    
    printf("before remove %d\n" ,*(ln_nth->first->next->data));
    printList(ln_nth);
   
    removeMyself(ln_nth->first->next);

    printf("after remove\n");
    printList(ln_nth);
   
    printf("add two lists:\n");
    printList(ln_add_1);
    printList(ln_add_2);
    printf("res:%d\n", plusLinkList(ln_add_1, ln_add_2));

    freeLn(ln_nth);
    freeLn(ln); 
    freeLn(ln_dup); 

}