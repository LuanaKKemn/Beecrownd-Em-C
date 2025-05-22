#include <stdio.h>

int criseS(int n, int k);

int main(){
    int n, y;
    int vetor[100];
    int i = 0;

    while (1) {
        scanf("%d", &n);
        if (n == 0) break;
        y = 1;
        while (1) {
            if (criseS(n, y) != 11) y++;
            else break;
        }
        vetor[i] = y;
        i++;
    }

    for (int j = 0; j < i; j++) {
        printf("%d\n", vetor[j]);
    }

    return 0;
}

int criseS(int n, int k) {
    int r = 0;
    for (int i = 1; i < n; i++)
        r = (r + k) % i;

    return r;
}