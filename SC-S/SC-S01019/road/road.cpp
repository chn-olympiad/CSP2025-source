#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e4 + 12;
struct E{
	int to, l;
};
struct H{
	int d, x;
	bool operator < (const H &rhs) const{
		return d > rhs.d;
	}
};
vector <E> G[N];
int c[N];
int arr[12][N];
priority_queue <H> q; 
int dis[N], vis[N], p[N], cnt[12];
signed main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	memset(dis, 0x3f, sizeof dis);
	memset(vis, 0, sizeof dis);
	memset(arr, 0, sizeof dis);
	int n, m, k;
	cin >> n >> m >> k;
	for (int i = 1, a, b, c; i <= m; ++i) {
		cin >> a >> b >> c;
		G[a].push_back({b, c});
		G[b].push_back({a, c});
	}
	for (int i = 1; i <= k; ++i) {
		cin >> c[i];
		for (int j = 1; j <= n; ++j) {
			cin >> arr[i][j];
		}
	}
	dis[1] = 0;
	vis[1] = 1;
	for (E e : G[1]) {
		dis[e.to] = e.l;
		p[e.to] = 0;
	}
	for (int j = 2; j <= n; ++j) {
		for (int i = 1; i <= k; ++i) {
			if(dis[j] > arr[i][1] + arr[i][j] + c[i]) {
				dis[j] = arr[i][1] + arr[i][j] + c[i];
				p[j] = i;
			}
		}
		q.push({dis[j], j});
	}
	int ans = 0;
	while(!q.empty()) {
//		for (int i = 1; i <= n; ++i) cout << dis[i] << ' ';
//		cout << endl;
		H now = q.top(); q.pop();
//		cout << now.x << ' ' << now.d << endl;
		if(vis[now.x]) continue;
		cnt[p[now.x]]++;
		ans += now.d;
		vis[now.x] = 1;
		dis[now.x] = 0;
		for (E e : G[now.x]) {
			if(!vis[e.to] && dis[e.to] > e.l) {
				dis[e.to] = e.l;
				p[e.to] = 0;
//				cout << e.to << endl;
//				cout << endl;
			}
		}
		for (int j = 1; j <= n; ++j) {
			if(vis[j]) continue;
			int mind = 0x3f3f3f3f3f3f3f3f, x = 0;
			for (int i = 1; i <= k; ++i) {
				if(mind > arr[i][now.x] + arr[i][j] + c[i]) {
					mind = arr[i][now.x] + arr[i][j] + c[i];
					x = i;
				}
			}
			if(dis[j] > mind) {
				dis[j] = mind;
				p[j] = x;
			}
			q.push({dis[j], j});
		}
	}
//	for (int i = 1; i <= n; ++i) cout << p[i] << ' ';
//	cout << endl;
	int sum = 0;
	for (int i = 1; i <= k; ++i) {
		if(cnt[i]) {
			sum += (cnt[i] - 1) * c[i];
		}
	}
	cout << ans - sum << endl;
	return 0;
}
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4


505585650
*/