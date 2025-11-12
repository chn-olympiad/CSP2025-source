#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,k,c[20],w[20][10005],fa[10005];
vector<pair<int,pair<int,int> > > e;
int fi(int u){
	if(fa[u]==u)return u;
	return fa[u]=fi(fa[u]);
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		e.push_back({w,{u,v}});
	}
	for(int i=1;i<=k;i++){
		int tmp;
		cin>>tmp;
		int a[10005]{0},boot;
		for(int j=1;j<=n;j++){
			cin>>a[j];
			if(a[j]==0)boot=j;
		}
		for(int j=1;j<=n;j++)
			e.push_back({a[j],{boot,j}});
	} 
	sort(e.begin(),e.end());
	for(int i=1;i<=n;i++)
		fa[i]=i;
	int cnt=0,ans=0;
	for(auto u:e){
		if(cnt==n-1)break;
		if(fi(u.second.first)==fi(u.second.second))continue;
		fa[fi(u.second.first)]=fi(u.second.second);
		ans+=u.first;
		cnt++;
	}
	cout<<ans;
	return 0;
}

