#include <bits/stdc++.h>
#include "testlib.h"


std::ifstream source_ifs;
std::ofstream score_ofs;

#ifndef IS_NOT_YUKICODER
/*
 * ./a.out <input-file> <answer-file> <source-file> <score-file> (+ output from stdin)
 */
void registerTestlibForYukicoder(int argc, char* argv[]) {
    __testlib_ensuresPreconditions();

    testlibMode = _checker;
    __testlib_set_binary(stdin);

    if (argc > 1 && !strcmp("--help", argv[1]))
        __testlib_help();

    if (argc != 5) {
        quit(_fail, std::string("Program must be run with the following arguments: ") +
            std::string("<input-file> <answer-file> <source-file> <score-file> (+ output from stdin)"));
    }
    resultName = "";
    appesMode = false;

    inf.init(argv[1], _input);
    ans.init(argv[2], _answer);
    ouf.init(stdin, _output);

    source_ifs.open(argv[3], std::ios::in);
    if (source_ifs.fail() || !source_ifs.is_open())
        quit(_fail, std::string("Can not read the source-file '") + argv[3] + std::string("'"));

    score_ofs.open(argv[4], std::ios::out);
    if (score_ofs.fail() || !score_ofs.is_open())
        quit(_fail, std::string("Can not write to the score-file '") + argv[4] + std::string("'"));
}
#endif

template<typename T>
void output_score(T score) {
#ifdef IS_NOT_YUKICODER
    std::cout << "IMOJUDGE<<<" << score << ">>>" << std::endl;
#else
    score_ofs << score << std::endl;
#endif
}
// end template



bool is_prime(long long n) {
    if (n < 2) return false;
    for (long long i = 2; i * i <= n; ++i) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

int main(int argc, char** argv) {

#ifdef IS_NOT_YUKICODER
    // You have to edit here if you use the reactive or scoring judge.
    registerTestlibCmd(argc, argv);
#else
    registerTestlibForYukicoder(argc, argv);
#endif

    long long n = inf.readLong();
    long long p = ouf.readLong(2, n);
    if (!is_prime(p)) {
        quitf(_wa, "%lld is not prime", p);
    }
    if (!ouf.seekEof()) {
        quitf(_wa, "Participant output contains extra tokens");
    }

    int d = 1000000;
    long long score = (p + d - 1) / d;
    output_score(score);

    quitf(_ok, "ok");
    return 0;
}
