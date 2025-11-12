#include <bits/stdc++.h>
#define LL long long
#define ull unsigned long long
#define uint unsigned int
using namespace std;

namespace EMPLOY {

const int N = 20;
const ull MOD = 998244353;
int n, m, C[N], S[N]; ull F[1 << N][N];

void main() {
    cin >> n >> m; 
    if (n > 18 && m == n) {
        char c; 
        for (int i = 1; i <= n; i ++) {
            cin >> c; if (c == '0') { cout << "0\n"; return ; }
        }
        for (int i = 1, x; i <= n; i ++) {
            cin >> x; if (x == 0) { cout << "0\n"; return ; }
        }
        ull Ans = 1; for (int i = 1; i <= n; i ++) Ans = Ans * i % MOD;
        cout << Ans << "\n"; return ;
    }
    char c;
    for (int i = 1; i <= n; i ++) cin >> c, S[i] = c - '0';
    for (int i = 1; i <= n; i ++) cin >> C[i];
    F[0][0] = 1;
    for (int s = 0; s < (1 << n); s ++) for (int j = 0; j < n; j ++) {
        int p = __builtin_popcount(s) + 1;
        for (int t = 0; t < n; t ++) if (!((s >> t) & 1)) {
            (F[s | (1 << t)][j + (C[t + 1] <= j || !S[p])] += F[s][j]) %= MOD;
        }
    }
    ull Ans = 0;
    for (int i = 0; i <= n - m; i ++) Ans += F[(1 << n) - 1][i];
    cout << Ans % MOD << "\n";
    return ;
}

}

int main() {
	freopen("employ.in", "r", stdin); freopen("employ.out", "w", stdout);
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	EMPLOY::main();
	return 0;
}