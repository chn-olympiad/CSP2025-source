/*
author: WilliamFranklin
AFOed on 2025/11/1

我常常追忆过去，忘了。 

我该在哪里停留？我问我自己。 
*/
#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
#define mp(Tx, Ty) make_pair(Tx, Ty)
#define For(Ti, Ta, Tb) for(auto Ti = (Ta); Ti <= (Tb); Ti++)
#define Dec(Ti, Ta, Tb) for(auto Ti = (Ta); Ti >= (Tb); Ti--)
#define debug(...) fprintf(stderr, __VA_ARGS__)
#define range(Tx) begin(Tx),end(Tx)
const int N = 505, M = 20, mod = 998244353;
int n, m;
char s[N];
int c[N];
namespace Sub1 {
	int p[N];
	void work() {
		For(i, 1, n) p[i] = i;
		long long ans = 0;
		do {
			int cnt = 0;
			For(i, 1, n) {
				if (c[p[i]] <= cnt || s[i] == '0') {
					cnt++;
				}
			}
			if (n - cnt >= m) {
				ans++;
			}
		} while (next_permutation(p + 1, p + n + 1));
		cout << ans;
	}
}
namespace Sub2 {
	long long f[2][1 << M][M];
	void work() {
		memset(f, 0, sizeof(f));
		int flag = 0;
		f[0][0][0] = 1;
		For(i, 1, n) {
			For(j, 0, (1 << n) - 1) For(k, 0, n) f[flag ^ 1][j][k] = 0;
			For(j, 0, (1 << n) - 1) {
				For(k, 0, n) {
					if (!f[flag][j][k]) continue;
					For(l, 1, n) {
						if ((j >> l - 1) & 1) continue;
						int x = 0;
						if (k >= c[l] || s[i] == '0') x = 1;
						else x = 0;
						f[flag ^ 1][j | (1 << l - 1)][k + x] = (f[flag ^ 1][j | (1 << l - 1)][k + x] + f[flag][j][k]) % mod;
					}
				}
			}
			flag ^= 1;
		}
		long long sum = 0;
		For(i, 0, n - m) {
			sum = (sum + f[flag][(1 << n) - 1][i]) % mod;
		}
		cout << sum << '\n';
	}
}
int cnt[N];
int main() {
	assert(freopen("employ.in", "r", stdin));
	assert(freopen("employ.out", "w", stdout));
	cin.tie(nullptr)->sync_with_stdio(false);
	cin >> n >> m;
	cin >> s + 1;
	For(i, 1, n) cin >> c[i];
	if (n <= 18) {
		Sub2::work();
	} else {
		if (m == n) {
			bool f = 1;
			For(i, 1, n) {
				if (s[i] == '0') f = 0;
			}
			For(i, 1, n) {
				if (c[i] == 0) f = 0;
			}
			if (f) {
				long long ans = 1;
				For(i, 1, n) {
					ans = ans * i % mod;
				}
				cout << ans;
			} else cout << 0;
		} else if (m == 1) {
			For(i, 1, n) cnt[c[i]]++;
			For(i, 1, n) cnt[i] += cnt[i - 1];
			int cnt1 = 0;
			long long ans = 1;
			For(i, 1, n) {
				if (s[i] == '1') {
					ans = ans * max(0, cnt[i - 1] - cnt1) % mod;
					cnt1++;
				}
			}
			For(i, 1, n - cnt1) {
				ans = ans * i % mod;
			}
			long long sum = 1;
			For(i, 1, n) sum = sum * i % mod;
			cout << (sum - ans + mod) % mod << '\n';
		}
	}
	return 0;
} 
