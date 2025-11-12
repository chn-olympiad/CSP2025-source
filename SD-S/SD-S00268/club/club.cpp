bool M1;
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define look_memory cerr<<abs(&M1-&M2)/1024.0/1024<<"MB\n";

namespace syr
{
	const ll N = 1e5+10;
	struct node {
		ll id;
		ll f; //1 2 3
		ll v;
	}a[3*N];
	ll t, n, x, tot, ans;
	ll s[4], vs[N], b[N][4], fl[N][4][4];
	priority_queue <pair<ll, ll>> q[4][4];
	void init () {
		tot = ans = s[1] = s[2] = s[3] = 0;
		memset(a, 0, sizeof(a));
		memset(q, 0, sizeof(q));
		memset(b, 0, sizeof(b));
		memset(fl, 0, sizeof(fl));
		memset(vs, 0, sizeof(vs));
	}
	bool cmp (node a, node b) {
		return a.v>b.v;
	}
	ll change (ll i, ll u, ll v) {
		while (!fl[q[u][v].top().second][u][v] && q[u][v].size()) q[u][v].pop();
		if (!q[u][v].size() || v>=n/2) return -1;
		ll x1 = -q[u][v].top().first;
		ll cha = b[i][u]-b[i][v];
		return cha-x1;
	}
	void add (ll i, ll f) {
		s[f]++;
		vs[i] = 1;
		
		ans += b[i][f];
		ll to = f%3+1;
		fl[i][f][to] = 1;
		q[f][to].push({-(b[i][f]-b[i][to]), i});
		
		to = to%3+1;
		fl[i][f][to] = 1;
		q[f][to].push({-(b[i][f]-b[i][to]), i});
	}
	void work2 () {
		ll ans = 0;
		for (ll i=1; i<=n/2; i++) {
			ans += a[i].v;
		}
		cout<<ans<<'\n';
	}
	void dfs (ll x, ll sum) {
		if (x>n) {
			ans = max(ans, sum);
			return;
		}
		for (ll i=1; i<=3; i++) {
			if (s[i]>=n/2) continue;
			s[i]++;
			dfs(x+1, sum+b[x][i]);
			s[i]--;
		}
	}
	void work4 () {
		dfs(1, 0);
		cout<<ans<<'\n';
	}
	void work()
	{
		cin>>t;
		while (t--) {
			init();
			cin>>n;
			ll sum[4];
			sum[1] = sum[2] = sum[3] = 0;
			for (ll i=1; i<=n; i++) {
				for (ll j=1; j<=3; j++) {
					cin>>b[i][j];
					sum[j] += b[i][j];
					a[++tot] = {i, j, b[i][j]};
				}
			}
			sort(a+1, a+1+tot, cmp);
			if (!sum[2] && !sum[3]) {
				work2();
				continue;
			}
			if (n<=15) {
				work4();
				continue;
			}
			for (ll i=1; i<=tot; i++) {
				if (vs[a[i].id]) continue;
				if (s[a[i].f]>=n/2) {
					ll to = a[i].f%3+1;
					ll w1 = change(a[i].id, a[i].f, to);
					
					to = to%3+1;
					ll w2 = change(a[i].id, a[i].f, to);
					
					if (w1<=0 && w2<=0) continue;
					if (w1>=w2) to = a[i].f%3+1;
					
					ll idd = q[a[i].f][to].top().second;
					q[a[i].f][to].pop();
					s[a[i].f]--;
					vs[idd] = 0;
					fl[idd][a[i].f][a[i].f%3+1] = fl[idd][a[i].f][(a[i].f%3+1)%3+1] = 0;
					ans -= b[idd][a[i].f];
					
					add(idd, to);
				}
				add(a[i].id, a[i].f);
			}
			cout<<ans<<'\n';
		}
	}
}

bool M2;

int main()
{
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin.tie(0)->sync_with_stdio(0);
	look_memory;
	syr::work();
	return 0;
}
/*
1
10
3004 4255 17336
11894 5756 17092
8150 14715 10991
5149 16652 16780
11524 11996 5433
7690 10472 19935
1184 6516 9246
3231 5570 10010
8426 16992 4654
18955 13977 16657

1
10
2 4 28
19 9 27
12 22 17
6 23 25
18 20 7
11 16 30
1 10 14
3 8 15
13 26 5
29 21 24
*/
