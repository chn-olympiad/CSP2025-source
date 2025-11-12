#include<bits/stdc++.h>
using namespace std;
const int N=1e4+20;
int fa[N],n,m,k,a[11][N],c[11],flag[N];
long long ans=1e18;
vector<array<int,3>>edge;
int find(int x){
	return fa[x]==x?x:fa[x]=find(fa[x]);
}
void update(vector<array<int,3>> &edge){
	sort(edge.begin(),edge.end());
	vector<array<int,3>> res;
	iota(fa+1,fa+N,1);
	for(auto it:edge){
		if(find(it[1])!=find(it[2])){
			fa[find(it[1])]=find(it[2]);
			res.push_back(it);
		}
	}
	edge=res;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		edge.push_back({w,u,v});
	}
	update(edge);
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
			edge.push_back({a[i][j],i+n,j});
		}
	}
	for(int i=1;i<=n;i++)
		flag[i]=1;
	sort(edge.begin(),edge.end());
	for(int s=0;s<(1<<k);s++){
		iota(fa+1,fa+N,1);
		long long res=0;
		for(int j=0;j<k;j++){
			if((s>>j)&1){
				res+=c[j+1];
				flag[n+j+1]=1;
			}
			else
				flag[n+j+1]=0;
		}
		for(auto it:edge){
			if(flag[it[1]]&&flag[it[2]]&&find(it[1])!=find(it[2])){
				res+=it[0];
				fa[find(it[1])]=find(it[2]);
			}
		}
		ans=min(ans,res);
	}
	cout<<ans<<'\n';
	return 0;
}
