#include <bits/stdc++.h>
using namespace std;
int a[5005], g[5005];

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	int n;
	bool k = 1;
	cin >> n;
	int sum = 0, cnt = 0;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = 3; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			g[i] = j;
		}
		for (; k == 1;) {
			k = 1;
			for (int j = 1; j <= i; j++) {
				if (g[j] != n - i + j)
					k = 0;
			}
			sum = 0;
			int max = INT_MIN;
			for (int x = 1; x <= i; x++) {
				sum += a[g[x]];
				if (a[g[x]] >= max)
					max = a[g[x]];
			}
			if (sum > 2 * max) {
				cnt++;
			}
			cnt = cnt % 998244353;
			g[i]++;
			for (int x = i; x >= 1; x--) {
				if (g[x] > n - i + x) {
					g[x] = 0;
					g[x - 1]++;
				}
			}
			for (int x = 1; x <= i; x++)
				if (g[x] == 0)
					g[x] = g[x - 1] + 1;
			//for (int j = 1; j <= 5; i++)
			//	cout << g[j];
			cout << endl;

		}

	}
	cout << cnt;
//	for (int i = 1; i <= 5; i++)
//		cout << g[i] << endl;
	return 0;
}

