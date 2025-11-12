#include <bits/stdc++.h>
using namespace std;
#define N 5010
#define mol 998244353
#define ll long long
ll a[N], b[N], sum, ssum, ans;
bool vis[N];

void dfs(ll x, ll m, ll sum, ll step) { //数的个数，最大值，和，步数
	if (step >= x) {
		if (sum > m)
			ssum++;
		return ;
	}
	for (int i = 1; i < m; i++) {
		if (vis[i] == 0) {
			vis[i] = 1;
			return dfs(x, m, sum + a[i], step + 1);
			vis[i] = 0;
		}
	}
}

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	int n, m;
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; i++)
		b[i] = b[i - 1] + a[i];
//	for (int i = 1; i <= n; i++)
//		cout << a[i] << " ";
//	cout << endl;
//	for (int i = 1; i <= n; i++)
//		cout << b[i] << " ";
//	cout << endl;
	if (n == 3) {
		if (a[1] + a[2] > a[3])
			cout << 1;
		else
			cout << 0;
		return 0;
	} else {
		for (int i = 3; i <= n; i++) {
			sum = 0;
			for (int j = 2; j < i; j++) {
				ssum = 0;
				dfs(j, i, 0, 0);
				ans += ssum;
				//cout << ssum << endl;
			}
		}
	}

	cout << sum;
	return 0;
}
