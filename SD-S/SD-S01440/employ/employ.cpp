//
//   D try 1 20
#include <bits/stdc++.h>
#define int long long
#define ll long long
#define ull unsigned long long
#define PII pair<int, int>
#define ls(u) (u <<< 1)
#define rs(u) (u << 1 | 1)
using namespace std;

int T = 1;
const int N = 509, MOD = 998244353;
int n, m;
string s;
int a[N], c[N];
int tot;
int fac[N];

signed main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);

	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> n >> m >> s;
	s = " " + s;
	for (int i = 1; i <= n; i ++) {
		cin >> c[i];
		a[i] = s[i] - '0';
		tot += a[i];
	} 
	fac[1] = 1;
	for (int i = 2; i < N; i ++) {
		fac[i] = (fac[i - 1] * i) % MOD;
	}
	if (m == n) {
		if (m != tot) {
			cout << 0 << '\n';
		}
		else {
			cout << fac[n] << '\n';
		}
		return 0;
	}
	if (m == 1) {
		if (tot == 0) {
			cout << 0 << '\n';
			return 0;
		}
		
	}

	return 0;
}

/*



*/

