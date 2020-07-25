#include <stdio.h>

int main(void) {
    int t;
    scanf("%d", &t);
    while(t--) {
        int n; // <= 100,000
        scanf("%d", &n);
        int a = n / 2, b = n % 2;
        if (b == 1) {
            printf("7");
        }
        else {
            printf("1");
        }
        for (int i = 1; i < a; i++) {
            printf("1");
        }
        printf("\n");
    }
    return 0;
}