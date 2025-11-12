#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
const int N = 1e4+5,inf = 0x3f3f3f3f3f3f3f3f;
struct node{
	int ne,v,w;
}a[2200005];
int n,m,k,head[N],dis[N][15],tot,viss[N+10];
void add(int u,int v,int w){
	a[++tot].v=v;
	a[tot].w=w;
	a[tot].ne=head[u];
	head[u]=tot;
}
bool vis[N];
typedef pair<int,int>pii;
priority_queue<pii,vector<pii>,greater<pii> >pq;
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		add(u,v,w);
		add(v,u,w);
	}
	vector<int>b(k+n+1);
	for(int i=1;i<=k;i++){
		int x,y;
		cin>>x;
		b[n+i]=x;
		for(int j=1;j<=n;j++){
			cin>>y;
			add(n+1,j,y);
			add(j,n+1,y);
		}
	}
	memset(dis,inf,sizeof dis);
	dis[1][0]=0;
	pq.push({dis[1][0],1});
	while(pq.size()){
		int t=pq.top().second;
		pq.pop();
		if(vis[t]) continue;
		vis[t]=1;
		for(int i=head[t];i;i=a[i].ne){
			int v=a[i].v;
			if(viss[t]==v) continue;
			if(dis[v][0]>a[i].w+b[v]){
				viss[v]=t;
				if(t>n){
					dis[v][t-n]=a[i].w;
					pq.push({dis[v][t-n],v});
				}else{
					dis[v][0]=a[i].w+b[v];
					pq.push({dis[v][0],v});
				}
			} 
		}
	}
	int mn=INT_MAX;
	for(int j=0;j<=k;j++){
		int sum=0;	
		for(int i=1;i<=n;i++) sum+=min(dis[i][0],dis[i][j]);
		for(int i=0;i<=k;i++) mn=min(mn,sum+dis[n+j][i]);
	} 
	cout<<mn;
	return 0;
}
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4
*/