#include<bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;
struct r{ll u,v,w;}a[1014514],b[114514];
ll n,m,k,l,ans,q[114];
ll f[114514],s[114514];
bool cmp(r x,r y){return x.w<y.w;}
ll find(ll x){
	if(x==f[x]) return x;
	return f[x]=find(f[x]);
}
ll kru(){
	ll rp=0;
	for(int i=1;i<=n+10;i++) f[i]=i,s[i]=1;
	sort(b+1,b+l+1,cmp);
	for(int i=1;i<=l;i++){
		int u=b[i].u,v=b[i].v;
		if(find(u)==find(v)) continue;
		rp+=b[i].w;
		u=find(u),v=find(v);
		if(s[u]>s[v]) s[u]+=s[v],f[v]=u;
		else s[v]+=s[u],f[u]=v;
	}
	return rp;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=n+10;i++) f[i]=i,s[i]=1;
	for(int i=1;i<=m;i++) cin>>a[i].u>>a[i].v>>a[i].w;
	sort(a+1,a+m+1,cmp);
	for(int i=1;i<=m;i++){
		int u=a[i].u,v=a[i].v;
		if(find(u)==find(v)) continue;
		ans+=a[i].w;
		b[++l].u=u,b[l].v=v,b[l].w=a[i].w;
		u=find(u),v=find(v);
		if(s[u]>s[v]) s[u]+=s[v],f[v]=u;
		else s[v]+=s[u],f[u]=v;
	}
	for(int i=1,x;i<=k;i++){
		cin>>x;
		int t=l;
		for(int j=1,y;j<=n;j++){
			cin>>y;
			b[++l].u=n+i,b[l].v=j,b[l].w=y;
		}
		ll num=kru();
		if(ans-num>x) ans=num+x;
		else l=t;
	}
	cout<<ans;
	return 0;
}