#include <iostream>
#include <cstdio>
#include <string>
#include <ctime>
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
int n;
struct TrieNode {
    TrieNode* son[27] = {};
    int cnt = 0;
} root;
void solve() {
    string x, y;
    fin >> x >> y;
    int st = x.size(), ed = 0;
    for (int i = 0; i < x.size(); ++i) {
        if (x[i] != y[i]) {
            st = i;
            break;
        }
    }
    for (int i = x.size() - 1; i >= 0; --i) {
        if (x[i] != y[i]) {
            ed = i;
            break;
        }
    }
    // cerr << x << " " << y << "\n";
    // cerr << "st-ed: " << st << " " << ed << "\n";
    long long ans = 0;
    for (int i = 0; i <= st; ++i) {
        TrieNode* now = &root;
        for (int j = i; j < x.size(); ++j) {
            if (now->son[x[j] - 'a'] == nullptr) { break; }
            now = now->son[x[j] - 'a'];
            if (now->son[y[j] - 'a'] == nullptr) { break; }
            now = now->son[y[j] - 'a'];
            if (j >= ed) {
                // cerr << i << " " << j << " " << now->cnt << "\n";
                ans += now->cnt;
            }
        }
    }
    fout << ans << "\n";
}
auto main() -> int {
    FILEIO;
    ios::sync_with_stdio(false);
    fin >> n >> T;
    for (int i = 0; i < n; ++i) {
        string x, y;
        fin >> x >> y;
        // cerr << x << " " << y << "\n";
        TrieNode* now = &root;
        for (int j = 0; j < x.size(); ++j) {
            if (now->son[x[j] - 'a'] == nullptr) { now->son[x[j] - 'a'] = new TrieNode; }
            now = now->son[x[j] - 'a'];
            if (now->son[y[j] - 'a'] == nullptr) { now->son[y[j] - 'a'] = new TrieNode; }
            now = now->son[y[j] - 'a'];
        }
        ++now->cnt;
    }
    cerr << 1.0 * clock() / CLOCKS_PER_SEC << "\n";
    while (T--) {
        solve();
    }
    return 0;
}
