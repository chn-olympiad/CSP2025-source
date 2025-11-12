#include<bits/stdc++.h>
#define MAXN 10050
#define MAXM 1000050 
#define MAXK 10
using namespace std;

int head[MAXM],fa[MAXN];
bool vis[MAXN];
int n,m,k,tot=0,ans=0;
int c[MAXK][MAXN];//c[k][0]表示对应城市化费用 
struct Edge{
	int from;
	int to,next,w;
}edge[MAXM*2];

bool cmp(Edge a,Edge b){
	return a.w<b.w;
}

void add_edge(int a,int x,int y,int z){
	edge[++tot].to=y;
	edge[tot].w=z;
	edge[tot].next=head[x];
	head[x]=tot;
	edge[tot].from =a;
}

int find(int x){
	if(fa[x]==x)return x;
	return fa[x]=find(fa[x]);
}

void bfs1(int x){
	queue<int> q;
	q.push(x);
	
	while(!q.empty()){
		int tmp=q.front();
		vis[tmp]=1;
		q.pop();
		for(int i=head[tmp];i;i=edge[i].next){
			
			int u=edge[i].to;
			int x=find(edge[tmp].to),y=find(u);
			if(vis[u])continue;
			q.push(u);vis[u]=1;
			if(x!=y){
			fa[x]=y;
			}
		
		}
	}
}
	
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int x,y,z;
		cin>>x>>y>>z;
		add_edge(x,x,y,z);
		add_edge(y,y,x,z);
	}
	for(int i=1;i<=k;i++){
		for(int j=0;j<=n;j++)cin>>c[k][j];
	}
	
	for(int i=1;i<=n;i++)fa[i]=i;
	memset(vis,0,sizeof(vis));
	bfs1(1);
	sort(edge+1,edge+m+1,cmp);
	
	for(int i=1;i<=m;i++){
		int x=find(edge[i].from),y=find(edge[i].to);
		if(x==y){
		ans+=edge[i].w;
		}
		
	}
	cout<<ans;
	return 0;
} 