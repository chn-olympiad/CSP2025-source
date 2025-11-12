#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
int n,m,k;
struct NODE{
	int to,c;
};
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	vector<vector<NODE>> gra(n);
	vector<vector<int>> city(k,vector<int>(n));
	for(int i=0;i<m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		gra[u].push_back({v,w});
		gra[v].push_back({u,w});
	}
	for(int i=0;i<k;i++)
		for(int j=0;j<n;j++)
			cin>>city[i][j];
	
	cout<<city[k-1][n-1];
	fclose(stdin);
	fclose(stdout);
	return 0;
}
