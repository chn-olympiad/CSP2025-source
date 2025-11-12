#include <bits/stdc++.h>
#define ull unsigned long long
using namespace std;
bool f1;
const int N = 2e5 + 5, M = 5e6 + 5, P = 20090723;
int n, q, len[N], id[N], ok[N];
string s1[N], s2[N];
bool f2;
struct node {
    ull key; int val;
};
struct Unordered_map {
    int fir[P], nxt[N], idx;
    node e[N];
    inline int& operator [] (ull key) {
        int u = key % P;
        for(int i = fir[u]; i; i = nxt[i]) if(e[i].key == key) {
            return e[i].val;
        }
        idx++, nxt[idx] = fir[u], fir[u] = idx, e[idx].key = key, e[idx].val = 0;
        return e[idx].val;
    }
    inline bool find(ull key) {
        int u = key % P;
        for(int i = fir[u]; i; i = nxt[i]) if(e[i].key == key) {
            return true;
        }
        return false;
    }
}mp;
int main() {
    printf("%.2lfMB\n", (&f2 - &f1) / 1024.0 / 1024.0);
    freopen("data.in", "r", stdin);
    freopen("code.out", "w", stdout);
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> n >> q;
    for(int i = 1; i <= n; i++) {
        cin >> s1[i] >> s2[i];
        len[i] = s1[i].size();
        id[i] = i;
    }
    sort(id + 1, id + n + 1, [&](int x, int y) {return len[x] < len[y];});
    for(int i = 1; i <= n; i++) ins(s1[id[i]], s2[id[i]], id[i]);
    return 0;
}