#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll n,m,k;
ll fa[11005];
ll find(ll x){
	if(x != fa[x]){
		fa[x] = find(fa[x]);
	}
	return fa[x];
}
bool merge(ll x,ll y){
	ll fx = find(x),fy = find(y);
	if(fx == fy){
		return 0;
	}
	fa[fx] = fy;
	return 1;
}
struct edg{
	ll u,v,w,id;
	bool b;
	bool operator < (const edg &y){
		return w < y.w;
	}
}e[1500005],g[1500005];
//vector <ll>g[10005];
bool flag = 1;
ll ans = 1e16;
struct info{
	ll c;
	ll a[10005];
}a[15];
ll mt;
//ll f[1005][1005];
ll mi;
ll solve(bool x){
//	puts("!!");
	for(ll i = 1;i <= n + 100;i++){
		fa[i] = i;
	}
//	puts("!!");
	for(ll i = 1;i <= mt;i++){
		g[i] = e[i];
	}
//	printf("@%lld (mt)@\n",mt);
	sort(g+1,g+mt+1);
//	printf("$");
	ll r = 0;
	for(ll i = 1;i <= mt;i++){
		if(merge(g[i].u,g[i].v)){
			r += g[i].w;
		}
		else{
			if(x){
				e[g[i].id].b = 1;
			}
		}
	}
	return r;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
//	memset(f,1,sizeof(f));
	scanf("%lld%lld%lld",&n,&m,&k);
//	if(k == 0){
	if(k == 0){
		ans = 0;
		for(ll i = 1;i <= n;i++){
			fa[i] = i;
		}
		for(ll i = 1;i <= m;i++){
			scanf("%lld%lld%lld",&e[i].u,&e[i].v,&e[i].w);
		//	e[i].w;
			mt++;
	/*		if(n <= 1000){
				f[e[i].u][e[i].v] = f[e[i].v][e[i].u] = min(f[e[i].v][e[i].u],e[i].w);
			}*/
		}
		for(ll i = 1;i <= k;i++){
			ll x;
			scanf("%lld",&x);
			if(x){
				flag = 0;
			}
			a[i].c = x;
			for(ll j = 1;j <= n;j++){
				ll y;
				scanf("%lld",&y);
				if(y){
					flag = 0;
				}
				a[i].a[j] = y;
			}
	/*		if(n <= 1000){
				for(ll j = 1;j <= n;j++){
					for(ll l = j + 1;l <= n;l++){
						f[l][j] = f[j][l] = min(f[j][l],a[i].c + a[i].a[j] + a[i].a[k]);
					}
				}
			}*/
		}
	/*	if(k && flag && n > 1000){
			printf("0");
			return 0;
		}*/
		sort(e+1,e+m+1);
		for(ll i = 1;i <= m;i++){
			if(merge(e[i].u,e[i].v)){
				ans += e[i].w;
			}
		}
		if(k == 0){
			printf("%lld",ans);
		}	
	}
	else{
		for(ll i = 1;i <= m;i++){
			scanf("%lld%lld%lld",&e[i].u,&e[i].v,&e[i].w);
			e[i].id = i;
		}
		for(ll i = 1;i <= k;i++){
			scanf("%lld",&a[i].c);
			for(ll j = 1;j <= n;j++){
				scanf("%lld",&a[i].a[j]);
			}
		}
		mt = m;
		ans = solve(1);
	//	puts("!!");
		mt = 0;
		for(ll i = 1;i <= m;i++){
			if(!e[i].b){
				++mt;
				e[mt] = e[i];
			}
		}
	//	puts("!!");
		m = mt;
		mi = 0;
		for(ll i = 1;i <= (1 << k) - 1;i++){
			//printf("%lld\n",i);
			mt = m;
			mi = 0;
			for(ll j = 1;j <= k;j++){
				if(i & (1 << (j - 1))){
					mi += a[j].c;
					for(ll l = 1;l <= n;l++){
						mt++;
						e[mt].u = n + j;
						e[mt].v = l;
						e[mt].w = a[j].a[l];
					}
				}
			}
			mi += solve(0);
		//	printf("%lld\n",mi);
			ans = min(ans,mi);
		}
		printf("%lld",ans);
	}
	
	//}
	return 0;
}
/*4 6 0
1 2 2
1 3 8
3 4 4
1 4 5
2 3 7
2 4 6*/
/*4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4*/

