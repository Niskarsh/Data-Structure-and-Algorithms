#include <stdio.h>
#include <malloc.h>
#include <string.h>

typedef struct {
    char type;
    double num;
    char op;
}  NumOp;

struct ListNode {
    NumOp* record;
    struct ListNode* next;
};
void prefix_stack (char*, int);
void evaluate ();
NumOp* stack (int, double, char, struct ListNode**);
struct ListNode* CreateStack ();
int IsEmpty (struct ListNode*);
void Push (struct ListNode**, NumOp*);
NumOp* Top (struct ListNode*);
NumOp* Pop (struct ListNode**);
double pow(double, double);


struct ListNode *S, *A;
NumOp *not;


int main () {
    int i, j, cnt=0;
    char prefix[500], temp[500];
    scanf("%[^\n]s", prefix);
    
    S = CreateStack ();
    A = CreateStack ();

    for (i=0;i< strlen(prefix);i++) {
        if(prefix[i]!=32) {
            temp[cnt] = prefix[i];
            ++cnt;
        } else {
            cnt=0;
            prefix_stack(temp, strlen(temp));
        }
    }
    if(cnt!=0) {
        prefix_stack(temp, strlen(temp));
    }
    evaluate();
    return 0;
}

void prefix_stack (char *prefix, int len) {
    int i;
    double num=0, power=0;
    for(i=len-1; i>=0; i--) {
        if(!(*(prefix+i)>=48 && *(prefix+i)<=57)) {
            stack(2, 0, *(prefix+i), &S);
            return;
        } else {
            num = num + ((double)(*(prefix+i))-48) * pow(10.0, power);
            ++power;
        }
    }
    stack(1, num, '\0', &S);
}

void evaluate () {
    if((S==NULL)&&((A->next)==NULL)) {
        fflush(stdout);
        printf("%lf\n", A->record->num);
        fflush(stdout);
        return;
    }
    not= malloc(sizeof(NumOp*)); 
    not = stack(5, 0, '\0', &S);
    if(not->type=='n') {
        stack(1, not->num, '\0', &A);
            } else {
        NumOp *op1 = stack(5, 0, '\0', &A);
        NumOp *op2 = stack(5, 0, '\0', &A);
        switch (not->op) {
            case '+':
                stack(1, (op1->num + op2->num), '\0', &A);
                break;
            case '-':
                stack(1, (op1->num - op2->num), '\0', &A);
                break;
            case '*':
                stack(1, (op1->num * op2->num), '\0', &A);
                break;
            case '/':
                stack(1, (op1->num / op2->num), '\0', &A);
                break;
            case '^':
                stack(1, pow(op1->num , op2->num), '\0', &A);
                break;
        }
    }
    free(not);
    evaluate();



}

NumOp* stack(int inp, double num, char op, struct ListNode **S) {
    int q,i,j;
    
    
    NumOp *temp = malloc(sizeof(NumOp*)); 

    switch (inp)
    {
        case 1:
            (*temp).type = 'n';
            (*temp).num = num;
            (*temp).op = '\0';
            Push(S, temp);
            break;
        case 2:
            fflush(stdin);
            (*temp).type = 'o';
            (*temp).op = op;
            Push(S, temp);
            break;
        case 3:
            if(IsEmpty(*S)==1) {
                printf("error\n");
            } else {
                temp = Top (*S);
            }
            break;
        case 4:
            if(IsEmpty(*S)==1) {
                printf("True\n");
            } else {
                printf("False\n");
            }
            break;
        case 5:
            if(IsEmpty(*S)==1) {
                printf("error\n");
            } else {
                temp = Pop (S);
            }
            break;
        default:
            break;
    }
    return(temp);
    
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
    if((S)==(NULL)) {
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

double pow(double x, double y) {
    double pow=1;
    for (int i=0;i<y;i++) {
        pow = pow*x;
    }
    return pow;
}