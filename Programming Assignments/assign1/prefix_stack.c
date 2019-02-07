#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char type;
    double num;
    char op;
}  NumOp;

struct ListNode {
    NumOp* record;
    struct ListNode* next;
};

struct ListNode* CreateStack ();
int IsEmpty (struct ListNode*);
void Push (struct ListNode**, NumOp*);
NumOp* Top (struct ListNode*);
NumOp* Pop (struct ListNode**);


int main() {
    int q,i,j,inp;
    double num;
    char op[1];
    scanf("%d", &q);
    struct ListNode *S = CreateStack ();
    for(i=0; i<q; i++) {
        NumOp *temp = malloc(sizeof(NumOp*)); 

        scanf("%d", &inp);
        switch (inp)
        {
            case 1:
                scanf("%lf", &num);
                (*temp).type = 'n';
                (*temp).num = num;
                (*temp).op = NULL;
                Push(&S, temp);
                printf("$\n");
                break;
            case 2:
                fflush(stdin);
                scanf("%s", &op);
                (*temp).type = 'o';
                (*temp).op = op[0];
                Push(&S, temp);
                printf("$\n");
                break;
            case 3:
                if(IsEmpty(S)==1) {
                    printf("error\n");
                } else {
                    temp = Top (S);
                    (*temp).type=='o'? printf("%c\n" ,(*temp).op): printf("%lf\n" ,(*temp).num);
                }
                break;
            case 4:
                if(IsEmpty(S)==1) {
                    printf("True\n");
                } else {
                    printf("False\n");
                }
                break;
            case 5:
                if(IsEmpty(S)==1) {
                    printf("error\n");
                } else {
                    temp = Pop (&S);
                    (*temp).type=='o'? printf("%c\n" ,(*temp).op): printf("%lf\n" ,(*temp).num);
                }
                break;
            default:
                break;
        }
    }
    return 0;
}

struct ListNode* CreateNode () {
    struct ListNode *node = malloc(sizeof(struct ListNode*));
    return(node);
}

struct ListNode* CreateStack () {
    struct ListNode *head = NULL;
    return (head);
}

int IsEmpty (struct ListNode* S) {
    if((S)==NULL) {
        return (1);
    }
    return (0);
}

void Push (struct ListNode** S, NumOp* key) {
    struct ListNode *newNode = CreateNode ();
    struct ListNode **P;
    P=S;
    (*newNode).record = key;
    if (IsEmpty(*S)==1) {
        (*newNode).next=NULL;
    } else {
        (*newNode).next = *P;
    }
    *S = newNode;
}

NumOp* Top (struct ListNode* S) {
    return((*S).record);
}

NumOp* Pop (struct ListNode** S) {
    NumOp *temp = malloc(sizeof(NumOp*)); 
    temp = (**S).record;
    *S = (**S).next;
    return (temp);
}