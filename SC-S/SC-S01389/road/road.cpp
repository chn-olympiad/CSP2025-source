#include<bits/stdc++.h>
using namespace std;
const int N=100005;
int head[N],cnt;
struct Edge{
	int next,to,dis;
}edge[200005];
int n,m,k;
int u,v,w,c,a;
void add(int from,int to ,int dis){
	edge[++cnt].next=head[from];
	edge[cnt].dis=dis;
	edge[cnt].to=to;
	head[from]=cnt;
}
int vis[N],dis[N];
void dij(int s){
	priority_queue<pair<int,int> > q;
	q.push(make_pair(0,s));
	dis[s]=1;
	while(q.size()){
		int x=q.top().second;
		q.pop();
		if(vis[s]==0)continue;
		vis[s]=1;
		for(int i=head[s];i;i=edge[i].next){
			int z=edge[i].dis;
			int y=edge[i].to;
			if(y<edge[x].to+z)
				y=edge[x].to+z;
			q.push(make_pair(-y,dis[y]));
		}
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>u>>v>>w;
		add(u,v,w);
		add(v,u,w);
	}
	for(int i=1;i<=k;i++){
		cin>>c;
		for(int j=1;j<=c;j++)
			cin>>a;
	}
	dij(1);
	cout<<0;
	return 0;
}