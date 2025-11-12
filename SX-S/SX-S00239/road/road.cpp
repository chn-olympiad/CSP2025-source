#include <bits/stdc++.h>
#define int register int
#define ll long long
#define db double
#define AKIOI ios::sync_with_stdio(false);cin.tie(0),cout.tie(0)
using namespace std;
ll n, m, k, ans, o, bl[1000005];

struct node {
	bool flag;
	ll lin;
} mp[1005][1005];
bool f;

struct lines {
	ll u, v, w;
} l[1000005];

bool check_(ll x) {
	for (int i = 1; i <= o; i++) {
		if (bl[i] == x)
			return false;
	}
	return true;
}

bool cmp(lines p, lines q) {
	return p.w > q.w;
}

bool bfs(ll u, ll v, ll badline) {
	queue<ll>q;
	q.push(u);
	while (!q.empty()) {
		ll now = q.front();
		q.pop();
		if (now == v)
			return true;
		for (int i = 1; i <= n; i++) {
			if (mp[now][i].flag && check_(mp[now][i].lin) && mp[now][i].lin != badline)
				q.push(i);
		}
	}
	return false;
}

signed main() {
//	freopen("road.in", "r", stdin);
//	freopen("road.out", "w", stdout);

	AKIOI;
	cin >> n >> m >> k;
	for (int i = 1; i <= m; i++) {
		cin >> l[i].u >> l[i].v >> l[i].w;
		ans += l[i].w;
		mp[l[i].u][l[i].v].flag = 1;
		mp[l[i].v][l[i].u].flag = 1;
	}
	sort(l + 1, l + m + 1, cmp);
	for (int i = 1; i <= n; i++) {
		if (bfs(l[i].u, l[i].v, i)) {
			bl[++o] = i;
			ans -= l[i].w;
		}
	}
	cout << ans;
	return 0;
}
//expected:0pts
/*
能做一做的T2出了一道没学过的图论，破防了
qpzc：兹磁，资瓷，滋磁
*/