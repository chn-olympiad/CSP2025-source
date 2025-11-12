#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int T, n, f[N][3];

struct node {
	int a, b, c;
} a[N];

bool cmp(node a, node b) {
	return max({a.a, a.b, a.c}) > max({b.a, b.b, b.c});
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> T;
	while (T--) {
		cin >> n;
		for (int i = 1; i <= n; i++)
			cin >> a[i].a >> a[i].b >> a[i].c;
//		sort(a + 1, a + n + 1, cmp);
		int aa = 0, bb = 0, cc = 0;
		memset(f, 0, sizeof(f));
		f[1][0] = a[1].a;
		f[1][1] = a[1].b;
		f[1][2] = a[1].c;
		int resa = 0, resb = 0, resc = 0;
		aa = 1;
		for (int i = 2; i <= n; i++) {
			int tmp = -2e9;
			tmp = max({f[i - 1][0], f[i - 1][1], f[i - 1][2]});
			if (tmp == f[i - 1][0])
				aa++;
			else if (tmp == f[i - 1][1])
				bb++;
			else
				cc++;
			if (aa <= n / 2)
				f[i][0] = max(f[i][0], tmp + a[i].a);
			if (bb <= n / 2)
				f[i][1] = max(f[i][1], tmp + a[i].b);
			if (cc <= n / 2)
				f[i][2] = max(f[i][2], tmp + a[i].c);
		}
		resa = max({f[n][0], f[n][1], f[n][2]});
		aa = cc = 0;
		bb = 1;
		memset(f, 0, sizeof(f));
		f[1][0] = a[1].a;
		f[1][1] = a[1].b;
		f[1][2] = a[1].c;
		for (int i = 2; i <= n; i++) {
			int tmp = -2e9;
			tmp = max({f[i - 1][0], f[i - 1][1], f[i - 1][2]});
			if (tmp == f[i - 1][0])
				aa++;
			else if (tmp == f[i - 1][1])
				bb++;
			else
				cc++;
			if (aa <= n / 2)
				f[i][0] = max(f[i][0], tmp + a[i].a);
			if (bb <= n / 2)
				f[i][1] = max(f[i][1], tmp + a[i].b);
			if (cc <= n / 2)
				f[i][2] = max(f[i][2], tmp + a[i].c);
		}
		resb = max({f[n][0], f[n][1], f[n][2]});
		aa = bb = 0;
		cc = 1;
		memset(f, 0, sizeof(f));
		f[1][0] = a[1].a;
		f[1][1] = a[1].b;
		f[1][2] = a[1].c;
		for (int i = 2; i <= n; i++) {
			int tmp = -2e9;
			tmp = max({f[i - 1][0], f[i - 1][1], f[i - 1][2]});
			if (tmp == f[i - 1][0])
				aa++;
			else if (tmp == f[i - 1][1])
				bb++;
			else
				cc++;
			if (aa <= n / 2)
				f[i][0] = max(f[i][0], tmp + a[i].a);
			if (bb <= n / 2)
				f[i][1] = max(f[i][1], tmp + a[i].b);
			if (cc <= n / 2)
				f[i][2] = max(f[i][2], tmp + a[i].c);
		}
		resc = max({f[n][0], f[n][1], f[n][2]});
		cout << max({resa, resb, resc}) << '\n';
	}
	return 0;
}
/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0
*/