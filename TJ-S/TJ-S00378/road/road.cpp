#include<bits/stdc++.h>
#define ll long long 
using namespace std;
/*struct edge{
	ll u,v,w;
};*/
int n,m,k;
ll a[10005][10005];//w
bool vis[10005];
//ll c[15];
ll ans=10000000000000;
void dfs(int now,ll anew,int cnt){
	//cout<<now<<" "<<anew<<" "<<cnt<<endl;
	if(cnt==n){
		ans=min(ans,anew);
		return;
	}
	for(int i=1;i<=n;i++){
		if(vis[i]){
			//cout<<"v"<<i<<endl;
			continue;
		}
		if(a[now][i]==-1){
			//cout<<"n"<<i<<endl;
			continue;
		}
		cnt++;
		vis[i]=1;
		dfs(i,anew+a[now][i],cnt);
		vis[i]=0;
		cnt--;
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	memset(a,-1,sizeof(a));
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		a[u][v]=w;
		//cout<<u<<" "<<v<<" "<<a[u][v]<<endl;
		a[v][u]=a[u][v];
	}
	//for(int i=1;i<=k;i++){
	//}
	vis[1]=1;
	dfs(1,0,1);
	cout<<ans;
	return 0;
}
/*
4 4 0
1 4 6
2 3 7
4 2 5
4 3 4
*/
