#include <stdio.h>
#include <malloc.h>

struct ListNode {
    int i;
    struct ListNode *set;
    struct ListNode *next;
};

int main () {

    int n, m, i, j;
    scanf("%d", &n);
    struct ListNode *Elements = (struct ListNode*)malloc(n*sizeof(struct ListNode*));
    struct ListNode *Set = (struct ListNode*)malloc(n*sizeof(struct ListNode*));
    int *size = (int*)malloc(n*sizeof(int));
    for(i=0;i<n;i++) {
        struct ListNode *temp = (struct ListNode*)malloc(sizeof(struct ListNode*));
        temp->i = i;
        temp->next = NULL;
        temp->set = (Elements+i);
        Elements[i] = *temp;
        Set[i] = *temp;
        size[i] = 1;
    }

    // for(i=0;i<n;i++) {
    //     printf("%d \n", Elements[i].i);
    // }

    scanf("%d", &m);
    

    return 0;
}