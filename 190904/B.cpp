#include <stdio.h>
#include <algorithm>

using namespace std;

int main(void) {
    int b, g, n;
    scanf("%d%d%d", &b, &g, &n);
    int i = max(n - g, 0);
    int j = max(n - b, 0);
    printf("%d", n + 1 - i - j);
    return 0;
}