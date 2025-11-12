#include <bits/stdc++.h>
using namespace std;

#define For(i,x,y,...) for(int i=(x),##__VA_ARGS__;i<=(y);++i)
#define foR(i,x,y,...) for(int i=(x),##__VA_ARGS__;i>=(y);--i)
#define Rep(i,x,y,...) for(int i=(x),##__VA_ARGS__;i<(y);++i)
typedef long long ll;
#define fi first
#define se second
#define me(s,x) memset(s,x,sizeof s)
#define pb emplace_back
const int N = 505;
const int mod = 998244353;
int n, m, ct;
ll ans = 0;
int a[N], c[N], sz[N], bx[N], cur[N];
ll fac[N];
char s[N];

void MAIN() {
	cin >> n >> m;
	For(i, 1, n) a[i] = i;
	fac[1] = 1;
	For(i, 2, n) {
		fac[i] = fac[i - 1] * i % mod;
	}
	For(i, 1, n) cin >> s[i], sz[i] = sz[i - 1] + s[i] == '0';
	For(i, 1, n) cin >> c[i], ct += c[i] == 0, bx[c[i]]++;
	cur[0] = ct;
	For(i, 1, n) cur[i] = cur[i - 1] + bx[i];
	if (m == n) {
		For(i, 1, n) {
			if (s[i] == '0') {
				cout << 0 << endl;
				return;
			}
		}
		For(i, 1, n) {
			if (c[i] == 0) {
				cout << 0 << endl;
				return;
			}
		}
		ans = 1;
		For(i, 1, n) {
			(ans *= i) %= mod;
		}
		cout << ans << endl;
		return;
	}
//	if (m == 1) {
//		For(i, 1, n) {
//			if (c[i]) {
//				For(j, 0, c[i]) {
//					if (s[j + 1] == '0')
//						continue;
//					ll res = 1;
//					For(k,1,j-1){
//						if(s[i]=='0') res*=
//					}
//					(res *= fac[n - j - 1]) %= mod;
//					(ans += res) %= mod;
//				}
//			}
//		}
//		cout << ans << endl;
//	}
	do {
		int cnt = 0;
		bool fl = 0;
		For(i, 1, n) {
//			cout << a[i] << " ";
			if (c[a[i]] <= cnt)
				cnt++;
			else if (s[i] == '0')
				cnt++;
			if (i - cnt >= m) {
				fl = 1;
				ans++;
				ans %= mod;
			}
		}
		if (fl)
			continue;
		if (n - cnt >= m) {
			ans++;
			ans %= mod;
		}
//		cout << endl;
//		cout << cnt << endl;
	} while (next_permutation(a + 1, a + n + 1));
	cout << ans << endl;
}

signed main() {
	freopen("employ.in", "r", stdin), freopen("employ.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(nullptr);
	int t = 1;
	while (t--) {
		MAIN();
	}
	return 0;
}
/*12 5
111111111111
1 2 3 4 5 6 1 2 3 4 5 0 */
