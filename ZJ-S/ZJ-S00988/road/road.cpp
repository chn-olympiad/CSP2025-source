#include<bits/stdc++.h>
using namespace std;
long long n,m,k,x,y,w,c[15],a[15][10005],nb;
struct node{
	int t,tt;
};
vector<node> g[100005];/*
void dfs(int x,int num){
	for(int i=0;i<g[x].size();i++){
		if(find(g[x][i]))
	}
}*/
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
//	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
	//	cin>>x>>y>>w;
		scanf("%d%d%d",&x,&y,&w);
		g[x].push_back({y,w});
		g[y].push_back({x,w});
		nb+=w;//
	}
	for(int i=1;i<=k;i++){
		scanf("%d",&c[i]);
	//	cin>>c[i];
	//	for(int j=1;j<=n;j++)cin>>a[i][j];
		for(int j=1;j<=n;j++)scanf("%d",&a[i][j]);
		if(c[i]==0)nb++;
	}
//	for(int i=1;i<=rand();i++)k=k+(rand()%rand())+rand();
	cout<<nb;
	return 0;
}
