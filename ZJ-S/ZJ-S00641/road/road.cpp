#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,m,k,c[10005],fA=1;
struct node{
	int id,w=INT_MAX;
};
pair<node,node> g[10005][1005];
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin.sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		g[u][v].first.w=min(g[u][v].first.w,w);
		g[v][u].first.w=min(g[v][u].first.w,w);
	}
	if(k==0){
		int sum=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				sum+=g[i][j].first.w;
			}
		}
		cout<<sum<<endl;
		return 0;
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		if(c[i]!=0) fA=0;
		for(int j=1;j<=n;j++){
			int a;
			cin>>a;
			if(a!=0) fA=0;
			g[i][j].second.w=a;
		}
	}
	if(fA){
		int sum=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				sum+=min(g[i][j].first.w,g[i][j].second.w);
			}
		}
		cout<<sum<<endl;
		return 0;
	}
	return 0;
}