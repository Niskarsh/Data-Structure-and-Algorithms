#include <stdio.h>
#include <malloc.h>

long **point, *a, *b;

void mergesort (long, long);
void merge (long, long, long);

int main () {

    long n, i, j=0, k, maxY;
    scanf("%ld", &n);
    point = (long**) malloc(n*sizeof(long*));
    a = (long*) malloc(n*sizeof(long));
    b = (long*) malloc(n*sizeof(long));
    
    for(i=0;i<n;i++) {
        point[i] = (long*) malloc(2*sizeof(long));
        fflush(stdout);
        scanf("%ld %ld", (*(point+i)+0), (*(point+i)+1));
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
            printf("%ld %ld\n", point[b[i]][0], point[b[i]][1]);
        }
    }

    free(b);
    free(a);
    free(point);
    
    return 0;
}

void mergesort (long m, long n) {
    if(m==n) {
        return;
    }
    long mid = (m+n)/2;
    mergesort(m, mid);
    mergesort(mid+1, n);
    merge(m, n, mid);

}

void merge (long m, long n, long mid) {
    long c1=0,c2=0, k=m;
    while (c1<mid-m+1&&c2<n-mid) {
        if(point[a[m+c1]][0]>point[a[mid+c2+1]][0]) {
            b[k] = a[mid+c2+1];
            ++c2;
            ++k;
        } else {
            b[k] = a[m+c1];
            ++c1;
            ++k;
        }
    }

    if(c1<mid-m+1) {
        while(c1<mid-m+1) {
            b[k] = a[m+c1];
            ++c1;
            ++k;
        }
    }
    if(c2<n-mid) {
        while(c2<n-mid) {
            b[k] = a[mid+c2+1];
            ++c2;
            ++k;
        }
    }

    for(long i=m;i<=n;i++) {
        *(a+i)=*(b+i);
    }
}
