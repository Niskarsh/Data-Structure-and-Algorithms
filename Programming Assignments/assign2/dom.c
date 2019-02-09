#include <stdio.h>
#include <malloc.h>

int **point, *a, *b;

void mergesort (int, int);
void merge (int, int, int);

int main () {

    int n, i, j=0, k, maxY;
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
    
    maxY = point[b[n-1]][1];
    a[n-1]= 1;
    for(i=n-2;i>=0;i--) {
        if( point[b[i]][1]>maxY) {
            maxY = point[b[i]][1];
            a[i]=1;
        } else {
            a[i]= 0;
        }
    }
    for(i=0;i<n;i++) {
        if(a[i]==1){
            printf("%d %d\n", point[b[i]][0], point[b[i]][1]);
        }
    }

    free(b);
    free(a);
    free(point);
    
    return 0;
}

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
    // a = (int*) malloc(n*sizeof(int));
    while (c1<mid-m+1&&c2<n-mid) {
        if(point[m+c1][0]>point[mid+c2+1][0]) {
            b[k] = mid+c2+1;
            ++c2;
            ++k;
        } else {
            b[k] = m+c1;
            ++c1;
            ++k;
        }
    }

    if(c1<mid-m+1) {
        while(c1<mid-m+1) {
            b[k] = m+c1;
            ++c1;
            ++k;
        }
    }
    if(c2<n-mid) {
        while(c2<n-mid) {
            b[k] = mid+c2+1;
            ++c2;
            ++k;
        }
    }

    // for(int i=m;i<=n;i++) {
    //     *(a+i)=*(b+i);
    // }
}
