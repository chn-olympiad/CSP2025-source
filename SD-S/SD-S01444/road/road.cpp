#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;
const ll maxn = 100500;
struct edge{
	ll u,v,val;
	bool operator < (const edge & ot)const{
		return val < ot.val;
	}
}e[maxn * 30];
ll fa[maxn],c[15][maxn],book[15];
ll getf(ll x){
	return fa[x] == x ? x : fa[x] = getf(fa[x]);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ll n,m,k,i,u,v,w,j,ans = 0,tot,o;
	scanf("%lld %lld %lld",&n,&m,&k);
	for(i = 1;i <= m;i++){
		scanf("%lld %lld %lld",&u,&v,&w);
		e[i].u = u;
		e[i].v = v;
		e[i].val = w;
	}
	tot = m;
	for(i = 1;i <= k;i++){
		scanf("%lld",&c[i][0]);
		for(j = 1;j <= n;j++){
			scanf("%lld",&c[i][j]);
		}
		for(j = 1;j <= n;j++){
			if(!c[i][j]){
				for(o = 1;o <= n;o++){
					e[++tot] = (edge){j,o,c[i][o]};
				}
			}
		}
	}
	for(i = 1;i <= n;i++) fa[i] = i;
	sort(e + 1,e + tot + 1);
	for(i = 1;i <= tot;i++){
		u = e[i].u;
		v = e[i].v;
		w = e[i].val;
		ll fu,fv;
		fu = getf(u);
		fv = getf(v);
		if(fu == fv) continue;
		fa[fv] = fu;
		ans += w;
	}
	printf("%lld",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
