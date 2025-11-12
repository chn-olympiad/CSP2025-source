#include<bits/stdc++.h>
typedef long long ll;
const ll N=3e6+10;
using namespace std;
ll n,m,k,fa[N/10],c[15][N/20],ans;
//ll ci,vis[N/10];
//bool in[N/10];
struct node{
	ll u,v,c;
}a[N];
bool cmp(node a,node b){
	return a.c<b.c;
}
ll find(ll x){
	if(fa[x]==x) return fa[x];
	fa[x]=find(fa[x]);
	return fa[x];
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&k);
	for(ll i=1;i<=n+n;i++)
		fa[i]=i;
	for(ll i=1;i<=m;i++){
		ll u,v,c;
		scanf("%lld%lld%lld",&a[i].u,&a[i].v,&a[i].c);
	}
	for(ll i=1;i<=k;i++){
		for(ll j=0;j<=n;j++){
			scanf("%lld",&c[i][j]);
//			vis[i+n]=c[i][0];
//			if(j>0){
//				a[++m].u=j;
//				a[m].v=n+i;
//				a[m].c=c[i][j];
//			}
		}
	}
	sort(a+1,a+1+m,cmp);
	for(ll i=1;i<=m;i++){
		ll x=find(a[i].u),y=find(a[i].v);
		if(x!=y){
//			if(!in[a[i].u]&&a[i].u>=1&&a[i].u<=n){
//				in[a[i].u]=1;
//				ci++;
//			}
//			if(!in[a[i].v]&&a[i].v>=1&&a[i].v<=n){
//				in[a[i].v]=1;
//				ci++;
//			}
			fa[x]=y;
			ans+=a[i].c;
//			ans+=vis[a[i].u];
//			ans+=vis[a[i].v];
		}
	}
	printf("%lld",ans);
	return 0;
}
