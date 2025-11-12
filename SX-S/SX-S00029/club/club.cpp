#include <bits/stdc++.h>
using namespace std;
const int N = 100005;
long long t, n, m, f[5], a[N], b[N], c[N], ans1, ans2, ans3, ans, vi[N], idd, z2, z1, h, z3;

struct node {
	long long id, val;
} a1[N], a2[N], a3[N];

int cmp(node x, node y) {
	return x.val > y.val;
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> t;
	while (t--) {
		ans = 0;
		cin >> n;
		m = n / 2;
		for (int i = 1; i <= n; i++) {
			cin >> a[i] >> b[i] >> c[i];
			a1[i].id = i;
			a2[i].id = i;
			a3[i].id = i;
			a1[i].val = a[i];
			a2[i].val = b[i];
			a3[i].val = c[i];
			if (c[i] == 0)
				z1++;
			if (a[i] == 0)
				z2++;
			if (b[i] == 0)
				z3++;
		}
		if (z1 == n || z2 == n || z3 == n)
			h = 1;
		sort(a1 + 1, a1 + n + 1, cmp);
		sort(a2 + 1, a2 + n + 1, cmp);
		sort(a3 + 1, a3 + n + 1, cmp);
		for (int i = 1; i <= n; i++) {
			if (m >= 1) {
				int mm = m;
				for (int j = 1; j <= mm; j++) {
					if (vi[a1[j].id] == 0 && f[1] == 0)
						ans1 += a1[j].val;
					else if (mm + 1 <= n && h == 1)
						mm++;
				}
				mm = m;
				for (int j = 1; j <= mm; j++) {
					if (vi[a2[j].id] == 0 && f[2] == 0)
						ans2 += a2[j].val;
					else if (mm + 1 <= n && h == 1)
						mm++;
				}
				mm = m;
				for (int j = 1; j <= mm; j++) {
					if (vi[a3[j].id] == 0 && f[3] == 0)
						ans3 += a3[j].val;
					else if (mm + 1 <= n && h == 1)
						mm++;
				}
				if (ans1 >= ans2 && ans1 >= ans3) {
					for (int j = 1; j <= m; j++)
						vi[a1[j].id] = 1;
					ans += ans1;
					ans1 = 0;
					ans2 = 0;
					ans3 = 0;
					f[1] = 1;
				} else if (ans3 >= ans2 && ans1 <= ans3) {
					for (int j = 1; j <= m; j++)
						vi[a3[j].id] = 1;
					ans += ans3;
					ans2 = 0;
					ans1 = 0;
					ans3 = 0;
					f[3] = 1;
				} else if (ans1 <= ans2 && ans2 >= ans3) {
					for (int j = 1; j <= m; j++)
						vi[a2[j].id] = 1;
					ans += ans2;
					ans1 = 0;
					ans2 = 0;
					ans3 = 0;
					f[2] = 1;
				}
				if (h != 1)
					m--;
			}
		}
		for (int i = 1; i <= n; i++)
			if (vi[i] == 0)
				idd = i;
		if (f[1] == 0)
			ans += a[idd];
		else if (f[2] == 0)
			ans += b[idd];
		else if (f[3] == 0)
			ans += c[idd];
		cout << ans;
		for (int i = 1; i <= n; i++)
			vi[i] = 0;
		f[1] = 0;
		f[2] = 0;
		f[3] = 0;
		h = 0;
	}
	return 0;
}