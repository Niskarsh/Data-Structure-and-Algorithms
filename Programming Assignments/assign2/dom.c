#include <stdio.h>
#include <malloc.h>

int main () {

    int n, i, j, **point;
    scanf("%d", &n);
    point = (int**) malloc(n*sizeof(int*));
    
    for(i=0;i<n;i++) {
        point[i] = (int*) malloc(2*sizeof(int));
        fflush(stdout);
        scanf("%d %d", (*(point+i)+0), (*(point+i)+1));
    }
    
    return 0;
}