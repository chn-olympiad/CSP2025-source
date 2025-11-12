#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 505, mod = 998244353;
int n, m, a[N], p[N], sum[N], ans, J[N];
char s[N];
bool vis[N], flag = true;

void dfs(int t) {
	if (t == n + 1) {
		int c1 = 0, c2 = 0;
//		for (int i = 1; i <= n; i++)
//			cout << p[i] << " ";
//		cout << endl;
		for (int i = 1; i <= n; i++) {
//			cout << "i:" << i << " p:" << p[i] << " a:" << a[i] << " s:" << s[i] << " sum:" << sum[i - 1] << " c2:" << c2 << " " <<
//			endl;
			if (sum[i - 1] + c2 < a[p[i]] && s[i] == '1') {
				c1++;
//				cout << "Y" << endl;
			}

			else if (sum[i - 1] + c2 >= a[p[i]] && s[i] == '1' ) {
				c2++;
//				cout << "N" << endl;
			}

		}
		if (c1 >= m)
			ans++;
		return;
	}
	for (int i = 1; i <= n; i++) {
		if (vis[i])
			continue;
		p[t] = i;
		vis[i] = true;
		dfs(t + 1);
		vis[i] = false;
	}
}

signed main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> n >> m >> (s + 1);
	J[0] = 1;
	for (int i = 1; i <= n; i++) {
		sum[i] = sum[i - 1];
		J[i] = J[i - 1] * i % mod;
		if (s[i] == '0')
			sum[i]++, flag = false;
//		cout << sum[i] << " ";
	}
	if (flag) {
		cout << J[n];
		return 0;
	}
//	cout << endl;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	dfs(1);
	cout << ans;
	return 0;
}
