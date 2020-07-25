#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

long long int X;
long long int x;
    
char sieve[1000001];
vector<long long int> arr;

long long int max(long long int a, long long int b) {
    return (a > b) ? a : b;
}

long long int back(long long int a, int p) {
    if (p >= arr.size()) {
        return max(a, x / a);
    }

    return min(back(a, p + 1), back(a * arr[p], p + 1));
}

int main(void) {
    vector<int> primes;
    scanf("%lld", &X);
    x = X;

    primes.push_back(2);
    for (long long int i = 3; i * i <= X; i += 2) {
        if (sieve[i] == 0) {
            primes.push_back(i);
            for (long long int j = i; j * j <= X; j += i) {
                sieve[j] = 1;
            }
        }
    }

    for (int i = 0; i < primes.size(); i++) {
        long long int t = 1;
        while (X % primes[i] == 0) {
            t *= primes[i];
            X /= primes[i];
        }
        if (t != 1) {
            arr.push_back(t);
        }
    }

    long long int ans = back(1, 0);

    printf("%lld %lld", ans, x / ans);
    return 0;
}