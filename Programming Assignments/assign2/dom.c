#include <stdio.h>
#include <malloc.h>

int **point, *a, *b;

void dom(int, int);

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
        *(b+i) = 0;
    }
    for(i=0;i<n;i++) {
        printf("A is %d that is %d %d\n", *(a+i), point[*(a+i)][0], point[*(a+i)][1]);
    }
    
    return 0;
}

void dom (int i, int j) {

    
}