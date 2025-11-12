#include <bits/stdc++.h>
using namespace std;
long long ans, t, n, s1, s2, s3;

struct node {
	int u, v, w;
} a[100005];

bool cmp1(node a, node b) {
	return a.u > b.u;
}

bool cmp2(node a, node b) {
	return a.v > b.v;
}

bool cmp3(node a, node b) {
	return a.w > b.w;
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> t;
	while (t--) {
		cin >> n;
		for (int i = 1; i <= n; i++) {
			cin >> a[i].u >> a[i].v >> a[i].w;
		}
		sort(a + 1, a + n + 1, cmp1);
		for (int i = 1; i <= n; i++) {
			if (a[i].u >= a[i].v && a[i].u >= a[i].w && s1 < n / 2 && a[i].v + a[i + 1].u < a[i].u + a[i + 1].v) {
				s1++;
				ans += a[i].u;
				a[i].v = 0;
				a[i].w = 0;
			}
		}
		sort(a + 1, a + n + 1, cmp2);
		for (int i = 1; i <= n; i++) {
			if (a[i].v >= a[i].w && s2 < n / 2) {
				s2++;
				ans += a[i].v;
				a[i].u = 0;
				a[i].w = 0;
			}
		}
		sort(a + 1, a + n + 1, cmp3);
		for (int i = 1; i <= n; i++) {
			if (s3 < n / 2) {
				s3++;
				ans += a[i].w;
				a[i].v = 0;
				a[i].u = 0;
			}
		}
		cout << ans << endl;
		ans = 0;
		s1 = 0;
		s2 = 0;
		s3 = 0;
	}
}