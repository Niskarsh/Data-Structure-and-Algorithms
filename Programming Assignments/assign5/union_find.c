#include <stdio.h>
#include <malloc.h>

struct ListNode {
    int i;
    int set;
    struct ListNode *next;
};

int find (int);

struct ListNode *Elements;
int *Set, *size;

int main () {

    int n, m, i, j, choice, inp1, inp2, f1, f2,a;
    scanf("%d", &n);
    Elements = (struct ListNode*)malloc((n+1)*sizeof(struct ListNode));
    Set = (int*)malloc(n*sizeof(int));
    size = (int*)malloc(n*sizeof(int));
    for(i=0;i<n;i++) {
        struct ListNode *temp = (struct ListNode*)malloc(sizeof(struct ListNode*));
        temp->i = i;
        temp->next = NULL;
        temp->set = i;
        Elements[i].next = temp;
        Set[i] = i;
        size[i] = 1;
    }
    scanf("%d", &m);
    for(i=0;i<m;i++) {
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                scanf("%d %d", &inp1, &inp2);
                struct ListNode *temp;
                f1 = find(inp1);
                f2 = find(inp2);
                if(f1==f2) {
                    printf("0\n");
                } else {
                    if(size[f1]>size[f2]) {
                        f1 = f1-f2;
                        f2 = f1-f2;
                        f1 = f1-f2;
                        f2 = f2+2*f1;
                    }
                    temp = (*(Elements+f1)).next;
                    while(temp->next!=NULL) {
                        Set[temp->i] = f2;
                        temp->set = f2;
                        temp = temp->next;
                    }
                    temp->set = f2;
                    temp->next = Elements[f2].next;
                    Elements[f2].next = Elements[f1].next;
                    Elements[f1].next = NULL;
                    size[f2] = size[f2]+size[f1];
                    size[f1] = 0;
                    Set[f1] = f2;
                    printf("1\n");
                }
                
                break;
            case 2:
                scanf("%d", &inp1);
                f1 = find(inp1);
                printf("%d\n", f1);
                break;
            case 3:

                scanf("%d %d", &inp1, &inp2);
                f1 = find(inp1);
                f2 = find(inp2);
                if(f1==f2) {
                    printf("1\n");
                } else {
                    printf("0\n");
                }
                break;
        }
    }

    return 0;
}

int find (int inp) {
    return Set[inp];
}