#include <bits/stdc++.h>
using namespace std;

long long n, ans = 0, maxn = 0, cnt = 0;
long long a[5010];
long long summ[5010];

void dfss(int x, int sum) {
	long long maxx = maxn;
	if (n - x < 3 - cnt) return ;
	if (summ[n] - summ[x] + sum <= maxn * 2) return ;
	if (x == n) {
		if (cnt >= 3 && sum > maxn * 2) {
			ans++, ans = ans % 998244353;
		}
		return ;
	}
	x++;
	dfss(x, sum);
	maxn = max(maxx, a[x]);
	cnt++;
	dfss(x, sum + a[x]);
	cnt--;
}

int main() {
	freopen("polygon.in", "r",stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		summ[i] = summ[i - 1] + a[i];
	}
	dfss(0, 0);
	cout << ans << endl;
	return 0;
}
