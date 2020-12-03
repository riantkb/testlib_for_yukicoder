#include <bits/stdc++.h>


bool is_prime(long long n) {
    if (n < 2) return false;
    for (long long i = 2; i * i <= n; ++i) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    long long n;
    std::cin >> n;
    while (true) {
        if (is_prime(n)) {
            std::cout << n << '\n';
            return 0;
        }
        --n;
    }
    return 0;
}
