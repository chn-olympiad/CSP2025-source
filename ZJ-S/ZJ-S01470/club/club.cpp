#include <bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;
const ll N = 1e5+5;
struct node{ll a,b,c;}p[N];
ll n,ans;
ll c[4];
bool cmp(node x,node y){
	ll xa = x.a,xb = x.b,xc = x.c,ya = y.a,yb = y.b,yc = y.c;
	if (xa < xb) swap(xa,xb);if (xa < xc) swap(xa,xc);if (xb < xc) swap(xb,xc);
	if (ya < yb) swap(ya,yb);if (ya < yc) swap(ya,yc);if (yb < yc) swap(yb,yc);
	if (xa-xb == ya-yb) return xb-xc > yb-yc;
	return xa-xb > ya-yb;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ll T;cin >> T;
	while (T--){
		cin >> n;
		for (ll i = 1;i <= n;i++) cin >> p[i].a >> p[i].b >> p[i].c;
		sort(p+1,p+1+n,cmp);
		ans = 0;c[1] = c[2] = c[3] = 0;
		for (ll i = 1;i <= n;i++){
			auto x = p[i];
			ll xa = x.a,xb = x.b,xc = x.c,p1 = 1,p2 = 2,p3 = 3;
			if (xa < xb){swap(xa,xb);swap(p1,p2);}if (xa < xc){swap(xa,xc);swap(p1,p3);}if (xb < xc){swap(xb,xc);swap(p2,p3);}
			if (c[p1] < n/2){c[p1]++;ans += xa;continue;}
			if (c[p2] < n/2){c[p2]++;ans += xb;continue;}
			if (c[p3] < n/2){c[p3]++;ans += xc;continue;}
		}
		cout << ans << '\n';
	}
	return 0;
} 
