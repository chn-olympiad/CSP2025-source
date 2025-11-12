#include<bits/stdc++.h>
using namespace std;
#define u first
#define v second
#define ll long long
ll n,m,k,fa[100005],a[15][100005],p=0;
ll find(ll x){
	if(fa[x]==x)return x;
	else return fa[x]=find(fa[x]);
}
struct Line{
	ll u,v,w;
};
bool cmp(Line x,Line y){
	return x.w<y.w;
}
Line l[10000005];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m>>k;
	for(ll i=1;i<=m;i++){
		cin>>l[i].u>>l[i].v>>l[i].w;
	}
	for(ll i=1;i<=n+k;i++)fa[i]=i;
	for(int i=1;i<=k;i++){
		for(int j=0;j<=n;j++)cin>>a[i][j];
	}
	int f=0;
	for(int i=1;i<=k;i++){
		if(a[i][0]!=0)f=1;
	}
	if(f==0){
		for(int i=1;i<=k;i++){
			for(int j=1;j<=n;j++){
				l[++m].u=i+n;
				l[m].v=j;
				l[m].w=a[i][j];
			}
		}
		n+=k;
		k=0;
	}
	sort(l+1,l+1+m,cmp);
	if(k==0){
		ll ans=0;
		for(ll i=1;i<=m;i++){
			ll u=l[i].u,v=l[i].v;
			int ku=u,kv=v;
			u=find(u);
			v=find(v);
			if(u==v)continue;
//			cout<<ku<<" "<<kv<<" "<<l[i].w<<endl;
			ans+=l[i].w;
			fa[u]=v;
			p++;
			if(p==n-1)break;
		}
		cout<<ans;
		return 0;
	}else{
		int ans=0;
		for(ll i=1;i<=m;i++){
			ll u=l[i].u,v=l[i].v;
			int ku=u,kv=v;
			u=find(u);
			v=find(v);
			if(u==v)continue;
//			cout<<ku<<" "<<kv<<" "<<l[i].w<<endl;
			ans+=l[i].w;
			fa[u]=v;
			p++;
			if(p==n-1)break;
		}
		cout<<ans;
		return 0;
	}
	return 0;
}
/*
4
5 5
1 4 6
4 3 4
2 4 5
1 2 7
1 3 9
0 0 4 3 5
0 3 2 4 0
0 2 1 0 5
0 9 8 4 0
0 0 4 8 8*/