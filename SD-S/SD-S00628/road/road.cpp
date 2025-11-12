#include<cstdio>
#include<iostream>
#include<vector>
#include<queue>
#include<cmath>
using namespace std;
const int N=1e3+100;
long long e[N][N];
bool vis[N];
int n,m,k;
int sz[N];
long long c[15],a[15][N];
long long ans=-1,lans,anss=-1;
void dfs(int u,int fa,long long sum,int cnt){
	if(cnt==n){
		if(ans==-1) ans=sum;
		else ans=min(ans,sum);
		return;
	}
	if(ans!=-1&&sum>=ans) return;
	vis[u]=true;
	for(int v=1;v<=n;v++){
		if(vis[v]||e[u][v]==-1) continue;
		dfs(v,u,sum+e[u][v],cnt+1);
	}
	vis[u]=false;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=n+k;i++)
		for(int j=1;j<=n+k;j++)
			e[i][j]=-1;
	for(int i=1;i<=m;i++){
		int u,v; long long w;
		scanf("%d%d%lld",&u,&v,&w);
		e[u][v]=e[v][u]=w;
	}
	for(int i=1;i<=k;i++){
		scanf("%lld",&c[i]);
		for(int j=1;j<=n;j++) scanf("%lld",&a[i][j]);
	}
	dfs(1,0,0,1);
	anss=ans;
	for(int i=0;i<1<<k;i++){
		int x=i,cnt=1;
		lans=0;
		while(x){
			if(x%2==1){
				lans+=c[cnt];
				for(int j=1;j<=n;j++){
					e[cnt+n][j]=e[j][cnt+n]=a[cnt][j];
				}
			}
			x>>=1;
			cnt++;
		}
		ans=-1;
		dfs(1,0,0,1);
		if(anss==-1) anss=ans+lans;
		else anss=min(anss,ans+lans);
		for(int i=n+1;i<=n+k;i++){
			for(int j=1;j<=n+k;j++) e[i][j]=e[j][i]=-1;
		}
	}
	printf("%lld\n",anss);
	return 0;
}
