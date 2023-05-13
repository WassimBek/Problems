/*You are given the head of a singly linked-list.
 The list can be represented as:

L0 → L1 → … → Ln - 1 → Ln
Reorder the list to be on the following form:

L0 → Ln → L1 → Ln - 1 → L2 → Ln - 2 → …
You may not modify the values in the list's nodes.
 Only nodes themselves may be changed.
*/


#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data ;
    struct node *next ;
}node ;

node *addData (node *head , int num) {
    node *newNode = (node *) malloc(sizeof(node)) ;
    newNode->data = num ;
    newNode->next = NULL ;
    if (head == NULL)
        head = newNode ;
    else {
        head->next = newNode ;
        head = newNode ;
    }
    return head ;
}

node *lnNode (node *frNode , int size) {
    if (size == 0)
        return frNode ;
    else 
        return lnNode(frNode->next,size-1) ;
}

node *reorderList (node *userNode , int t) {
    int saveT = (int) t/2 ;
    node *nodeFr = userNode->next ;
    while (saveT)
    {
        t = t - 2;
        userNode->next = lnNode(nodeFr,t);
        userNode = userNode->next ;
        userNode->next = nodeFr ;
        userNode = nodeFr ;
        nodeFr = nodeFr->next ;
        saveT-- ;
    }
    return userNode ;
}

void display (node *finalNode) {
    if (finalNode->next == NULL)
        printf("%d ",finalNode->data) ;
    else {
        printf("%d ",finalNode->data) ;
        display(finalNode->next) ;
    }
}

int main () {
    node *Head = NULL ;
    node *tmp = NULL ;
    int n ;
    do
    {
        printf("How Many Num in your list ? ") ;
        scanf("%d",&n) ;
    } while (n <= 0);
    for (size_t i = 1; i <= n; i++)
    {
        tmp = addData(tmp,i) ;
        if (i == 1)
            Head = tmp ;
    }
    tmp = reorderList(Head,n) ;
    tmp->next = NULL ;
    display(Head) ;
}