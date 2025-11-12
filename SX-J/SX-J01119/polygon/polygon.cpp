#include <bits/stdc++.h>
using namespace std;
int n, a[5005], gzh[5005], sum;

void dfs(int b, int k) {
	for (int i = b; i <= n; i++) {
		gzh[k] = a[i];
		if (k >= 3) {
			int num = 0, maxx = 0;
			for (int j = 1; j <= k; j++) {
				num += gzh[j];
				maxx = max(maxx, gzh[j]);
			}
			if (num > maxx * 2) {
				sum++;
				sum %= 998244353;
			}
		}
		dfs(i + 1, k + 1);
	}
	return ;
}

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	dfs(1, 1);
	cout << sum % 998244353;
	return 0;
}