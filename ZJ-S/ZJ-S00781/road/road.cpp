#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e6+100;
ll n,m,w[N],k,ans,c[100],a[12][10000+100],dis[N],vis[N];
struct node{
	int v;
	int val;
};
vector<node> G[N];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v;cin>>u>>v>>w[i];
		G[u].push_back({v,w[i]});
		G[v].push_back({u,w[i]});
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++)
			cin>>a[i][j];
	}
	sort(w+1,w+n+1);
	for(int i=1;i<=n-1;i++)
		ans+=w[i];
	cout<<ans;
	return 0;
}