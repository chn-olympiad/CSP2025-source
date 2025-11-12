#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

const int N = 100010;

int n;
LL w[N][4];
LL a[N], b[N], c[N];
int ac, bc, cc;

bool mycmp(LL x, LL y) {
	return x > y;
}

void solve() {
	scanf("%d", &n);
	ac = bc = cc = 0;
	LL ans = 0;
	for(int i = 1; i <= n; ++ i) {
		scanf("%lld%lld%lld", &w[i][1], &w[i][2], &w[i][3]);
		if(w[i][1] >= w[i][2] && w[i][1] >= w[i][3]) {
			a[++ ac] = i; ans += w[i][1];
		} else if(w[i][2] >= w[i][1] && w[i][2] >= w[i][3]) {
			b[++ bc] = i; ans += w[i][2];
		} else {
			c[++ cc] = i; ans += w[i][3];
		}
	}
	if(ac > n / 2) {
		for(int i = 1; i <= ac; ++ i) {
			int v = max(w[a[i]][2] - w[a[i]][1], w[a[i]][3] - w[a[i]][1]);
			a[i] = v;
		}
		sort(a + 1, a + ac + 1, mycmp);
		int t = ac;
		for(int i = 1; i <= t && ac > n / 2; ++ i, -- ac)
			ans += a[i];
	}
	if(bc > n / 2) {
		for(int i = 1; i <= bc; ++ i) {
			int v = max(w[b[i]][1] - w[b[i]][2], w[b[i]][3] - w[b[i]][2]);
			b[i] = v;
		}
		sort(b + 1, b + bc + 1, mycmp);
		int t = bc;
		for(int i = 1; i <= t && bc > n / 2; ++ i, -- bc)
			ans += b[i];
	}
	if(cc > n / 2) {
		for(int i = 1; i <= cc; ++ i) {
			int v = max(w[c[i]][2] - w[c[i]][3], w[c[i]][1] - w[c[i]][3]);
			c[i] = v;
		}
		sort(c + 1, c + cc + 1, mycmp);
		int t = cc;
		for(int i = 1; i <= t && cc > n / 2; ++ i, -- cc)
			ans += c[i];
	}
	printf("%lld\n", ans);
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int T; scanf("%d", &T);
	while(T --) solve();
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
