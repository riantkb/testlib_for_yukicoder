#include <bits/stdc++.h>


int main() {
    int l = 0, u = 1000000002;
    while (true) {
        int m = (l + u) / 2;
        std::cout << "? " << m << std::endl;
        std::cerr << m << std::endl;
        std::string res;
        std::cin >> res;
        if (res == "upper") {
            u = m - 1;
        }
        else if (res == "lower") {
            l = m + 1;
        }
        else {
            return 0;
        }
    }
}
