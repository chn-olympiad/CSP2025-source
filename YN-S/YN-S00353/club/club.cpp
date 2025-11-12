#include <bits/stdc++.h>
using namespace std;
int t;

struct node {
	int r, l, z;
} a[100005];

bool cmp(node x, node y) {
	return x.z > y.z;
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> t;
	while (t--) {
		int n, num, f[100005], ans = 0;
		int ll[4];
		cin >> n;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= 3; j++) {
				a[num++].r = i;
				a[num].l = j;
				cin >> a[num].z;
			}
		}
		sort(a + 1, a + 1 + n, cmp);
		for (int i = 1; i <= n; i++) {
			if (f[a[i].r] == 0 && ll[a[i].l] < n / 2) {
				ans += a[i].z;
				f[a[i].r] = 1;
				ll[a[i].l]++;
			}
		}
		cout << ans << "\n";
	}
	return 0;
}