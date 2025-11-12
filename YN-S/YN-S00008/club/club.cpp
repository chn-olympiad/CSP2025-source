#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e5 + 50;

struct A {
	int a, b, c;
	int p, m, p2;
} mb[N];

int max_(int a, int b, int c) {
	if (a > b) {
		if (a > c)
			return 1;
		else
			return 3;
	} else {
		if (b > c)
			return 2;
		else
			return 3;
	}
}

bool cmp(A x, A y) {
	if (x.m != y.m)
		return x.m < y.m;
	return x.p > y.p;
}

signed main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int cnta = 0, cntb = 0, cntc = 0;
		int ans = 0;
		int n;
		cin >> n;
		for (int i = 1; i <= n; i++) {
			cin >> mb[i].a >> mb[i].b >> mb[i].c;
			mb[i].m = max_(mb[i].a, mb[i].b, mb[i].c);
			mb[i].p = max(mb[i].a, max(mb[i].b, mb[i].c));
			int a, b;
			if (mb[i].m == 1) {
				cnta++;
				a = mb[i].b;
				b = mb[i].c;
			}

			else if (mb[i].m == 2) {
				cntb++;
				a = mb[i].a;
				b = mb[i].c;
			}

			else {
				cntc++;
				a = mb[i].a;
				b = mb[i].b;
			}
			mb[i].p2 = max(a, b);
		}

//		for (int i = 1; i <= n; i++)
//			cout << mb[i].m << " " << mb[i].p << '\n';
//		cout << '\n';

		if (cnta <= n / 2 && cntb <= n / 2 && cntc <= n / 2) {
			for (int i = 1; i <= n; i++)
				ans += mb[i].p;
			cout << ans << '\n';
			continue;
		}//严格全部满足条件，不用处理

		sort(mb + 1, mb + 1 + n, cmp);
//		for (int i = 1; i <= n; i++)
//			cout << '\n' << mb[i].m << " " << mb[i].p ;
//		cout << '\n';
		int flag = max_(cnta, cntb, cntc), cnt = 1, x = mb[1].m;
		for (int i = 1; i <= n; i++, cnt++) {
			if (mb[i].m != x) {
				x = mb[i].m;
				cnt = 0;
			}
			if (cnt > n / 2) {
				while (mb[i].m == x && i <= n) {
					ans += mb[i].p2;
					i++;
				}
				cnt = 0;
				i--;
				continue;
			}
			ans += mb[i].p;
		}
		cout << ans << '\n';
	}
	return 0;
}