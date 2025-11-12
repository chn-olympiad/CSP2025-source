#include <bits/stdc++.h>
using namespace std;

namespace myb {
	using ll = long long;
	const int N = 505;
	const int Mod = 998244353;
	
	int n, m;
	int a[N], t[N];
	char s[N];
	
	void ab() {
		cin >> n >> m;
		cin >> (s + 1);
		for (int i = 1;i <= n;i++) {
			cin >> a[i];
		}
//		int cnt = 0;
//		for (int i = 1;i <= n;i++) cnt += (s[i] == '1');
//		if (cnt == n) {
//			ll ans = 1;
//			for (int i = 1;i <= 200;i++) ans = ans * i % Mod, cout << (ans == 161088479) << "\n";
//			cout << ans;
//		}

		for (int i = 1;i <= n;i++) t[i] = i;
		
		int ans = 0;
		do {
			int cnt = 0;
			int res = 0;
			for (int i = 1;i <= n;i++) {
				int p = t[i];
				
				if (s[i] == '1' && cnt < a[p]) {
					res++;
				}
				else cnt++;
			}
			ans += (res >= m);
		} while (next_permutation(t + 1, t + n + 1));
		cout << ans;
		
		
	}
	
	int f[1 << 20][20];
	void main() {
		cin >> n >> m;
		cin >> (s + 1);
		for (int i = 0;i < n;i++) {
			cin >> a[i];
		}
		
		f[0][0] = 1;
		for (int i = 0;i < (1 << n);i++) {
			int cnt = __builtin_popcount(i);
			for (int j = 0;j <= n;j++) {
				for (int k = 0;k < n;k++) {
					if ((i >> k) & 1) continue;
					if (a[k] <= j || s[cnt + 1] == '0') {
						f[i | (1 << k)][j + 1] += f[i][j];
//						if (f[i][j])
//							cout << bitset<3>(i | (1 << k)) << " " << j + 1 << ' ' << f[i | (1 << k)][j + 1] << "\n";
					}
					else {
						f[i | (1 << k)][j] += f[i][j];
//						if (f[i][j])
//							cout << bitset<3>(i | (1 << k)) << " " << j + 1 << ' ' << f[i | (1 << k)][j] << "\n";;
					}
				}
			}
		}
		int ans = 0;
		for (int i = 0;i <= n - m;i++) {
			ans += f[(1 << n) - 1][i];
		}
		cout << ans;
	}
}

int main() {
	ios :: sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	myb::main();
	return 0;
}


