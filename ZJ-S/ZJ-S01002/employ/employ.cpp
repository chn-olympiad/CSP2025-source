#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int N = 19, mod = 998244353;
int n, m, c[N], f[N][1 << N];
char S[N];
void add(int &x, int y) {
	x += y;
	if (x >= mod) x -= mod;
}
int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> n >> m >> S;
	for (int i = 0; i < n; i++) cin >> c[i];
	f[0][0] = 1;
	for (int j = 0; j < n; j++) {
		for (int s = 0; s < (1 << n); s++) {
			int cnt = __builtin_popcount(s);
			for (int i = 0; i < n; i++) if (!(s >> i & 1)) {
				if (S[cnt] == '1' && cnt - j < c[i]) add(f[j + 1][s | (1 << i)], f[j][s]);
				else add(f[j][s | (1 << i)], f[j][s]);
			}
		}
	}
	
	int ans = 0;
	for (int i = m; i <= n; i++) ans = (ans + f[i][(1 << n) - 1]) % mod;
	cout << ans << '\n';
	return 0;
}


