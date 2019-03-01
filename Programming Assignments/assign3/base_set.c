#include <stdio.h>
#include <malloc.h>

typedef struct {
    int n;
    int *base_set;
    int *s;
} sum;

int power (int, int);
void base_set (sum*, int);
void sum_set (sum*, int, int);

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
    return 0;
}

void base_set (sum* sArray, int p) {

    int dis=2, cnt=3;
    if (sArray[p].n==1) {
        *(sArray[p].base_set+0) = *(sArray[p].s+1);
    } else if (sArray[p].n==2) {
        *(sArray[p].base_set+0) = *(sArray[p].s+1);
        *(sArray[p].base_set+1) = *(sArray[p].s+2);
    } else {
        *(sArray[p].base_set+0) = *(sArray[p].s+1);
        *(sArray[p].base_set+1) = *(sArray[p].s+2);
        while (dis<sArray[p].n) {
            sum_set (sArray, p, dis);
            while (*(sArray[p].s+cnt)==-1) {
                cnt++;
            }
            *(sArray[p].base_set+dis) = *(sArray[p].s+cnt);
            ++dis;
        }

    }
}

void sum_set (sum* sArray, int p, int dis) {
    int i, j, pow, sum=0;
    pow = power (2, dis);
    for (i=0; i<pow; i++) {
        sum=0;
        if ( i & (1<<(dis-1))) {
            for (j=0; j<dis; j++) {
                if( i & (1<<j)) {
                    sum = sum + *(sArray[p].base_set+j);
                }
            }
            j=3;
            int powe = power(2, sArray[p].n);
            while (j<powe){
                if (*(sArray[p].s+j)==sum) {
                    *(sArray[p].s+j) = -1;
                    break;
                }
                ++j;
            }
        }
        

        
        
    }
}

int power (int b, int exp) {
    int p=1;
    for(int i=0;i<exp;i++) {
        p*=b;
    }
    return p;
}