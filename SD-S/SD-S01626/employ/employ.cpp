#include <bits/stdc++.h>

using namespace std;

const int N = 510, P = 998244353;

int n, m;
bool st[N];
int c[N];

namespace BF {
int f[1 << 18][18];		// Â¼È¡ÁË j ¸ö 
int mian() {
	f[0][0] = 1;
	for (int s = 1; s < 1 << n; ++ s ) {
		int cnt = __builtin_popcount(s);
		for (int j = 0; j <= cnt - 1; ++ j )
			for (int i = 0; i < n; ++ i )
				if (s >> i & 1) {
					f[s][j + (st[cnt] && cnt - 1 - j < c[i + 1])] += f[s ^ (1 << i)][j];
				}
	}
	
//	for (int s = 0; s < 1 << n; ++ s ) {
//		int cnt = __builtin_popcount(s);
//		for (int j = 0; j <= cnt; ++ j ) {
//			for (int i = 0; i < n; ++ i ) cout << (s >> i & 1);
//			cout << ' ' << j << " : " << f[s][j] << '\n';
//		}
//	}
	
	int res = 0;
	for (int i = m; i <= n; ++ i ) res += f[(1 << n) - 1][i];
	return res;
}
}

signed main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; ++ i ) {
		char c;
		cin >> c;
		st[i] = c - '0';
	}
	for (int i = 1; i <= n; ++ i ) {
		cin >> c[i];
	}
	cout << BF::mian();
	return 0;
}
