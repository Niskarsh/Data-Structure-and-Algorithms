#include <stdio.h>
#include <malloc.h>

typedef struct {
    int n;
    int *s;
} sum;

int power (int, int);

int main () {
    int N, i, j, p;
    scanf("%d", &N);
    sum sArray[N];
    for(i =0; i<N; i++) {
        scanf("%d", &(sArray[i].n));
        p = power(2, sArray[i].n);
        sArray[i].s = (int*)malloc(p * sizeof(int));
        for (j=0; j<p; j++) {
            scanf("%d", ((sArray[i].s)+j));
        }
    }

    // for(i =0; i<N; i++) {
    //     for (j=0; j<power(2, sArray[i].n); j++) {
    //         printf("%d\n", *((sArray[i].s)+j));
    //     }
    // }
    return 0;
}

int power (int b, int exp) {
    int p=1;
    for(int i=0;i<exp;i++) {
        p*=b;
    }
    return p;
}