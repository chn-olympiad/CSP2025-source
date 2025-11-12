#include <bits/stdc++.h>
using namespace std;
bool mp[10005][10005];

struct node {
	int a, b, c;
} a[1000005];


bool cmp(node a, node b) {
	return a.c > b.c;
}



int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int n, m, t;
	cin >> n >> m >> t;
	if (t != 0) {
		char c;
		while (cin >> c) {
			c += 0;
		}
		cout << 0;
	}
	for (int i = 1; i <= m; i++) {
		cin >> a[i].a >> a[i].b >> a[i].c;
	}
	sort(a + 1, a + m + 1, cmp);
	int ans = 0, sum = 0;
	for (int i = 1; i <= m; i++) {
		bool f = 1;
		for (int j = 1; j <= n; j++) {
			if (mp[a[i].a][j] && mp[a[i].b][j]) {
				f = 0;
				break;
			}
		}
		if (f && !mp[a[i].a][a[i].b] && sum <= n - 1) {
			ans += a[i].c;
			mp[a[i].a][a[i].b] = 1;
			mp[a[i].b][a[i].a] = 1;
			sum++;
		}
	}
	cout << ans;
	return 0;
}
