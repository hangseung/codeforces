#include <stdio.h>
#include <algorithm>

using namespace std;
int a[100010];
int main(void) {
    int n;
    int max = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    
    int ans = 17, x = -1;
    for (int i = 0; i < 16; i++) {
        int max = 0;
        for (int j = 0; j < n; j++) {
            max = (max > (i ^ a[j])) ? max : (i ^ a[j]);
        }
        printf("x : %d, ")
    }
    printf("%d %d", ans, x);
    return 0;
}