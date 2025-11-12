#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> PII;
const int N=1e4+10,M=1e6+10;
int n,ans,c[20],a[20][N],dist[N],vis[N];
struct node{
	int y,w;
};
vector<node> q[M];
priority_queue<PII,vector<PII>,greater<PII> > p;
void dij(int s){
	memset(dist,0x3f,sizeof dist);
	p.push({0,s});
	dist[s]=0;
	int x,y,w;
	while(!p.empty()){
		PII t=p.top();
		p.pop();
		x=t.second;
		vis[x]=0;
		ans+=t.first;
		for(int i=0;i<q[x].size();i++){
			y=q[x][i].y,w=q[x][i].w;
			if(vis[y]) continue;
			if(dist[y]>dist[x]+w){
				dist[y]=dist[x]+w;
				vis[y]=1;
				p.push({w,y});
			}
		}
	}
	cout<<ans;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int m,k,x,y,w;
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>x>>y>>w;
		q[x].push_back({y,w});
		q[y].push_back({x,w});
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++) cin>>a[i][j];
	}
	dij(1);
	return 0;
}