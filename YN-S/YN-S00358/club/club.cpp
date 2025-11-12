#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;

struct node {
	int a, b, c, ajb;//ajb:a-b的值
} d[N];

bool cmpA(node x, node y) {
	return x.a > y.a;
}

bool cmpB(node x, node y) {
	return x.ajb > y.ajb;
}
int t, n, maxx, ans = 0;

void dfs(int dep, int sum, int cnta, int cntb, int cntc) {
	if (dep > n) {
		ans = max(ans, sum);
		return;
	}
	if (cnta < maxx)
		dfs(dep + 1, sum + d[dep].a, cnta + 1, cntb, cntc);
	if (cntb < maxx)
		dfs(dep + 1, sum + d[dep].b, cnta, cntb + 1, cntc);
	if (cntc < maxx)
		dfs(dep + 1, sum + d[dep].c, cnta, cntb, cntc + 1);
}

int main () {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> t;
	while (t--) {
		cin >> n;
		maxx = n / 2, ans = 0;
		int tmpa = 0, tmpb = 0, tmpc = 0;
		for (int i = 1; i <= n; i++) {
			cin >> d[i].a >> d[i].b >> d[i].c;
			d[i].ajb = abs(d[i].a - d[i].b);
			if (d[i].a == 0)
				tmpa++;
			if (d[i].b == 0)
				tmpb++;
			if (d[i].c == 0)
				tmpc++;
		}
		if (tmpa != n && tmpb == n && tmpc == n) { //特殊性质A
			sort(d + 1, d + n + 1, cmpA);
			for (int i = 1; i <= maxx; i++) {
				ans += d[i].a;
			}
			cout << ans << "\n";
			continue;
		}
		if (tmpa != n && tmpb != n && tmpc == n) { //特殊性质B
			sort(d + 1, d + n + 1, cmpB);
			int i = 1, cnta = 0, cntb = 0; //a、b组各选了多少个
			for (int i = 1; i <= n; i++) {
				if (d[i].a > d[i].b) {
					if (cnta < maxx) {
						cnta++;
						ans += d[i].a;
					} else {
						cntb++;
						ans += d[i].b;
					}
				} else {
					if (cntb < maxx) {
						cntb++;
						ans += d[i].b;
					} else {
						cnta++;
						ans += d[i].a;
					}
				}
			}
			cout << ans << "\n";
			continue;
		} else { //小数据
			dfs(1, 0, 0, 0, 0);
			cout << ans << "\n";
		}
	}
	return 0;
}