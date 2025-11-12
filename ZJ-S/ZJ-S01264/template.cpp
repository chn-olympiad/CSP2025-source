#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
#define FILENAME []() -> string {string t = __FILE__; t.erase(t.find_last_of('.')); t.erase(0, t.find_last_of('/') + 1); return t;}()
#define INPUT (FILENAME + ".in").c_str()
#define OUTPUT (FILENAME + ".out").c_str()
#define FILEIO freopen(INPUT, "r", stdin), freopen(OUTPUT, "w", stdout)
#define fin cin
#define fout cout
int T;
void solve() {
}
auto main() -> int {
    FILEIO;
    int T;
    fin >> T;
    while (T--) {
        solve();
    }
    return 0;
}
