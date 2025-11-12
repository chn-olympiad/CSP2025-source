#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,k,x,u,v,w,sm,c[12],fa[10020],s,ans;
struct node{ll u,v,w,c;}a[1000010],b[200010];
bool cmp(node x,node y){return x.w<y.w;}
ll find(ll x){return x==fa[x]?x:fa[x]=find(fa[x]);}
int main(){
	freopen("road.in","r",stdin),freopen("road.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m>>k,ans=1e18;
	for(ll i=1;i<=n;i++)fa[i]=i;
	for(ll i=1;i<=m;i++)cin>>a[i].u>>a[i].v>>a[i].w;
	sort(a+1,a+m+1,cmp);
	for(ll i=1;i<=k;i++){
		cin>>c[i];
		for(ll j=1;j<=n;j++)cin>>w,b[++x]={i+n,j,w,i};
	}
	for(ll i=1;i<=m;i++){
		u=a[i].u,v=a[i].v;
		if(find(u)!=find(v))fa[find(v)]=find(u),b[++x]=a[i];
	}
	sort(b+1,b+x+1,cmp);
	for(ll i=0;i<1<<k;i++){
		s=0;
		for(ll j=0;j<k;j++)if(i>>j&1)s+=c[j+1];
		for(ll j=1;j<=n+k;j++)fa[j]=j;
		for(ll j=1;j<=x;j++)if(!b[j].c||(i>>(b[j].c-1)&1)){
			u=b[j].u,v=b[j].v;
			if(find(u)!=find(v))fa[find(v)]=find(u),s+=b[j].w;
		}
		ans=min(ans,s);
	}
	cout<<ans;
	return 0;
}
