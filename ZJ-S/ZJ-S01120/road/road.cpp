#include<bits/stdc++.h>
using namespace std;
const int N=1e4+5,INF=N*N;
int n,m,k,u,v,w,a,al,xi,opi,minx;
int x[N],xx[N];
int dp[N][N];
bool _;
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++)
			dp[i][j]=INF;
		x[i]=INF;
	}
	for(int i=1;i<=m;i++){
		cin>>u>>v>>w;
		dp[u][v]=dp[v][u]=w;
		if(u==1)
			x[v]=w;
	}
	xx[++xi]=1;
	while(xi!=n){
		minx=INF;
		for(int i=2;i<=n;i++){
			_=false;
			for(int j=2;j<=xi;j++){
				if(i==xx[j]){
					_=true;
					break;
				}
			}
			if(_)
				continue;
			if(minx>x[i]){
				opi=i;
				minx=x[i];
			}
		}
		al+=minx;
		xx[++xi]=opi;
		for(int i=2;i<=n;i++){
			_=false;
			for(int j=2;j<=xi;j++){
				if(i==xx[j]){
					_=true;
					break;
				}
			}
			if(_)
				continue;
			if(dp[opi][i]!=INF)
				x[i]=min(x[i],dp[opi][i]);
		}
	}
	cout<<al;
	return 0;
}
