#include <bits/stdc++.h>

// #define IS_NOT_YUKICODER

#ifdef IS_NOT_YUKICODER
#include "reactive.hpp"
#else
#include "testlib.h"
#endif


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

void quit_reactive(bool ok, const std::string& msg = "") {
#ifdef IS_NOT_YUKICODER
    std::cout << (ok ? "AC" : "WA") << std::endl;
    reactive_end();
    exit(0);
#else
    quitf(ok ? _ok : _wa, msg.c_str());
#endif
}
// end templates



// begin constraints
const int MIN_N = 0;
const int MAX_N = 1000000000;
const int MIN_X = MIN_N;
const int MAX_X = MAX_N;
const int MAX_Q = 40;
// end constraints


void read_infile(int& n) {
#ifdef IS_NOT_YUKICODER
    std::cin >> n;
#else
    n = inf.readInt();
#endif
}

void read_query(char& c, int& x) {
#ifdef IS_NOT_YUKICODER
    std::string query = reactive_read();
    std::cerr << query << std::endl;
    if (sscanf(query.c_str(),"%c %d", &c, &x) != 2) {
        quit_reactive(false);
    }
    if (c != '?') {
        quit_reactive(false);
    }
    if (!(MIN_X <= x && x <= MAX_X)) {
        quit_reactive(false);
    }
#else
    std::string s = ouf.readWord();
    c = s[0];
    ensure(c == '?');
    x = ouf.readInt(MIN_X, MAX_X, "X");
    std::cerr << c << ' ' << x << std::endl;
#endif
}

void write_query(const std::string& s) {
#ifdef IS_NOT_YUKICODER
    reactive_write(s + '\n');
#else
    std::cout << s << std::endl;
#endif
}


int main(int argc, char** argv) {
#ifdef IS_NOT_YUKICODER
    reactive_start(argv[1]);
#else
    registerTestlibForYukicoder(argc, argv);
#endif

    int n;
    int q = 0;
    read_infile(n);
    while (true) {
        char c;
        int x;
        read_query(c, x);
        ++q;
        if(q > MAX_Q)
            quit_reactive(false, "query is over");
        if (x > n) {
            write_query("upper");
        }
        else if (x < n) {
            write_query("lower");
        }
        else {
            write_query("equal");
            quit_reactive(true, "ok");
        }
    }
}
