#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int MAXN=1e7+5;
const int N=1e4+1;
struct edge{
	ll u,v,w;int mid;
}e[MAXN];
int n,m,k;
int f[N];
int a[20][N];
int c[20];
bool use[20][N];
int dis[N][N];
int find(int x){
	if(f[x]==x)return x;
	return f[x]=find(f[x]);
}
bool cmp(edge a,edge b){
	return a.w<b.w;
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)
		f[i]=i;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		e[i]={u,v,w,-1};
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(i==j)continue;
			ll now=1e18;
			int to;
			for(int x=1;x<=k;x++){				
				if(1LL*a[x][i]+a[x][j]+c[x]<now){
					now= 1LL*a[x][i]+a[x][j]+c[x],now;
					to=x;
				}
				e[++m]={i,j,now,to};
			}			
			
		}
	}
	sort(e+1,e+1+m,cmp);
	ll cost=0;
	for(int i=1;i<=m;i++){
		int f1=find(e[i].u),f2=find(e[i].v);
		if(f1==f2){
			if(e[i].mid!=-1&&dis[e[i].u][e[i].v]){
//				int now=c
				int now=-1;
				if(!use[e[i].mid][e[i].u]&&use[e[i].mid][e[i].v])now=a[e[i].mid][e[i].u];
				else if(!use[e[i].mid][e[i].v]&&!use[e[i].mid][e[i].u])now=a[e[i].mid][e[i].v];
				if(now==-1||(!use[e[i].mid][e[i].u]&&!use[e[i].mid][e[i].v]))continue;
				use[e[i].mid][e[i].u]=true;
				use[e[i].mid][e[i].v]=true;
				if(now<dis[e[i].u][e[i].v]){
					cost-=dis[e[i].u][e[i].v];
					cost+=now;
				}
			}
			continue;
		}		
		cost+=e[i].w;		
		f[f1]=f2;
		if(e[i].mid!=-1){
			if(use[e[i].mid][e[i].u])cost-=c[e[i].mid]+a[e[i].mid][e[i].u];
			if(use[e[i].mid][e[i].v])cost-=c[e[i].mid]+a[e[i].mid][e[i].v];
		}
		else {
			dis[e[i].u][e[i].v]=dis[e[i].v][e[i].u]=e[i].w;
		}
		use[e[i].mid][e[i].u]=true;
		use[e[i].mid][e[i].v]=true;
	}
	cout<<cost<<'\n';
	return 0;
}

























