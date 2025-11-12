#include <bits/stdc++.h>
#define fi first
#define se second
#define mkp make_pair
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const ll INF=0x3f3f3f3f3f3f3f3f, N=1e5+5;
ll T, n, x, y, z, cnt[4], vis[N], b[N], c[N], val[N][4];
struct qwq {
	ll x, id, p;
} a[N*3];

bool mycmp(qwq u, qwq v) {
	return u.x > v.x;
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin>>T;
	while(T--) {
		cin>>n;
		for(ll i=1; i<4; i++) cnt[i]=0;
		for(ll i=1; i<=n; i++) vis[i]=0;
		for(ll i=1; i<=n; i++) {
			cin>>x>>y>>z;
			a[i*3-2]={x, i, 1};
			a[i*3-1]={y, i, 2};
			a[i*3]={z, i, 3};
			val[i][1]=x;
			val[i][2]=y;
			val[i][3]=z;
		}
		sort(a+1, a+3*n+1, mycmp);
		ll ans=0;
		for(ll i=1; i<=3*n; i++) {
			if(!vis[a[i].id]) {
				ans+=a[i].x;
				vis[a[i].id]=a[i].p;
				ll res=-INF;
				if(a[i].p!=1) res=max(res, val[a[i].id][1]);
				if(a[i].p!=2) res=max(res, val[a[i].id][2]);
				if(a[i].p!=3) res=max(res, val[a[i].id][3]);
				b[a[i].id]=res-val[a[i].id][a[i].p];
				cnt[a[i].p]++;
			}
		}
		if(cnt[1]<=n/2&&cnt[2]<=n/2&&cnt[3]<=n/2) {
			cout<<ans<<'\n';
			continue;
		}
		ll opt=0;
		if(cnt[1]>n/2) opt=1;
		if(cnt[2]>n/2) opt=2;
		if(cnt[3]>n/2) opt=3;
		ll tot=0;
		for(ll i=1; i<=n; i++) if(vis[i]==opt) {
			c[++tot]=b[i];
		}
		sort(c+1, c+tot+1, greater<ll>());
		for(ll i=1; i<=cnt[opt]-n/2; i++) {
			ans+=c[i];
		}
		cout<<ans<<'\n';
	}
	return 0;
}

