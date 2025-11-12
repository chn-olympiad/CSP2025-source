#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
struct node{
	int u,v,w;
}a[1000005];
int n,m,f[10005],ans,k,vis[1005][1005],c[15],p[15][1005],t[15];
bool pd[15][1005][1005];
vector<int> g[10005];
int find(int x){
	if(x==f[x]) return x;
	f[x]=find(f[x]);
	return f[x];
}
bool cmp(node x,node y){
	return x.w<y.w;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=n;++i) f[i]=i;
	for(int i=1;i<=m;++i){
		cin>>a[i].u>>a[i].v>>a[i].w;
	}
	for(int i=1;i<=k;++i){
		cin>>c[i];
		for(int j=1;j<=n;++j) cin>>p[i][j];
	}
	sort(a+1,a+1+m,cmp);
	for(int i=1;i<=m;++i){
		if(find(f[a[i].u])!=find(f[a[i].v])){
			ans+=a[i].w;
			f[find(f[a[i].u])]=find(f[a[i].v]);
		}
	}
	cout<<ans;
	return 0;
}