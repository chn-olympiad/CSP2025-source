#include<bits/stdc++.h>
using namespace std;
struct node{
	int x,num;
};
int ans=INT_MAX;
int n,m,k;
vector<node> e[1000005];
int c[15];
int a[15][1000005];
bool vis[1000005];
void f(int x,int now,int sum){
	if(x==m-1){
		ans=min(sum,ans);
		return ;
	}
	for(int i=0;i<e[now].size();i++){
		if(vis[e[now][i].x]==0){
			vis[e[now][i].x]=1;
			f(x+1,e[now][i].x,sum+e[now][i].num);
			vis[e[now][i].x]=0;
		}
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		e[u].push_back({v,w});
		e[v].push_back({u,w});
	}
	for(int j=1;j<=m;j++){
		cin>>c[j];
		for(int i=1;i<=m;i++){
			cin>>a[j][i];
		}
	}
	vis[1]=1;
	f(0,1,0);
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
