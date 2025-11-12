#include<bits/stdc++.h>
using namespace std;
#define int long long

vector<vector<int> >c;
struct rd{
	int t;
	int w;
};
vector<vector<rd> >a;
int n,m,k;



signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	a=vector<vector<rd> >(n+1,vector<rd>{});
	for(int i=0;i<m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		a[u].push_back({v,w});
		a[v].push_back({u,w});
	}
	c=vector<vector<int> >(k+1,vector<int>(n+1,0));
	for(int i=1;i<=k;i++){
		int w1;
		cin>>w1;
		c[i][0]=w1;
		for(int j=1;j<=n;j++){
			int w;
			cin>>w;
			c[i][j]=w;
		}
	}
	return 0;
}
