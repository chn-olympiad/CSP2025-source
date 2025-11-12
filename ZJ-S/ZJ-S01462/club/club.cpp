#include <bits/stdc++.h>
using namespace std;

const int N = 100010;
int a[N][3], p[N], cnt[3];

void solve() {
	memset(cnt, 0, sizeof cnt);
	
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i ++ ) {
		for (int j = 0; j < 3; j ++ )
			scanf("%d", &a[i][j]);
	}
	for (int i = 1; i <= n; i ++ ) {
		int mx = max({a[i][0], a[i][1], a[i][2]});
		for (int j = 0; j < 3; j ++ )
			if (a[i][j] == mx) {
				p[i] = j;
				break;
			}
		cnt[p[i]] ++ ;
	}
	if (max({cnt[0], cnt[1], cnt[2]}) <= n / 2) {
		int ans = 0;
		for (int i = 1; i <= n; i ++ ) ans += a[i][p[i]];
		printf("%d\n", ans);
		return;
	}
	int ans = 0;
	for (int i = 0; i < 3; i ++ ) {
		int res = 0;
		priority_queue<int> Q;
		for (int j = 1; j <= n; j ++ ) {
			int mx = -1;
			for (int k = 0; k < 3; k ++ )
				if (i ^ k)
					mx = max(mx, a[j][k]);
			Q.push(a[j][i] - mx);
			res += mx;
		}
		int T = n / 2;
		while (T -- ) {
			res += Q.top();
			Q.pop();
		}
		ans = max(ans, res);
	}
	printf("%d\n", ans);	
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int T;
	cin >> T;
	while (T -- ) solve();
	return 0;
}
