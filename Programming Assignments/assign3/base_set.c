#include <stdio.h>
#include <malloc.h>

typedef struct {
    int n;
    int *base_set;
    int *s;
} sum;

int power (int, int);
void base_set (sum*, int);
int nHighest (int);
int combination (int, int);
int factorial (int);

int main () {
    int N, i, j, p;
    scanf("%d", &N);
    sum sArray[N];
    for(i =0; i<N; i++) {
        scanf("%d", &(sArray[i].n));
        p = power(2, sArray[i].n);
        sArray[i].s = (int*)malloc(p * sizeof(int));
        sArray[i].base_set = (int*)malloc(sArray[i].n * sizeof(int));
        for (j=0; j<p; j++) {
            scanf("%d", ((sArray[i].s)+j));
        }
    }
    for (i=0; i<N; i++) {
        base_set(sArray, i);
    }
    for(i =0; i<N; i++) {
        for (j=0; j<sArray[i].n; j++) {
            printf("%d ", *(sArray[i].base_set+j));
        }
        printf("\n");
    }
    // for(i =0; i<N; i++) {
    //     for (j=0; j<power(2, sArray[i].n); j++) {
    //         printf("%d\n", *((sArray[i].s)+j));
    //     }
    // }
    return 0;
}

void base_set (sum* sArray, int p) {

    int i, j, k, len;
    len = power(2, sArray[p].n);
    if (sArray[p].n==1) {
        *(sArray[p].base_set+0) = *(sArray[p].s+1);
    } else if (sArray[p].n==2) {
        *(sArray[p].base_set+0) = *(sArray[p].s+1);
        *(sArray[p].base_set+1) = *(sArray[p].s+2);
    }
    for (i=0; i<len; i++) {


    }
}


int nHighest (int n) {
    
}

int combination (int n, int k) {
    return (factorial(n)/(factorial(k)*factorial(n-k)));
}

int factorial (int n) {
    int i, f=1;
    for (i=2;i<=n;i++) {
        f*=i;
    }
    return f;

}


int power (int b, int exp) {
    int p=1;
    for(int i=0;i<exp;i++) {
        p*=b;
    }
    return p;
}