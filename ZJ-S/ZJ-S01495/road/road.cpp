#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2000010;

ll n,m,k,ans,tot;
ll c[N],a[N];
ll fa[N];

struct edge{
	ll u,v,w;
}e[N];

bool cmp(edge x,edge y){
	return x.w<y.w;
}

ll find(ll x){
	if(fa[x]==x) return x;
	fa[x]=find(fa[x]);
	return fa[x];
}

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	
	cin>>n>>m>>k;
	tot=m;
	for(int i=1;i<=m;i++){
		scanf("%lld %lld %lld",&e[i].u,&e[i].v,&e[i].w);
	}
	for(int j=1;j<=k;j++){
		memset(a,0,sizeof(a));
		scanf("%lld",&c[j]);
		for(int i=1;i<=n;i++){
			scanf("%lld",&a[i]);
		}
		for(int i=1;i<=n;i++){
			for(int k=i+1;k<=n;k++){
				e[++tot].u=i;
				e[tot].v=k;
				e[tot].w=c[j]+a[i]+a[k];
			}
		}
	}
	for(int i=1;i<=n;i++){
		fa[i]=i;
	}
	sort(e+1,e+1+tot,cmp);
	for(int i=1;i<=m;i++){
		ll fu=find(e[i].u);
		ll fv=find(e[i].v);
		if(fu==fv) continue;
		fa[fv]=fu;
		ans+=e[i].w;
	}
	cout<<ans;
	return 0;
}
