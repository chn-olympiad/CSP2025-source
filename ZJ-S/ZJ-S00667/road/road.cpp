#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e4+3,M=1e6+3,D=1e3+3;
int n,m,k,ans;
struct Edge{
	int u,v,w;
}a[M];
bool cmp(Edge a,Edge b){
	return a.w<b.w;
}
int fa[N];
int find(int x){
	return (x==fa[x])?x:(fa[x]=find(fa[x]));
}
void Main1(){
	for (int i=1;i<=n;i++) fa[i]=i;
	for (int i=1;i<=m;i++){
		cin>>a[i].u>>a[i].v>>a[i].w;	
	}
	sort(a+1,a+m+1,cmp);
	for (int i=1,j=1;i<=m && j<n;i++){
		if (find(a[i].u)!=find(a[i].v)){
			j++;
			fa[find(a[i].u)]=find(a[i].v);
			ans+=a[i].w;
		}
	}
	cout<<ans;
}
int d[D][D],dist[D],g[D][D];
int c[10],b[10][D];
int vis[D];
void Main2(){
	int ans=1e18;
	memset(g,0x3f,sizeof(g));
	for (int i=1;i<=n;i++) g[i][i]=0;
	for (int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		g[u][v]=g[v][u]=min(g[u][v],w);
	}
	for (int i=0;i<k;i++){
		cin>>c[i];
		for (int j=1;j<=n;j++) cin>>b[i][j];
	}
	for (int i=0;i<(1<<k);i++){
		int res=0;
		for (int j=1;j<=n;j++) for (int p=1;p<=n;p++) d[j][p]=g[j][p];
		for (int v=0;v<k;v++){
			if (!(i>>v&1)) continue;
			res+=c[v];
			
//			cout<<v<<" ";
			
			for (int j=1;j<=n;j++){
				for (int p=1;p<=n;p++){
					d[j][p]=min(d[j][p],b[v][j]+b[v][p]);
				}
			}
		}
		if (res>=ans) continue;
		
//		cout<<"\n";
//		for (int j=1;j<=n;j++){
//			for (int p=1;p<=n;p++){
//				cout<<d[j][p]<<" "; 
//			}
//			cout<<"\n";
//		}
		for (int j=1;j<=n;j++) dist[j]=d[1][j],vis[j]=0;
		vis[1]=1;
		for (int t=1;t<n;t++){
			int mn=-1;
			for (int j=1;j<=n;j++){
				if (!vis[j] && (mn==-1 || dist[j]<dist[mn])){
					mn=j;
				}
			}
			res+=dist[mn]; vis[mn]=1;
			if (res>=ans) break;
			for (int j=1;j<=n;j++){
				dist[j]=min(dist[j],d[mn][j]);
			}
		}
//		cout<<res<<"\n";
		ans=min(ans,res);
	}
	cout<<ans;
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m>>k;
	if (k==0) Main1();
	else Main2();
	return 0;
}

