#include<bits/stdc++.h>
using namespace std;
int sum,n,m,k,u,v,w,d[15],ans[10015],vis[10015];
bool f;
struct Node{
	int to,c;
};
vector<Node> a[10015];
void dfs(int now,int cost){
	if(ans[now]>cost){
		ans[now]=cost;
	}
	for(int i=0;i<a[now].size();i++){
		if(ans[a[now][i].to]>=cost+a[now][i].c&&vis[a[now][i].to]==0){
			if(a[now][i].to<=n){
				vis[a[now][i].to]=1;
				dfs(a[now][i].to,cost+a[now][i].c);
				vis[a[now][i].to]=0;
			}
			else{
				if(vis[a[now][i].to]==0){
					vis[a[now][i].to]=1;
					dfs(a[now][i].to,cost+a[now][i].c+d[i]);
					vis[a[now][i].to]=0;
				}
			}
		}	
	}
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++){
		ans[i]=1e9;
	}
	for(int i=1;i<=m;i++){
		cin>>u>>v>>w;
		a[u].push_back({v,w});
		a[v].push_back({u,w});
	}
	f=1;
	for(int i=1;i<=k;i++){
		cin>>d[i];
		for(int j=1;j<=n;j++){
			cin>>w;
			a[j].push_back({n+i,w});
			a[n+i].push_back({j,w});
		}
	}
	vis[1]=1;
	dfs(1,0);
	sum=-1;
	for(int i=1;i<=n;i++){
		sum=max(sum,ans[i]);
		cout<<ans[i]<<" ";
	}
	cout<<sum;
	return 0;
}
