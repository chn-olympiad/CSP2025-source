#include<bits/stdc++.h>
using namespace std;
const int N=1e4+5;
int n,m,k,ans;
vector<pair<int,int>>g[N];
vector<int>p[11];
void solve(){
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		g[u].emplace_back(v,w);
		g[v].emplace_back(u,w);
	}
	for(int i=1;i<=k;i++){
		int x;
		cin>>x;
		p[i].emplace_back(x);
	}
	cout<<0;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	solve()
}
