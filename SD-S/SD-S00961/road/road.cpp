#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ios ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define pb push_back
const int N=1e4+5,M=1e6+5,mod=998244353;
int n,m,k;
struct node{
	int u,v,w;
	bool operator <(const node &x)const{
		return w<x.w;
	}
};
vector<node>edge;
int country_cost[15],country_val[15][N];
int fa[N];
int find(int x){
	if(fa[x]==x){
		return x;
	}
	return fa[x]=find(fa[x]);
}
int kruskal(){
	sort(edge.begin(),edge.end());
	int cnt=0,ans=0;
	for(node i:edge){
		int u=i.u,v=i.v,w=i.w;
		u=find(u);v=find(v);
		if(u!=v){
			fa[u]=v;
			cnt++;
			ans+=w;
		}
		if(cnt==n-1){
			break;
		}
	}
	return ans;
}
signed main(){
	ios;
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)fa[i]=i;
	for(int i=1,u,v,w;i<=m;i++){
		cin>>u>>v>>w;
		edge.pb({u,v,w});
		edge.pb({v,u,w});
	}
	if(!k){
		cout<<kruskal();
		return 0;
	}
	int feijunxi=0;
	for(int i=1;i<=k;i++){
		cin>>country_cost[i];
		feijunxi+=country_cost[i];
		for(int j=1;j<=n;j++){
			cin>>country_val[i][j];	
		}
	}
	if(!feijunxi){
		for(int i=1;i<=k;i++){
			for(int j=1;j<=n;j++){
				for(int l=j+1;l<=n;l++){
					edge.pb({j,l,country_val[i][j]+country_val[i][l]});
					edge.pb({l,j,country_val[i][j]+country_val[i][l]});
				}
			}
		}
		cout<<kruskal();
	}
	return 0;
}


