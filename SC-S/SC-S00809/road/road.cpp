#include<bits/stdc++.h>
using namespace std;

const int N=1e4+7,M=1e6+7,inf=1e9+7;
#define int long long
int n,m,k,f[N<<2],rode[N],to[N>>1][N>>1];
bool vis[27];
struct ins{
	int u,v,val;
}edge[M<<2];

bool operator <(const ins &a,const ins &b){
	return a.val<b.val;
}

int find(int x){
	if(f[x]==x)return x;
	else return f[x]=find(f[x]);
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&k);
	if(k==0){
		for(int i=1;i<=n;i++){
			f[i]=i;
		}
		for(int i=1;i<=m;i++){
			int x,y,w;
			scanf("%lld%lld%lld",&x,&y,&w);
			edge[i]={x,y,w};
		}
		sort(edge+1,edge+1+m);
		int ans=0;
		for(int i=1;i<=m;i++){
			int x=find(edge[i].u);
			int y=find(edge[i].v);
			if(x==y)continue;
			f[x]=y;
			ans+=edge[i].val;
		}
		printf("%lld",ans);
	}else{
		int tot=1;
		for(int i=1;i<=n;i++){
			f[i]=i;
			for(int j=1;j<=n;j++){
				to[i][j]=inf;
			}
		}
		for(int i=1;i<=m;i++){
			int x,y,w;
			scanf("%lld%lld%lld",&x,&y,&w);
			to[x][y]=to[y][x]=min(to[x][y],w);
		}
		for(int r=1;r<=k;r++){
			int x;
			scanf("%lld",&x);
			for(int i=1;i<=n;i++){
				scanf("%lld",&rode[i]);
			}
			for(int i=1;i<=n;i++){
				for(int j=i+1;j<=n;j++){
					to[i][j]=to[j][i]=min(to[i][j],rode[i]+rode[j]);
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(to[i][j]!=inf){
					edge[++tot]={i,j,to[i][j]};
				}
			}
		}
		sort(edge+1,edge+1+tot);
		int ans=0;
		for(int i=1;i<=tot;i++){
			int x=find(edge[i].u);
			int y=find(edge[i].v);
			if(x==y)continue;
			f[x]=y;
			ans+=edge[i].val;
		}
		printf("%lld",ans);
	}
	return 0;
}