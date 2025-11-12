#include <bits/stdc++.h>
#include <set>
#define NOI(x) freopen(x".in","r",stdin),freopen(x".out","w",stdout);
using namespace std;
int n, a[5001];
long long ans = 0, cnt1 = 0;
bool vis[5005];
const long long md = 998244353;
set<int>st;

void dfs(int x, int ln, int zd, int cnt) {
	if (x == ln + 1) {
		if (2 * zd < cnt) {
			ans = (ans + 1) % md;
//			cout << 2 * zd << ' ' << cnt << ' ' << ln << endl;
		}
		return;
	}
	for (int i = 1; i <= n; i++) {
		if (!vis[i]) {
			vis[i] = 1;
			dfs(x + 1, ln, max(zd, a[i]), cnt + a[i]);
			vis[i] = 0;
		}
	}
}


int main() {
	NOI("polygon");
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	if (n == 3) {
		if (a[1] + a[2] + a[3] > max({a[1], a[2], a[3]}) * 2) {
			cout << 1;
		} else
			cout << 0;
		return 0;
	}
//	for (int i = 1; i <= 15; i++)
//		cout << jc[i] << endl;
	for (int i = 3; i <= n; i++) {
		dfs(1, i, 0, 0);
	}
	cout << ans % md;
	return 0;
}
