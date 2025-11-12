#include<bits/stdc++.h>
#define double long double 
//#define int long long 
#define re0 return 0;
#define exf exit(0);
#define mod 10000007
#define M 1000010
#define N 1010
#define min(a,b) (a<b?a:b)
using namespace std;
int id=0;
struct Edge{
	int to,w;
};
//vector<Edge>edge[N];
int edge[N][N];
int n,m,k,a[11][N];
int dist[N];
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
//	ios::sync_with_stdio(0);
//	ios::sync_with_stdio(0);
	cin.tie(0);
	memset(edge,0x3f,sizeof(edge));
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		edge[u][v]=min(edge[u][v],w);
		edge[v][u]=min(edge[v][u],w);
//		edge[u].push_back(((Edge){v,w}));
//		edge[v].push_back(((Edge){u,w}));
	}
	for(int i=1;i<=k;i++){
		cin>>a[i][0];
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
			for(int t=1;t<=j;t++){
				edge[j][t]=min(edge[j][t],a[i][j]+a[i][t]+a[i][0]);
				edge[t][j]=min(edge[t][j],a[i][j]+a[i][t]+a[i][0]);
//				edge[j].push_back(((Edge){t,a[i][j]+a[i][t]+a[i][0]}));edge[t].push_back(((Edge){j,a[i][j]+a[i][t]+a[i][0]}));
			}
		}
	}
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=n;j++){
//			cout<<edge[i][j]<<' ';
//		}
//		cout<<'\n';
//	}
//	for(int i=1;i<=n;i++){
//		for(int j=0;j<edge[i].size();j++){
//			cout<<i<<' '<<edge[i][j].to<<' '<<edge[i][j].w<<'\n';
//		}
//	}
//	cout<<a[1][1]+a[1][2]+a[1][0]<<'\n';
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			for(int k=1;k<=n;k++){
				if(i==j||j==k||i==k) continue;
				if(edge[i][k]+edge[j][k]<edge[i][j]){
					edge[i][j]=edge[i][k]+edge[j][k];
				}
	}
	int ans=INT_MAX;
	for(int i=1;i<=n;i++){
		int maxn=0;
		for(int j=1;j<=n;j++){
			maxn=maxn<edge[i][j]?edge[i][j]:maxn;
		}
		ans=min(ans,maxn);
	}
	re0;	
}

/*
AFO
*/
