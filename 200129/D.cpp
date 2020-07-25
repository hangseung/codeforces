#include <stdio.h>
#include <vector>

using namespace std;

char sieve[100010];

long long int a, m;

vector<long long int> v;

long long int gcd(long long int a, long long int b) {
    if (a % b == 0) {
        return b;
    }
    else {
        return gcd(b, a % b);
    }
}

long long int back(int p, long long int mul, int c) {
    if (p >= v.size()) {
        printf("p: %d, mul: %lld, c: %d\n", p, mul, c);
        if (c == 0) {
            printf("0\n");
            return 0;
        }
        printf("%lld\n", ((a + m - 1) / mul - a / mul) * ((c % 2) ? 1 : -1));
        return ((a + m - 1) / mul - a / mul) * ((c % 2) ? 1 : -1); 
    }
    return back(p + 1, mul * v[p], c + 1) + back(p + 1, mul, c);
}

int main(void) {
    vector<int> primes;
    primes.push_back(2);
    for (int i = 3; i <= 100000; i += 2) {
        if (sieve[i] == 0) {
            primes.push_back(i);
            for (int j = i * 2; j <= 100000; j += i) {
                sieve[j] = 1;
            }
        }
    }
    int T;
    scanf("%d", &T);
    while (T--) {
        scanf("%lld %lld", &a, &m);
        long long int g = gcd(a, m);
        long long int b = m / g;
        v.resize(0);
        for (int i = 0; i < primes.size() && b > 1; i++) {
            if (b % primes[i] == 0) {
                v.push_back(primes[i]);
                b /= primes[i];
                while (b % primes[i] == 0) {
                    b /= primes[i];
                }
            }
        }
        if (b != 1) {
            v.push_back(b);
        }
        long long int ans = back(0, 1, 0);
        printf("%lld\n", ans);
    }
    return 0;
}