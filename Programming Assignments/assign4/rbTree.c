#include <stdio.h>
#include <malloc.h>

struct node {
    int data;
    struct node *parent;
    struct node *lchild;
    struct node *rchild;
    char color;
};

void insert (int);
int blackHeight ();

struct node *tree;
int main() {
    int n1, n2, n3, i, j, k;
    tree = NULL;
    scanf("%d", &n1);
    int *in = (int *)malloc(n1* sizeof(int));
    for (i=0; i<n1; i++) {
        scanf("%d", (in+i));
        // printf("%d \n", *(in+i));
    }
    scanf("%d", &n2);
    int *del = (int *)malloc(n2* sizeof(int));
    for (i=0; i<n2; i++) {
        scanf("%d", (del+i));
    }
    scanf("%d", &n3);
    int *srch = (int *)malloc(n3* sizeof(int));
    for (i=0; i<n3; i++) {
        scanf("%d", (srch+i));
    }

    for (i=0; i<n1; i++) {
        insert(*(in+i));
    }
    printf("\n");

    return 0;
}

void insert (int data) {
    if (tree == NULL) {
        tree = (struct node*)malloc (sizeof (struct node));
        tree->color = 'b';
        tree->data = data;
        tree->parent = NULL;
        tree->lchild = NULL;
        tree->rchild = NULL;
        printf("%d ", blackHeight());
        return;
    }
    struct node *temp1; temp1 = tree;
    while (1) {
        if(data < temp1->data && temp1->lchild==NULL) {
            struct node *temp = (struct node*)malloc (sizeof (struct node));
            (temp1->color=='b')?(temp->color = 'r'):(temp->color = 'b');
            temp->data = data;
            temp->parent = temp1;
            temp->lchild = NULL;
            temp->rchild = NULL;
            temp1->lchild = temp;
            printf (" inserting left %d \n", data);
            break;
        } else if (data > temp1->data && temp1->rchild==NULL) {
            struct node *temp = (struct node*)malloc (sizeof (struct node));
            (temp1->color=='b')?(temp->color = 'r'):(temp->color = 'b');
            temp->data = data;
            temp->parent = temp1;
            temp->lchild = NULL;
            temp->rchild = NULL;
            temp1->rchild = temp;
            printf (" inserting right %d \n", data);
            break;
        } else if (data < temp1->data) {
            temp1 = temp1->lchild;
            printf (" Left %d %c \n", temp1->data, temp1->color);

        } else if (data > temp1->data) {
            
            temp1 = temp1->rchild;
            printf (" Right %d %c \n", temp1->data,  temp1->color);
        } else if (data == temp1->data) {
            break;
        }
    }
    tree = temp1;
    // free (temp1);
    printf("%d ", blackHeight());
}

int blackHeight () {
    int n=0;
    struct node *temp1 = tree;
    while (temp1!=NULL) {
        n = (temp1->color=='b')?n+1:n;
        temp1 = temp1->lchild;
    }
    free (temp1);
    return n;
}