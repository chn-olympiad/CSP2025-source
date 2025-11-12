#include <bits/stdc++.h>
using namespace std;
#define int long long
int n, t, p, cnt;
int visr[100005], vist[5], ans[5];
int flag1;

struct node {
	int num, z, ren;
} a[100005];

bool cmp(node x, node y) {
	return x.num < y.num;
}


signed main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> t;
	while (t--) {
		memset(a, 0, sizeof(a));
		memset(visr, 0, sizeof(visr));
		memset(vist, 0, sizeof(vist));
		memset(ans, 0, sizeof(ans));
		cnt = 0;
		cin >> n;
		if (n == 2) {
			int q1[5] = {0}, q2[5] = {0};
			cin >> q1[1] >> q1[2] >> q1[3];
			cin >> q2[1] >> q2[2] >> q2[3];
			int anss = 0, ans1 = 0;
			for (int i = 1; i <= 3; i++) {
				for (int j = i + 1; j <= 3; j++) {
					if (i == j) {
						continue;
					}
					ans1 = q1[i] + q2[j];
					anss = max(anss, ans1);
				}
			}
			cout << anss << "\n";
			continue;
		}
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= 3; j++) {
				cnt++;
				cin >> a[cnt].num;
				a[cnt].z = j;
				a[cnt].ren = i;
			}
		}
		sort(a + 1, a + 1 + 3 * n, cmp);
		p = n / 2;
		for (int i = 3 * n; i >= 1; i--) {
			if (a[i].num == 0) {
				break;
			}
			if (visr[a[i].ren] == 0 && vist[a[i].z] + 1 <= p) {
				vist[a[i].z]++;
				visr[a[i].ren] = 1;
				ans[a[i].z] += a[i].num;
			}
		}
		cout << ans[1] + ans[2] + ans[3] << "\n";
	}
	return 0;
}