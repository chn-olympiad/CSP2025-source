#include<bits/stdc++.h>
using namespace std;
struct node{
	int u,v;
	long long w;
	bool operator<(const node &s) const{
		return w<s.w;
	}
};
int f[50010];
int find(int k){
	return f[k]==k?k:f[k]=find(f[k]);
}
long long ans=0;
int n,m,k;
long long c[15];
vector<node> g;
int p=0;
void kruskal(){
	for(int i=0;i<g.size();i++){
		if(p==n+k-1) break;
		int u=g[i].u,v=g[i].v;long long w=g[i].w;
		if(find(u)!=find(v)){
			f[find(u)]=find(v);
			ans+=w;
			p++;
		}
	}	
}
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n+k;i++) f[i]=i;
	for(int i=1;i<=m;i++){
		int u,v;
		long long w;
		cin>>u>>v>>w;
		g.push_back({u,v,w});
	}	
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			long long w;cin>>w;
			g.push_back({i+n,j,w});
		}
	}
	sort(g.begin(),g.end());
	kruskal();
	cout<<ans<<endl;
	return 0;
}