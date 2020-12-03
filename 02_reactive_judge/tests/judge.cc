#include <bits/stdc++.h>
#include "testlib.h"


// this judge code is not used in yukicoder

int main(int argc, char** argv) {
    registerTestlibCmd(argc, argv);
    std::string res = "";
    while (!ouf.seekEof()) {
        res = ouf.readWord();
        if (res == "WA") {
            quitf(_wa, "wrong answer");
        }
    }
    quitf(_ok, "ok");
    return 0;
}
