#include<bits/stdc++.h>
#define int long long

using namespace std;

inline int read(){
	int s = 0, w = 1;
	char ch = getchar();
	for (; ch < '0' || ch > '9'; w *= (ch == '-') ? -1 : 1, ch = getchar());
	for (; ch >= '0' && ch <= '9'; s = s * 10 + (ch - '0'), ch = getchar());
	return s * w;
}

const int INF = 0x3f3f3f3f3f3f3f3f, N = 505, MOD = 998244353;

int n, m, k, c[N], f[1 << 18][19];
char s[N];

signed main(){
//	freopon("../../csps/down/employ/employ2.in", "r", stdin);
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	n = read(), m = read(), scanf("%s", s + 1);
	for (int i = 1; i <= n; i++) c[i] = read();
	f[0][0] = 1;
	for (int i = 0; i < (1 << n); i++){
		int cnt = 0;
		for (int j = 1; j <= n; j++){
			if ((i >> (j - 1)) & 1) cnt++;
		}
		for (int j = 0; j <= n; j++){
			if (!f[i][j]) continue;
			for (int k = 1; k <= n; k++){
				if ((i >> (k - 1)) & 1) continue;
				if (s[cnt + 1] == '0' || c[k] <= j) (f[i | (1 << (k - 1))][j + 1] += f[i][j]) %= MOD;
				else (f[i | (1 << (k - 1))][j] += f[i][j]) %= MOD;
			}
		}
	}
	int ans = 0;
	for (int i = 0; i <= n - m; i++) (ans += f[(1 << n) - 1][i]) %= MOD;
	cout << ans << endl;
	return 0;
}

