#include<bits/stdc++.h>
#define ll long long 
using namespace std;
const int N=2e3+10;	//其实没开完
const int M=110001; 
ll ans[N][N]; 
int w[M];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	memset(ans,0x3f,sizeof ans);
	int n,m,k,cnt=0;
	ll anss=0;
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v;
		cin>>u>>v>>w[i];
		ans[u][v]=ans[v][u]=w[i];
	}
	for(int i=1;i<=k;i++){
		int c;
		cin>>c;
		for(int j=1;j<=n;j++){	//到第j个城市 
			cin>>w[m+cnt+j];
			ans[i+n][j]=ans[j][i+n]=w[n+cnt+j];
		}
		cnt+=n; 
	}
	for(int i=1;i<=n;i++)
		ans[i][i]=0;
	for(int i=1;i<=n;i++){	//起点
		for(int j=i;j<=n;j++){	//终点 
			for(int x=1;x<=k+n;x++){	//中转点 
				if(ans[i][x]+ans[x][j]<ans[i][j]){
					ans[i][j]=ans[j][i]=ans[i][x]+ans[x][j];
				
				}
			}
	//		cout<<i<<"->"<<j<<":"<<ans[i][j]<<"\n";
			anss+=ans[i][j];	//i到j的最短路径 
		}
	}
	cout<<anss;
}