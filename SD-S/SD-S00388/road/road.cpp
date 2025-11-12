#include<bits/stdc++.h>
#define ll long long 
using namespace std;
const ll N=2e4+10;
const ll M=2e6+10;
ll n,m,k,c[N],fa[N],top,ans;
ll sz[N],b[15][N];
struct sqy{
	ll u,v,w;
}a[M],e[M];
ll find(ll x){
	if(fa[x]==x)return x;
	fa[x]=find(fa[x]);
	return fa[x];
}
bool marge(ll x,ll y){
	ll tx=find(x),ty=find(y);
	if(tx==ty)return false;
	if(sz[tx]>=sz[ty])fa[ty]=tx,sz[tx]+=sz[ty];
	else fa[tx]=ty,sz[ty]+=sz[tx];
	return true;
}
bool cmp(sqy x,sqy y){
	return x.w<y.w;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&k);
	for(ll i=1;i<=n;i++){
		fa[i]=i;sz[i]=1;
	}
	for(ll i=1;i<=m;i++){
		scanf("%lld%lld%lld",&a[i].u,&a[i].v,&a[i].w);
	}
	sort(a+1,a+m+1,cmp);
	for(ll i=1;i<=k;i++){
		scanf("%lld",&c[i]);
		for(ll j=1;j<=n;j++){
			scanf("%lld",&b[i][j]);
		}
	}
	for(ll i=1;i<=m;i++){
		if(marge(a[i].u,a[i].v))e[++top]=a[i];
	}
	for(ll i=1;i<=top;i++)a[i]=e[i];
	ans=2e15;
	for(ll i=0;i<(1ll<<k);i++){
		ll res=0;top=0;
		for(ll j=1;j<=k;j++){
			if((i>>j-1)&1){
				res+=c[j];
				for(ll l=1;l<=n;l++){
					e[++top]=sqy{n+j,l,b[j][l]};
				}
			}
		}
		for(ll j=1;j<n;j++)e[++top]=a[j];
		sort(e+1,e+top+1,cmp);
		for(ll j=1;j<=n+k;j++)fa[j]=j,sz[j]=1;
		for(ll j=1;j<=top;j++){
			if(marge(e[j].u,e[j].v))res+=e[j].w;
		}
		ans=min(ans,res);
	}
	printf("%lld\n",ans);
	return 0;
} 
