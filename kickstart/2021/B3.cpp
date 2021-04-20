#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

const long long maxn = 1e5;
int is_prime[maxn];
vector<long long> primes;

void solve() {
    long long n; cin >> n;
    for (int i = 0; i < primes.size() - 1; i++) {
        if (primes[i] * primes[i+1] > n) {
            cout << primes[i-1] * primes[i] << endl;
            break;
        }
    }
}

int main() {
    // pre
    memset(is_prime, 1, sizeof(is_prime));
    is_prime[0] = is_prime[1] = 0;
    for (long long i = 2; i <= maxn; i++) {
        if (is_prime[i]) primes.push_back(i);
        for (long long j = i*i; j < maxn; j += i) {
            is_prime[j] = 0;
        }
    }
    int t; cin >> t;
    for (int i = 1; i <= t; i++) {
        cout << "Case #" << i << ": ";
        solve();
    }
}