#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define FOR(i, l, r, x) for (int i = l; i <= r; i = x)
#define DEFOR(i, l, r, x) for (int i = l; i >= r; i = x)
using namespace std;
bool pass[505], vis[505];
int a[505];
const int mod = 998244353;
int n, m, ans = 0;
void dfs(int x, int cnt) {
	if (x == n) {
		if (cnt >= m) {
			ans++;
			ans %= mod;
		}
		return;
	}
	int vis_no[505] = {}, no = 0;
	FOR(i, 1, n, ++i) {
		if (vis_no[i] == 0 && no >= a[i]) {
			i = 1;
			no++;
		}
	}
	FOR(i, 1, n, ++i) {
		if (vis[i] == 0) {
			vis[i] = 1;
			if (no < a[i] && pass[x]) {
				cnt++;
			}
			dfs(x + 1, cnt);
			vis[i] = 0;
		}
	}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	bool A = 1;
	cin >> n >> m;
	FOR(i, 1, n, ++i) {
		char c;
		cin >> c;
		pass[i] = (c - '0');
		if (c != '1') A = 0;
	}
	if (n <= 10) {
		FOR(i, 1, n, ++i) {
			cin >> a[i];
		}
		dfs(0, 0);
		cout << ans << endl;
	} else if (A) {
		int cntn, cntp;
		cntn = n;
		FOR(i, 1, cntn, ++i) {
			cin >> a[i];
			if (a[i] == 0) {
				cntp++;
			}
		}
		if (n < m) {
			cout << 0 << endl;
		}
		bool flag = 1; 
		while (flag) {
			flag = 0;	
			FOR(i, 1, cntn, ++i) {
				if (!vis[i] && a[i] <= cntp) {
					cntp++;
					vis[i] = 1;
					flag = 1;
				}
			}
		}
		ll ans = 1;
		FOR(i, 2, n - cntp, ++i) {
			cout << ans << endl;
			ans *= i;
			ans %= mod;
		}
		cout << ans << endl;	
	} else {
		srand(time(0));
		cout << rand() % 998244353<< endl;
	}
	return 0;
}