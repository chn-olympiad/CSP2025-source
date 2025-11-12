#include <bits/stdc++.h>
using namespace std;
int n,m,k;
int u,v;
int head[10005],cnt;
long long c[15];
struct Node1{
	int to;
	int nxt;
	long long w;
	int h;
}edge[12000005];
void addedge(int u,int v,long long w,int h){
	edge[++cnt].to=v;
	edge[cnt].w=w;
	edge[cnt].nxt=head[u];
	edge[cnt].h=h;
	head[u]=cnt;
}
struct Node{
	int v;
	long long dis;
	int h;
	bool operator <(const Node &x)const
	{
		return dis>x.dis;
	}
};
long long dis[10005],ans,a[15][10005],w;
bool vis[10005],ok[15];
priority_queue <Node> q;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++){
		scanf("%d%d%lld",&u,&v,&w);
		addedge(u,v,w,0);
		addedge(v,u,w,0);
	}
	for(int i=1;i<=k;i++){
		scanf("%lld",&c[i]);
		for(int j=1;j<=n;j++){
			scanf("%lld",&a[i][j]);
		}
		for(int y=1;y<=n;y++){
			for(int j=1;j<=n;j++){
				addedge(y,j,a[i][y]+a[i][j]+c[i],i);
			}
		}
	}
	for(int i=1;i<=n;i++)dis[i]=2000000000000000000;
	dis[1]=0;
	Node t;
	t.v=1,t.dis=0,t.h=0;
	q.push(t);
	while(!q.empty()){
		Node now=q.top();
		q.pop();
		u=now.v;
		int h=now.h;
		if(vis[u])continue;
		vis[u]=1;
		ans+=now.dis;
//		cout<<u<<' '<<now.dis<<endl;
		if(h!=0&&!ok[h]){
			for(int i=1;i<=n;i++){
				if(dis[i]>a[h][i]){
					dis[i]=a[h][i];
					t.dis=dis[i];
					t.v=i;
					t.h=h;
					q.push(t);
//					cout<<u<<' '<<t.v<<' '<<t.dis<<endl;
				}
			}
			ok[h]=1;
		}
		for(int i=head[u];i>0;i=edge[i].nxt){
//			if(u==4)cout<<i<<' '<<edge[i].to<<' '<<edge[i].w<<' '<<edge[i].h<<endl;
			v=edge[i].to;
			w=edge[i].w;
//			if(u==4&&i==5)cout<<dis[v]<<' '<<dis[u]+w<<endl;
			if(dis[v]>w){
//				cout<<u<<' '<<v<<' '<<w<<' '<<edge[i].h<<endl;
				dis[v]=w;
				t.dis=dis[v];
				t.v=v;
				t.h=edge[i].h;
				q.push(t);
//				cout<<u<<' '<<t.v<<' '<<t.dis<<endl;
			}
		}
	}
	printf("%lld",ans);
	return 0;
}
