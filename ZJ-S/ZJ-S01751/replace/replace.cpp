#include <bits/stdc++.h>
using namespace std;

#define L 5000024

typedef unsigned long long ull;
typedef pair<ull, ull> pu;

int n, m, cnt;
int acnt[L], sub[L][53], fail[L], fa[L];
char chof[L];
int Q[L], qs, qt;
map<pu, int> root;

char S[L], T[L];

int getsub(int x, char ch) {
    if (sub[x][ch]) return sub[x][ch];
    return (chof[++cnt] = ch, fa[cnt] = x, sub[x][ch] = cnt);
}

int getro(pu dst) {
    auto it = root.find(dst);
    if (it != root.end()) return it->second;
    return 0;
}

int getrw(pu dst) {
    auto it = root.find(dst);
    if (it != root.end()) return it->second;
    return root[dst] = ++cnt;
}

pu mkdiff(char* s, char* t) {
    ull a = -1, b = -1, dx = 0, dy = 0, tmp;
    for (int i = 0; s[i]; i++) {
        if (s[i] != t[i]) {
            if (!~a) a = 1, b = 1;
            tmp = (s[i] - 'a') * 26 + t[i] - 'a';
            dx += a * tmp;
            dy += b * tmp;
        }
        if (~a) a *= 101, b *= 301;
    }
    return {dx, dy};
}

void add(int x, char* s, char* t) {
    for (int i = 0; s[i]; i++) x = getsub(x, s[i] - 'a' + (s[i] != t[i] ? 27 : 1));
    acnt[x]++;
}

int main() {
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> S >> T;
        add(getrw(mkdiff(S, T)), S, T);
    }
    for (auto& p : root) Q[++qt] = p.second;
    while (qs != qt) {
        int i = Q[++qs];
        if (!chof[i]) {
            fail[i] = i;
            for (int j = 1; j <= 52; j++) if (sub[i][j]) Q[++qt] = sub[i][j];
            continue;
        }
        int f = fail[fa[i]];
        while (chof[f] && !sub[f][chof[i]]) f = fail[f];
        if (sub[f][chof[i]] && sub[f][chof[i]] != i) f = sub[f][chof[i]];
        fail[i] = f;
        acnt[i] += acnt[fail[i]];
        for (int j = 1; j <= 52; j++) if (sub[i][j]) Q[++qt] = sub[i][j];
    }
    while (m--) {
        cin >> S >> T;
        int ix = getro(mkdiff(S, T));
        if (!ix) {
            cout << "0\n";
            continue;
        }
        int ans = 0;
        for (int i = 0; S[i]; i++) {
            char ch = S[i] - 'a' + (S[i] != T[i] ? 27 : 1);
            while (chof[ix] && !sub[ix][ch]) ix = fail[ix];
            if (sub[ix][ch]) ix = sub[ix][ch];
            ans += acnt[ix];
        }
        cout << ans << '\n';
    }
    return 0;
}