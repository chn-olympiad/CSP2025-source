#include <bits/stdc++.h>
using namespace std;
int n, k;
int a[50005];
int vis[50005][50005];
int index1 = 0;
int ans = 0;

struct none {
	int st;
	int en;
} d[500005];

bool cmp(none x, none y) {
	if (x.en == y.en)
		return x.st < y.st;
	else
		return x.en < y.en;
}

int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	for (int i = 1; i <= n; i++) {
		for (int j = i; j <= n; j++) {
			if (i == j)
				vis[i][j] = 0;
			else if (i == j - 1)
				vis[i][j] = a[i] ^ a[j];
			else
				vis[i][j] = vis[i][j - 1] ^ a[j];
			if (vis[i][j] == k) {
				index1++;
				d[index1].st = i;
				d[index1].en = j;
			}
		}
	}
	sort(d + 1, d + 1 + index1, cmp);
	int e = 0;
	index1 = 0;
	while (index1 <= n) {
		if (d[index1].st > e) {
			e = d[index1].en;
			ans++;
		}
	}
	cout << ans;
	return 0;
}
