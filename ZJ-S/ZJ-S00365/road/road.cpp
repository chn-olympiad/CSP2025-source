#include<bits/stdc++.h>
using namespace std;
const int N=1e3+5;
const int K=15;
int va[N][N],v0[N][N];
bool vis[K];
int c[K],a[K][N];
int n,k;
long long ans=1e18;
void dfs(int q){
	if(q>k){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				va[i][j]=v0[i][j];
			}
		}
		long long sum=0;
		for(int i=1;i<=k;i++){
			if(vis[i]){
				sum+=c[i];
				for(int j=1;j<=n;j++){
					for(int l=1;l<=n;l++){
						va[j][l]=min(va[j][l],a[i][j]+a[i][l]);
					}
				}
			}
		}
		for(int i=1;i<n;i++){
			int mn=2e9;
			for(int j=i+1;j<=n;j++){
				mn=min(va[i][j],mn);
			}
			sum+=mn;
		}
		ans=min(ans,sum);
		return ;
	}
	vis[q]=0;
	dfs(q+1);
	vis[q]=1;
	dfs(q+1);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int m;
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			v0[i][j]=2e9;
			va[i][j]=2e9;
		}
	}
	while(m--){
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		va[u][v]=min(va[u][v],w);
		va[v][u]=min(va[v][u],w);
		v0[u][v]=va[u][v];
		v0[v][u]=va[v][u];
	}
	for(int i=1;i<=k;i++){
		scanf("%d",&c[i]);
		for(int j=1;j<=n;j++){
			scanf("%d",&a[i][j]);
		}
	}
	if(k==0){
		ans=0;
		for(int i=1;i<n;i++){
			int mn=2e9;
			for(int j=i+1;j<=n;j++){
				mn=min(mn,va[i][j]);
			}
			ans+=mn;
		}
		printf("%lld",ans);
		return 0;
	}
	dfs(1);
	printf("%lld",ans);
	return 0;
}
