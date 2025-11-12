#include <bits/stdc++.h>
using namespace std;

#define int long long
int t, n, m[100005][5], cd[100005], zd[100005];
int cnta = 0, cntb = 0, cntc = 0;
long long ans = 0;

void work(int pyx) {
	memset(cd, 0, sizeof(cd));
	for (int i = 1; i <= n; i++) {
		int y = m[i][pyx];
		sort(m[i] + 1, m[i] + 3 + 1);
//		cout << "***" << i << "***" << endl;
//		for (int j = 1; j <= n; j++) {
//			cout << m[i][j] << endl;
//		}
		cd[i] = m[i][3] - m[i][2];
		if (!(m[i][3] == zd[i] && zd[i] == y)) {
			cd[i] = 2e9;
		}
	}
	sort(cd + 1, cd + n + 1);
//	for (int i = 1; i <= n; i++) {
//		cout << cd[i] << " ";
//	}
//	cout << endl;
//	zd[i] == m[i][pyx]
	for (int i = 1; i <= n; i++) {
		cout << cd[i] << " ";
	}
	cout << endl;
	if (pyx == 1) {
		for (int i = 1; i <= cnta - (n / 2); i++) {
			ans -= cd[i];
		}
	} else if (pyx == 2) {
		for (int i = 1; i <= cntb - (n / 2); i++) {
			ans -= cd[i];
		}
	} else {
		for (int i = 1; i <= cntc - (n / 2); i++) {
			ans -= cd[i];
		}
	}
}

signed main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	scanf("%lld", &t);
	while (t--) {
		ans = cnta = cntb = cntc = 0;
		memset(m, 0, sizeof(m));
		scanf("%lld", &n);
		for (int i = 1; i <= n; i++) {
			scanf("%lld%lld%lld", &m[i][1], &m[i][2], &m[i][3]);
			zd[i] = max(max(m[i][1], m[i][2]), m[i][3]);
			if (zd[i] == m[i][1])
				ans += m[i][1], cnta++;
			else if (zd[i] == m[i][2])
				ans += m[i][2], cntb++;
			else
				ans += m[i][3], cntc++;
		}
//	cout << cnta << " " << cntb << " " << cntc << endl;
//		for (int i = 1; i <= n; i++) {
//			printf("%lld ", zd[i]);
//		}
		if (cnta > (n / 2))
			work(1);
		else if (cntb > (n / 2))
			work(2);
		else if (cntc > (n / 2))
			work(3);
		printf("%lld\n", ans);
	}
	return 0;
}
/*
4
0 1 0
0 1 0
0 2 0
0 2 0
*/