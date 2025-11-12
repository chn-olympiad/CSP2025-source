//by snakeMC
//now:UAC  1~4 k=0 ~16pts
#include<bits/stdc++.h>
using namespace std;
const int INF=INT_MAX;
int main() {
//	freopen("road.in","r",stdin);
//	freopen("road.out","w",stdout);
	cin.tie(0);
	cout.tie(0);
	int n,m,k;
	cin>>n>>m>>k;
	vector<vector<int> > dis(n+1,vector<int>(n+1,INF));
	for(int i=1; i<=n; i++) {
		dis[i][i]=0;
	}
	int u,v,w;
	for(int i=1; i<=m; i++) {
		cin>>u>>v>>w;
		dis[u][v]=w;
		dis[v][u]=w;
	}
	int c[k+1],a[k+1][n+1];
	for(int i=1; i<=k; i++) {
		cin>>c[i];
		for(int j=1; j<=n; j++) {
			cin>>a[i][j];
		}
	}
	long long cost=0;
	int t;
	for(int i=1; i<=n; i++) {//dang qian wen ti : cun zhuang hui bei chong fu ji suan duo ci
		for(int j=i+1; j<=n; j++) {
			for(int k2=1; k2<=n; k2++) {
				if(i!=j&&j!=k&&i!=k&&dis[i][k2]!=INF&&dis[k2][j]!=INF) {
					t=dis[i][j];
					dis[i][j]=dis[j][i]=min(dis[i][j],dis[i][k2]+dis[k2][j]);
					if(t==INF&&dis[i][j]!=INF)cost+=dis[i][j];
					if(t!=INF)cost=cost-t+dis[i][j];
				}
			}
			for(int k2=1; k2<=k; k2++) {
				t=dis[i][j];
				if(dis[i][j]>a[k2][i]+a[k2][j]+c[k2])dis[i][j]=dis[j][i]=a[k2][i]+a[k2][j]+c[k2];
				if(t==INF&&dis[i][j]!=INF)cost+=dis[i][j];
				if(t!=INF)cost=cost-t+dis[i][j];
			}
		}
	}
	cout<<cost;
//	fclose(stdin);
//	fclose(stdout);
	return 0;
}
