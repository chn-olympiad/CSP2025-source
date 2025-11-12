#include<bits/stdc++.h>
using namespace std;
int n,m,k;
struct node{
	int v,w;
};
vector<node>ve[100005];
int a[15][100005];
int cnt;
int res;
int dis[100005];
int vis[100005];
void prim(){
	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;
	memset(dis,0x3f,sizeof dis);
	dis[1]=0;
	q.push({0,1});
	while(!q.empty()){
		int u=q.top().second;
		int ww=q.top().first;
		q.pop();
		if(vis[u])continue;
		vis[u]=1;
		cnt++;
		if(cnt==n+1)break;
		res+=ww;
		for(int i=0;i<ve[u].size();i++){
			int v=ve[u][i].v;
			int w=ve[u][i].w;
			if(dis[v]>w){
				dis[v]=w;
				q.push({w,v});
			}
		}
	}
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int a,b,c;
		cin>>a>>b>>c;
		ve[a].push_back({b,c});
		ve[b].push_back({a,c});
	}
	int flag=0;
	for(int i=1;i<=k;i++){
		for(int j=1;j<=n+1;j++){
			cin>>a[i][j];
			if(a[i][j]!=0){
				flag=1;
			}
		}
	}
	if(flag==0){
		cout<<0;
		return 0;
	}
	prim();
	cout<<res;
	return 0;
}