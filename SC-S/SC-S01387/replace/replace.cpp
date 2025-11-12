#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int N = 2e5 + 5, M = 5e6 + 5, mod = 1e9 + 7, base = 131;

string s[2][N];
map<int, map<int, int>> mp;

// int tr[N * 40][26], idx = 0, cnt[N * 40];

// int new_node() {
//     ++idx;
//     cnt[idx] = 0;
//     memset(tr[idx], 0, sizeof tr[idx]);
//     return idx;
// }

// void insert(string s) {
//     int p = 0;
//     for(char x : s) {
//         int c = x - 'a';
//         if(!tr[p][c]) tr[p][c] = new_node();
//         p = tr[p][c];
//     }
//     cnt[p] ++;
// }

// int ask(string s) {
//     int p = 0;
//     for(char x : s) {
//         int c = x - 'a';
//         if(!tr[p][c]) return 0;
//         p = tr[p][c];
//     }
//     return cnt[p];
// }

int Base[M];

void init(int n) {
    Base[0] = 1;
    for(int i=1; i<=n; i++)
        Base[i] = 1LL * Base[i-1] * base % mod;
}

int Hs[2][M];

int main() {
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    init(N - 5);

    int n, q; cin >> n >> q;

    int cnt = 0;
    for(int i=1; i<=n; i++) {
        cin >> s[0][i] >> s[1][i];
        int H[2] = {};
        for(int j=0; j<2; j++) {
            for(char x : s[j][i])
                H[j] = (1LL * H[j] * base % mod + x) % mod;
        }
        if(H[0] == H[1]) cnt ++;
        mp[H[0]][H[1]] ++;
    }
    while(q --)  {
        string t[2]; cin >> t[0] >> t[1];
        if(t[0].size() != t[1].size()) continue;
        int m = t[0].size();
        t[0] = " " + t[0];
        t[1] = " " + t[1];

        int l = 0, r = m + 1;
        while(l < m && t[0][l+1] == t[1][l + 1]) l ++;
        while(r > 1 && t[0][r-1] == t[1][r - 1]) r --;

        for(int j=0; j<2; j++) {
            for(int i=1; i<=m; i++) {
                Hs[j][i] = (1LL * Hs[j][i-1] * base % mod + t[j][i]) % mod;
            }
        }

        int ans = 0;

        for(int i=1; i<=m; i++) {
            for(int j=i; j<=m; j++) {
                int H = (Hs[0][j] - 1LL * Hs[0][i - 1] * Base[j - i + 1] % mod + mod) % mod;
                for(auto x : mp[H]) {
                    int h = ((1LL * Hs[0][m] - 1LL * Hs[0][j] * Base[m - j] % mod + mod) % mod
                          + 1LL * x.first * Base[m - j] % mod + 1LL * Hs[0][i-1] * Base[m - i + 1] % mod) % mod;
                    if(h == Hs[1][m]) ans += x.second;
                }
            }
        }
        cout << ans << "\n";
    }
    return 0;
}