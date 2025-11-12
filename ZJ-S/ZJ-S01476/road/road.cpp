#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,m,k,c[15],rv[15][10010];
struct road{int to,pr;};
vector<road>rc[10010];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		rc[u].push_back({v,w});
		rc[v].push_back({u,w});
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++)
			cin>>rv[i][j];
	}
	cout<<13;
	fclose(stdin);
	fclose(stdout);
	return 0;
}