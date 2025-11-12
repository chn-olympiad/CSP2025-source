#include<bits/stdc++.h>
using namespace std;
const long long maxn=1e3+5,maxm=2e6+5;
long long n,m,k,a[maxn][maxn],b[maxn],sum[maxm],cnt,ans,c[maxn],dis[maxn][maxn],vis[maxn];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie();
	cout.tie();
	cin>>n>>m>>k;
	for(long long i=1;i<n;i++){
		for(long long j=i+1;j<=n;j++){
			a[i][j]=1e18;
		}
	}
	for(long long i=1;i<=m;i++){
		long long u,v,w;
		cin>>u>>v>>w;
		a[u][v]=a[v][u]=w;
	}
	for(long long i=1;i<=k;i++){
		cin>>c[i];
		for(long long j=1;j<=n;j++){
			cin>>b[j];
		}
		for(long long j=1;j<n;j++){
			for(long long l=j+1;l<=n;l++){
				if((c[i]+b[j]+b[l])<a[j][l]){
					a[j][l]=c[i]+b[j]+b[l];
					dis[j][l]=i;
				}
			}
		}
	}
	for(long long i=1;i<n;i++){
		for(long long j=i+1;j<=n;j++){
			if(a[i][j]!=1e18){
				if(dis[i][j]&&!vis[dis[i][j]]){
					vis[dis[i][j]]=1;
					ans+=c[dis[i][j]];
				}
				if(dis[i][j]){
					a[i][j]-=c[dis[i][j]];
				}
				sum[++cnt]=a[i][j];
			}
		}
	}
	sort(sum+1,sum+cnt+1);
	for(long long i=1;i<n;i++){
		ans+=sum[i];
	}
	cout<<ans;
	return 0;
}
