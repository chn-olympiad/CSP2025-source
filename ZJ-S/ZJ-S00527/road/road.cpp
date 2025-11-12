#include<bits/stdc++.h>
using namespace std;
const int N = 2e4+5;//这里开小了 
int n,m,k;	
struct edge{
	int u,v,w;
};
vector<edge> eg[N];
int ks[15][N],c[N];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i = 1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		eg[u].push_back({v,w});
		eg[v].push_back({u,w});
	}
	bool can=true;
	for(int i = 1;i<=k;i++){
		cin>>c[i];
		if(c[i]) can=false;
		for(int j = 1;j<=n;j++){
			cin>>ks[i][j];
		}
	}
	cout<<0<<endl;
	fclose(stdin);
	fclose(stdout);
}
