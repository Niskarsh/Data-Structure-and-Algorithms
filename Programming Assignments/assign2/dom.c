#include <stdio.h>
#include <malloc.h>

int **point, *a, *b;

int dominateCheck (int*, int*);
void mergesort (int, int);
void merge (int, int, int);

int main () {

    int n, i, j=0, k;
    scanf("%d", &n);
    point = (int**) malloc(n*sizeof(int*));
    a = (int*) malloc(n*sizeof(int));
    b = (int*) malloc(n*sizeof(int));
    
    for(i=0;i<n;i++) {
        point[i] = (int*) malloc(2*sizeof(int));
        fflush(stdout);
        scanf("%d %d", (*(point+i)+0), (*(point+i)+1));
        *(b+i) = i;
        *(a+i) = i;
    }

    mergesort(0, n-1);
    // dom(0, n-1);
    for(i=0;i<n;i++) {
        printf("A is %d that is %d %d\n", *(b+i), point[*(b+i)][0], point[*(b+i)][1]);
    }
    
    return 0;
}

// void dom (int i, int j) {

//     int pivot;

//     pivot = partition(i,j);
//     dom(i, pivot);
//     dom(pivot+1, j);
    
// }

void mergesort (int m, int n) {
    if(m==n) {
        return;
    }
    int mid = (m+n)/2;
    mergesort(m, mid);
    mergesort(mid+1, n);
    merge(m, n, mid);

}

void merge (int m, int n, int mid) {
    int c1=0,c2=0, k=m;
    printf("In merge functions m %d n %d mid %d \n", m, n, mid);
    while (c1<mid-m+1&&c2<n-mid) {
        if(point[a[m+c1]][0]>point[a[mid+c2+1]][0]) {
            printf("In merge %d %d c1 is %d c2 is %d\n", point[a[m+c1]][0], point[a[mid+c2+1]][0], c1, c2);
            b[k] = a[mid+c2+1];
            ++c2;
            ++k;
        } else {
            printf("In merge else %d %d c1 is %d c2 is %d\n", point[a[m+c1]][0], point[a[mid+c2+1]][0], c1, c2);
            b[k] = a[m+c1];
            ++c1;
            ++k;
        }
    }

    if(c1<mid-m+1) {
        while(c1<mid-m+1) {
            printf("In loop for c1 c1 is %d\n", c1);
            b[k] = a[m+c1];
            ++c1;
            ++k;
        }
    }
    if(c2<n-mid) {
        while(c2<n-mid) {
            printf("In loop for c2 c2 is %d\n", c2);
            b[k] = a[mid+c2+1];
            ++c2;
            ++k;
        }
    }

    for(int i=m;i<=n;i++) {
        *(a+i)=*(b+i);
    }
}

int dominateCheck (int *p, int *q) {
    if(p[0]==q[0]&&p[1]==q[1]) {
        return 0;
    } else if (p[0]<=q[0]&&p[1]<=q[1]) {
        return 2;
    } else if (p[0]>=q[0]&&p[1]>=q[1]) {
        return 1;
    } else {
        return 3;
    }
}