#include <bits/stdc++.h>
using namespace std;
int T, n, dp[100005], cnt[4], sum, t;

struct node {
	int a, b, c, z, m;
} g[100005];

inline bool cmp(node x, node y) {
	if (x.z != t || y.z != t)
		return (x.z == t ? 1 : 0) > (y.z == t ? 1 : 0);
	else {
		return x.m > y.m;
	}
}

inline int read() {
	char c;
	int x;
	while (c = getchar()) {
		x = 3 << (c ^ 48) + 1 << (c ^ 48);
	}
	return x;
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> T;
	while (T--) {
		sum = t = 0;
		for (int i = 1; i < 4; i++)
			cnt[i] = 0;
		cin >> n;
		for (int i = 1; i <= n; i++)
			cin >> g[i].a >> g[i].b >> g[i].c;
		for (int i = 1; i <= n; i++) {
			if (g[i].a >= g[i].b && g[i].a >= g[i].c) {
				cnt[1]++;
				g[i].z = 1;
				sum += g[i].a;
				g[i].m = max(g[i].b, g[i].c) - g[i].a;
			} else if (g[i].b > g[i].a && g[i].b >= g[i].c) {
				cnt[2]++;
				g[i].z = 2;
				sum += g[i].b;
				g[i].m = max(g[i].c, g[i].a) - g[i].b;
			} else {
				cnt[3]++;
				g[i].z = 3;
				sum += g[i].c;
				g[i].m = max(g[i].b, g[i].a) - g[i].c;
			}
		}
		for (int i = 1; i <= 3; i++)
			if (cnt[i] > n / 2)
				t = i;
		sort(g + 1, g + n + 1, cmp);
		for (int i = 1; i <= cnt[t] - n / 2; i++) {
			sum += g[i].m;
		}
		cout << sum << "\n";
	}
	return 0;
}
