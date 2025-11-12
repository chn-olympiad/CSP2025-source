#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e6+5;
int vis[N];
ll head[N], cnt, k;
struct node {
	ll to, nxt, dis;
} edge[N * 3];
ll n, ans, m;
ll mp[N], c[N];
void zxs(ll s) {
	ll M = 0;
	priority_queue<pair<ll, ll > >q;
	q.push(make_pair(0, s));
	while (q.size()) {
//		cout << "!";
		ll x = q.top().second;
		ll d = q.top().first;
		q.pop();
		if (!vis[x]) {
			vis[x] = 1;
			if (x > n) {
				mp[x] = 1;
				M--;
			}
			ans += -d;
//			cout << x << " " << -d << '\n';
			M++;
			if (M == n) {
				break;
			}
			for (ll i = head[x]; i; i = edge[i].nxt) {
				ll dis = edge[i].dis;
				ll y = edge[i].to;
//				cout << y << " " << dis << "\n";
				if (y > n && mp[y] == 0) {
					dis += c[y - n];
				}
				q.push(make_pair(-dis, y));
			}
		}
	}
}
void add(ll from, ll to, ll dis) {
	cnt++;
	edge[cnt].to = to;
	edge[cnt].dis = dis;
	edge[cnt].nxt = head[from];
	head[from] = cnt;
}
int t;
int read() {
	char ch;
	int s = 0;
	int f = 1;
	ch = getchar();
	while (!isdigit(ch)) {
		if (ch == '-')f = -1;
		ch = getchar();
	}
	while (isdigit(ch)) {
		s = s * 10 + ch - '0';
		ch = getchar();
	}
	return f*s;
}
int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	n = read(), m = read(), k = read();
	ll x, y, z;
	for (ll i = 1; i <= m; i++) {
		x = read(), y = read(), z = read();
		add(x, y, z);
		add(y, x, z);
	}

	for (ll i = 1; i <= k; i++) {
		c[i] = read();
		for (ll j = 1; j <= n; j++) {
			t = read();
			add(i + n, j, t);
			add(j, i + n, t);
		}
	}

	zxs(n);
	cout << ans << '\n';
	return 0;
}