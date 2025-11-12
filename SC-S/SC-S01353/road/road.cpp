#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N = 1e3+10;
struct node {
	ll x, y, val;
} p[N*N];
ll n, m, k, fa[N];
ll co[N][N];
ll read(){
	ll x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-') f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=(x<<1)+(x<<3)+(c-'0');
		c=getchar();
	}
	return f*x;
}
ll fin(ll x) {
	if (fa[x] == x) return x;
	return fa[x] = fin(fa[x]);
}
bool cmp(node a, node b) {
	return a.val < b.val;
}
void solve1() {
	for (ll i = 1; i <= m; i++) {
		ll x, y, val;
		x=read(),y=read(),val=read();
		p[i].x = x, p[i].y = y, p[i].val = val;
	}
	for (ll i = 1; i <= m; i++) fa[i] = i;
	sort(p + 1, p + m + 1, cmp);
	ll num = 0, sum = 0;
	for (ll i = 1; i <= m; i++) {
		ll x = p[i].x, y = p[i].y, val = p[i].val;
		ll t1 = fin(x), t2 = fin(y);
		if (t1 == t2) continue;
		fa[t1] = t2;
		num++;
		sum += val;
		if (num == n - 1) {
			cout << sum;
			return;
		}
	}
}

int main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);

	n=read(),m=read(),k=read();
	if (k == 0) solve1();
	else {
		for (ll i = 1; i <= m; i++) {
			ll x, y, val;
			x=read(),y=read(),val=read();
			p[i].x = x, p[i].y = y, p[i].val = val;
		}
		ll x;
		for (ll i = 1; i <= k; i++) {
			read();
			for (ll j = 1; j <= n; j++) {
				x=read();
				co[i][j] = x;
			}
		}
		ll cnt = m;
		for (ll l = 1; l <= k; l++) {
			for (ll i = 1; i <= n; i++) {
				for (ll j = 1; j <= n; j++) {
					++cnt;
					p[cnt].x = i, p[cnt].y = j, p[cnt].val = co[l][i] + co[l][j];
				}
			}
		}
		for (ll i = 1; i <= cnt; i++) fa[i] = i;
		sort(p + 1, p + cnt + 1, cmp);
		ll num = 0, sum = 0;
		for (ll i = 1; i <= cnt; i++) {
			ll x = p[i].x, y = p[i].y, val = p[i].val;
			ll t1 = fin(x), t2 = fin(y);
			if (t1 == t2) continue;
			fa[t1] = t2;
			num++;
			sum += val;
			if (num == n - 1) {
				cout << sum;
				return 0;
			}
		}
	}
	cout<<"Why you come here.";
	return 0;
}