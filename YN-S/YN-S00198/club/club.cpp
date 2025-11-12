#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n;
ll a[100000][3];
bool flag[100000][3];
ll num[3];
int ans = 0, maxn = 0;

void d(int k) {
	if (k >= n) {
		maxn = max(ans, maxn);
		return ;
	}
	for (int i = 0; i < 3; i++) {
		if (num[i] < n / 2) {
			ans += a[k][i];
			num[i]++;
			flag[k][i] = true;
		} else
			continue;
		d(k + 1);
		if (flag[k][i]) {
			ans -= a[k][i];
			flag[k][i] = false;
			num[i]--;
		}
	}
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int t;
	cin >> t;
	while (t--) {
		ans = 0;
		maxn = 0;
		cin >> n;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < 3; j++)
				cin >> a[i][j];
		d(0);
		cout << maxn << endl;
	}
	return 0;
}