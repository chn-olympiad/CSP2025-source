#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int n,m,k;
vector<int> g[N];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			int u,v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
	}
	return 0;
}
