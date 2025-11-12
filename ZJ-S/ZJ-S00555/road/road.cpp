#include<bits/stdc++.h>
using namespace std;

struct node{
	long long u;
	long long v;	
};
long long x,l,r,u,v,w,n,m,k,vis[100005],dis[100005],i;
vector <node> a[10005];
priority_queue <pair<long long,long long>,vector<pair<long long,long long> >,greater<pair<long long,long long> > > q;
void dfs(){
	while(!q.empty()){
		x=q.top().second;
		q.pop();
		if(vis[x]==1){
			continue;
		}
		vis[x]=1;
		for(int j=0;j<a[x].size();j++){
			l=a[x][j].u;
			r=a[x][j].v;
			if(dis[l]>dis[x]+r){
				dis[l]=dis[x]+r;
				q.push({dis[l],l});
			}
		}
	}
	return ;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(i=1;i<=m;i++){
		cin>>u>>v>>w;
		a[u].push_back({v,w});
		a[v].push_back({u,w});
	}
	memset(dis,0x3f3f3f3f,sizeof dis);
	q.push({0,1});
	dis[1]=0;
	dfs();
	cout<<dis[n];
	return 0;
}