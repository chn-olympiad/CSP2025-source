#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e4+5,M=1e6+5;
int n,m,u,v,w,c[15],a[15][N];short k;bool vis[M],visc[15];ll r[N][N],ans=1e18;
void dfs(int now,int s1,ll sum){
	if(s1==n){
		ans=min(ans,sum);
		return;
	}
	for(int i=1;i<=n;i++)
		if(!vis[i]){
			vis[i]=1,dfs(i,s1+1,sum+r[now][i]);
			for(int j=1;j<=k;j++)
				if(visc[j])
					dfs(i,s1+1,sum+a[j][now]+a[j][i]);
				else
					visc[j]=1,dfs(i,s1+1,sum+a[j][now]+a[j][i]+c[j]),visc[j]=0;
			vis[i]=0;
		}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d %d %hd",&n,&m,&k),memset(r,0x3f,sizeof(r));
	for(int i=1;i<=m;i++)
		scanf("%d %d %d",&u,&v,&w),r[u][v]=r[v][u]=w;
	for(int j=1;j<=k;j++){
		scanf("%d",&c[j]);
		for(int i=1;i<=n;i++)
			scanf("%d",&a[j][i]);
	}
	for(int i=1;i<=n;i++)
		vis[i]=1,dfs(i,1,0),vis[i]=0;
	printf("%lld",ans);
	return 0;
}