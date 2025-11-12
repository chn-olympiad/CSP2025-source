#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int> > v[10005];
int g[10005][10005];
bool st[10005];
int n, m, k;

void fi() {
	long long ans = 1000000000000000000;
	long long res = 0;
	for ( int i = 1 ; i <= n ; i ++ ) {
		res = 0;
		queue<int> q;
		q.push(1);
		memset(st, false, sizeof st);
		int tt = 0;
		int idx, cnt;
		while ( tt < n ) {
			int kk = q.front();
			q.pop();
			tt++;
			cnt = 0x3f3f3f3f;
			for ( auto j : v[kk] ) {
				if ( j.second < cnt && !st[j.first] ) {
					cnt = j.second;
					idx = j.first;
				}
			}
			st[idx] = true;
			q.push(idx);
			res += cnt;
		}
		ans = min(ans, res);
	}
	printf("%lld", ans);
}

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	scanf("%d %d %d", &n, &m, &k);
	for ( int i = 1 ; i <= m ; i ++ ) {
		int a, b, d;
		scanf("%d %d %d", &a, &b, &d);
		v[a].push_back({b, d});
		v[b].push_back({a, d});
	}
	memset(g, 0x3f, sizeof g);
	for ( int i = 1 ; i <= k ; i ++ ) {
		int qq;
		cin >> qq;
		for ( int j = 1 ; j <= n ; j ++ ) {

			cin >> g[j][j];
		}
		for ( int j = 1 ; j <= n ; j ++ ) {
			for ( int kkk = 1 ; kkk <= n ; kkk ++ ) {
				if ( j == kkk )
					continue;
				g[j][kkk] = min(g[j][kkk], g[j][j] + g[kkk][kkk]);
			}
		}
	}
	for ( int i = 1 ; i <= n ; i ++ ) {
		for ( int j = 1 ; j <= n ; j ++ ) {
			if ( i == j )
				continue;
			v[i].push_back({j, g[i][j]});
			v[j].push_back({i, g[i][j]});
		}
	}
	fi();
	return 0;
}