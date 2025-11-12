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
const int mod = 998244353;
int T;
void solve() {
    int n, m;
    fin >> n >> m;
    string s;
    fin >> s;
    vector<int> c;
    for (int i = 0, x; i < n; ++i) {
        fin >> x;
        c.push_back(x);
    }
    long long ans = 1;
    for (int i = 1; i <= n; ++i) {
        ans = (ans * i) % mod;
    }
    fout << ans << "\n";
}
auto main() -> int {
    FILEIO;
    ios::sync_with_stdio(false);
    T = 1;
    while (T--) {
        solve();
    }
    return 0;
}
