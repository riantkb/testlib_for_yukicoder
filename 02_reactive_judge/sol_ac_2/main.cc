#include <bits/stdc++.h>


int main() {
    int l = -1, u = 1000000001;
    while (true) {
        int m = (l + u) / 2;
        std::cout << "? " << m << std::endl;
        std::string res;
        std::cin >> res;
        if (res == "upper") {
            u = m;
        }
        else if (res == "lower") {
            l = m;
        }
        else {
            return 0;
        }
    }
}
