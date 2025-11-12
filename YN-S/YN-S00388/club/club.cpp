#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
int t, n, ans;
int d[5];
int a[100010][5];
int m1[100010];
int c[100010], mem[100010];

bool cmp(int u, int v) {
	return c[u] < c[v];
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> t;
	while (t--) {
		cin >> n;
		int k = n / 2;
		ans = 0;
		memset(d, 0, sizeof(d));
		memset(a, 0, sizeof(a));
		memset(m1, 0, sizeof(m1));
		memset(c, 0, sizeof(c));
		memset(mem, 0, sizeof(mem));
		for (int i = 1; i <= n; i++) {
			cin >> a[i][1] >> a[i][2] >> a[i][3];
			int x = 0, y = 0;
			for (int j = 1; j <= 3; j++) {
				if (a[i][j] >= x) {
					x = a[i][j];
					m1[i] = j;
				}
			}
			for (int j = 1; j <= 3; j++) {
				if (a[i][j] >= y && j != m1[i]) {
					y = a[i][j];
				}
			}
			d[m1[i]]++;
			c[i] = x - y;
			ans += x;
		}
		for (int i = 1; i <= 3; i++) {
			if (d[i] > k) {
				int p = 0;
				for (int j = 1; j <= n; j++) {
					if (m1[j] == i) {
						p++;
						mem[p] = j;
					}
				}
				sort(mem + 1, mem + p + 1, cmp);
				int gap = d[i] - k;
				for (int j = 1; j <= gap; j++) {
					ans -= c[mem[j]];
				}
			}
		}
		cout << ans << endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}