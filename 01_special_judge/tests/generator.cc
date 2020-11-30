#include <bits/stdc++.h>
#include "testlib.h"

// begin templates
void makecase(std::ostream&, int);
void setseed(int testcase_idx) {
    // これだとテストケースを予測されやすいので seed を加工するなどする必要があるかもしれない
    long long seed = testcase_idx;
    rnd.setSeed(seed);
}
void makecase_rime(const std::string& filename, int testcase_idx) {
    setseed(testcase_idx);
    std::ofstream ofs(filename);
    makecase(ofs, testcase_idx);
    ofs.close();
}
void makecase_yukicoder(const std::string& filename, int testcase_idx) {
    setseed(testcase_idx);
    makecase(std::cout, testcase_idx);
    std::cerr << filename << std::endl;
}
// end templates


// begin constraints
const long long MIN_N = 2;
const long long MAX_N = 1000000000000LL;
// end constraints

void makecase(std::ostream& os, int testcase_idx) {
    long long N = rnd.next(MIN_N, MAX_N);
    os << N << std::endl;
}


int main(int argc, char** argv) {
    registerGen(argc, argv, 1);
#ifdef IS_NOT_YUKICODER
    int case_num = 10;
    for (int t = 0; t < case_num; ++t) {
        makecase_rime(format("01_random_%02d_r.in", t + 1).c_str(), t);
    }
#else
    int t;
    std::cin >> t;
    // to 0-origin
    --t;
    makecase_yukicoder(format("01_random_%02d_y", t + 1).c_str(), t);
#endif
    return 0;
}
