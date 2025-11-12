#include <bits/stdc++.h>
using namespace std;
long long n, T, m[10005], maxs = -1, suma, sumb, sumc;
long long a[10005][4];

struct zzz {
	long long a, b, c;
} sa[10005];

void dfs(int k) {
	if (k == n + 1) {
		long long s1 = 0;
		for (int i = 1; i <= n; i++) {
			s1 += a[i][m[i]];
		}
		maxs = max(maxs, s1);
		return ;
	}
	if (suma < n / 2) {
		suma++;
		m[k] = 1;
		dfs(k + 1);
		suma--;
	}
	if (sumb < n / 2) {
		sumb++;
		m[k] = 2;
		dfs(k + 1);
		sumb--;
	}
	if (sumc < n / 2) {
		sumc++;
		m[k] = 3;
		dfs(k + 1);
		sumc--;
	}
}

bool cmp(zzz x, zzz y) {
	return x.a > y.b;
}

bool cmp1(zzz x, zzz y) {
	if (x.b == y.a)
		return x.a < y.a;
	return x.b > y.b;
}

bool cmp2(zzz x, zzz y) {
	if (x.a == y.a)
		return x.b < y.b;
	return x.a > y.a;
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> T;
	while (T--) {
		cin >> n;
		bool p = 1, pp = 1;
		for (int i = 1; i <= n; i++) {
			cin >> a[i][1] >> a[i][2] >> a[i][3];
			sa[i].a = a[i][1];
			sa[i].b = a[i][2];
			sa[i].c = a[i][3];
			if (a[i][2] != 0)
				p = 0;
			if (a[i][3] != 0)
				pp = 0;
		}
		if (n <= 30) {
			dfs(1);
			cout << maxs << "\n";
			maxs = -1;
			suma = 0;
			sumb = 0;
			sumc = 0;
			continue;
		}
		if (p && pp) {
			sort(sa + 1, sa + n + 1, cmp);
			long long ans = 0;
			for (int i = 1; i <= n / 2; i++)
				ans += sa[i].a;
			cout << ans << "\n";
			continue;
		}
		if (pp) {
			sort(sa + 1, sa + n + 1, cmp1);
			long long ans = 0;
			for (int i = 1; i <= n / 2; i++)
				ans += sa[i].b;
			for (int i = n / 2 + 1; i <= n; i++)
				ans += sa[i].a;
			sort(sa + 1, sa + n + 1, cmp2);
			long long ANS = 0;
			for (int i = 1; i <= n / 2; i++)
				ANS += sa[i].a;
			for (int i = n / 2 + 1; i <= n; i++)
				ANS += sa[i].b;
			cout << max(ans, ANS) << "\n";
		}
	}

	return 0;
}
