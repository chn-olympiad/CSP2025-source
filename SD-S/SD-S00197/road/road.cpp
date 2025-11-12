#include <bits/stdc++.h>
using namespace std;
const int N=1e4+7;
int n,m,k,ans;
int a[N][N],b[N][N],dp[N][N];
int main(){
	memset(a,0x3f,sizeof(a));
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++){
		a[i][i]=0;
	}
	for(int i=1;i<=m;i++){
		int u,v,f;
		cin>>u>>v>>f;
		a[u][v]=f;
		a[v][u]=f;
	}
	for(int i=1;i<=k;i++){
		for(int j=1;j<=n+1;j++){
			cin>>b[i][j];
			ans+=b[i][j]; 
		}
	}
//	for(int k=1;k<=n;k++){
//		for(int i=1;i<=n;i++){
//			for(int j=1;j<=n;j++){
//				a[i][j]=min(a[i][j],a[i][k]+a[k][j]);
//				ans=max(ans,a[i][j]); 
//			}
//		}
//	}
	cout<<ans;
	return 0;
}

