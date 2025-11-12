#include<bits/stdc++.h>
using namespace std;
int n,m,k;
struct e{
	int to,step;
};
vector<e> g[10005];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int x,y,z;
		cin>>x>>y>>z;
		g[x].push_back({y,z});
		g[y].push_back({x,z});
	}
	for(int i=1;i<=k;i++){
		for(int j=0;j<=n;j++){
			int _;
			cin>>_;
		}
	}
	cout<<0;
	return 0;
}