#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+10;
int n,m,k;
int vlg[50],dis[maxn];
struct node{
	int v,cost;
};
vector<node>G[maxn]

int main(){
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<maxn;i++){
		dis[i]=1e9+10;
	}
	for(int i=1;i<=m;i++){
		int x,y,z;
		cin>>x>>y>>z;
		G[x].push_back{y,z};
		G[y].push_back{x,z};
	}
	cout<<0;
	dij(1,0);
	return 0;
}
