#include <bits/stdc++.h>
using namespace std;
#define int long long

int n , m , k , x , y , z , res , ans = 0x3f3f3f3f3f3f3f3f , dis[13009] , vis[13009] , f[23] , c[23] , a[23][13009] , cnt;
struct node {
	int v , w;
	bool operator < (const node &b) const {
		return w > b.w;
	}
};
vector <node> g[13009];

void work(int x) {
	priority_queue <node> q;
	res = 0 , dis[1] = 0 , cnt = 0;
	memset(dis , 0x3f , sizeof dis) , memset(f , 0 , sizeof f) , memset(vis , 0 , sizeof vis);
	for (int i = 1 ; i <= k ; i++) {
		if (x & 1ll != 0) f[i] = 1 , res += c[i];
		x >>= 1ll;
	}
	q.push((node){1 , 0});
	while (!q.empty()) {
		node tmp = q.top(); q.pop();
		if (vis[tmp.v]) continue;
		vis[tmp.v] = 1 , res += tmp.w;
		if (tmp.v > n) {
			for (int i = 1 ; i <= n ; i++) {
				if (vis[i] || dis[i] <= a[tmp.v - n][i]) continue;
				dis[i] = a[tmp.v - n][i];
				q.push((node){i , dis[i]});
			}
			continue;
		}
		for (auto i : g[tmp.v]) {
			if (vis[i.v] || dis[i.v] <= i.w) continue;
			dis[i.v] = i.w;
			q.push((node){i.v , dis[i.v]});
		}
		for (int i = 1 ; i <= k ; i++) {
			if (!f[i] || vis[n + i] || dis[n + i] <= a[i][tmp.v]) continue;
			dis[n + i] = a[i][tmp.v];
			q.push((node){i + n , dis[n + i]});
		}
	}
	ans = min(ans , res);
}

bool check() {
	bool f = 1;
	for (int i = 1 ; i <= k ; i++) {
		if (c[i] != 0) return 0;
		f = 1;
		for (int j = 1 ; j <= n ; j++) if (a[i][j] == 0) f = 0;
		if (f) return 0;
	}
	return 1;
}

signed main() {
	freopen("road.in" , "r" , stdin);
	freopen("road.out" , "w" , stdout);
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> m >> k;
	for (int i = 1 ; i <= m ; i++) cin >> x >> y >> z , g[x].push_back((node){y , z}) , g[y].push_back((node){x , z});
	for (int i = 1 ; i <= k ; i++) {
		cin >> c[i];
		for (int j = 1 ; j <= n ; j++) cin >> a[i][j];
	}
	if (check()) work((1 << k) - 1);
	else for (int i = 0 ; i < (1 << k) ; i++) work(i);
	cout << ans;
	return 0;
}
