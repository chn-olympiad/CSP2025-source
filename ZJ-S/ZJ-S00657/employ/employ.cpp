#include <bits/stdc++.h>
#define FL(i, a, b) for (int i = (a); i <= (b); ++i)
#define FR(i, a, b) for (int i = (a); i >= (b); --i)
using namespace std;
typedef long long ll;
const int N = 510;
const int MOD = 998244353;
int n, m, s[N], c[N];
int fac[N], cnt[N], f[N][N];
char str[N];
inline void AddTo(int &x, int y) {
	x = (x + y >= MOD? x + y - MOD : x + y);
}
inline void SubTo(int &x, int y) {
	x = (x < y? x + MOD - y : x - y);
}
int main() {
	/*
	3 2
	111
	1 1 2
	*/
//	freopen("employ2.in", "r", stdin);
//	freopen("employ.out", "w", stdout);
	scanf("%d %d", &n, &m);
	scanf("%s", str + 1);
	FL(i, 1, n) {
		scanf("%d", &c[i]);
		FL(j, 0, c[i] - 1) {
			++cnt[j];
		}
	}
	sort(c + 1, c + n + 1);
	fac[0] = 1;
	FL(i, 1, n) {
		fac[i] = (ll)fac[i - 1] * i % MOD;
	}
	int ans = 0;
	FL(s, m, n) {
		FL(i, 0, n) {
			fill(f[i], f[i] + n + 1, 0);
		}
		f[n][s] = 1;
		FR(i, n, 1) {
			FL(j, 0, i) {
				AddTo(f[i - 1][j], f[i][j]);
				if (str[i] == '1' && j && cnt[i - j] > (s - j)) {
					AddTo(f[i - 1][j - 1], (ll)f[i][j] * (cnt[i - j] - (s - j)) % MOD);
				}
			}
		}
		int t = f[0][0];
		t = (ll)t * fac[n - s] % MOD;
		if ((s - m) & 1) {
			SubTo(ans, (ll)t);
		} else {
			AddTo(ans, (ll)t);
		}
		cout << s << ' ' << t << ' ' << ans << endl;
	}
	printf("%d\n", ans);
	return 0;
}
