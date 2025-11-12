#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,k;
int fa[10104];
vector<pair<int,int>>ve[10104];
struct node{
	int u,v,w;
};
int find(int x){
	if(fa[x]==x)return fa[x];
	else return fa[x]=find(fa[x]);
}
vector<node>E;
signed main(){
	freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=n+k;i++)
		fa[i]=i;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		ve[u].emplace_back(v,w);
		ve[v].emplace_back(u,w);
		E.push_back({u,v,w});
	}
	for(int i=1;i<=k;i++){
		int x;
		cin>>x;
		for(int j=1;j<=n;j++){
			int x;
			cin>>x;
			ve[i+n].emplace_back(j,x);
			ve[j].emplace_back(i+n,x);
			E.push_back({i+n,j,x});
		}
	}
	int ans=0;
	sort(E.begin(),E.end(),[](node x,node y){return x.w<y.w;});
	for(auto i:E){
		if(find(fa[i.u])!=find(fa[i.v])){
			ans+=i.w;
			cout<<i.u<<' '<<i.v<<' '<<find(i.u)<<' '<<find(i.v)<<endl;
			fa[find(i.u)]=find(fa[i.v]);
		}
	}
	cout<<ans;
	return 0;
}

