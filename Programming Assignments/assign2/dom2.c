#include <stdio.h>
#include <malloc.h>

int **point, *a, *b;
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
        if(i==0) {
            *a = 0;
        } else {
            j=0;
            while(point[i][0]>point[*(a+j)][0]&&j<i) {
                ++j;
            }
            for (k=i;k>=j;k--) {
                *(a+k) = *(a+k-1);
            }
            *(a+j) = i;
        }
    }
    maxY = point[a[n-1]][1];
    b[n-1]= 1;
    for(i=n-2;i>=0;i--) {
        if( point[a[i]][1]>maxY) {
            maxY = point[a[i]][1];
            b[i]=1;
        } else {
            b[i]= 0;
        }
    }
    for(i=0;i<n;i++) {
        if(b[i]==1){
            printf("%d %d\n", point[a[i]][0], point[a[i]][1]);
        }
    }

    free(b);
    free(a);
    free(point);
    return 0;
}