#include <bits/stdc++.h>
using namespace std;
struct Edge{
	int u,v,w;
};
int n,m,k,ans,res,cnt;
int vis[10010],a[20][10010];
Edge edge[1000010];
inline bool cmp(Edge x,Edge y){return x.w<y.w;}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for (int i=1;i<=m;++i) cin>>edge[i].u>>edge[i].v>>edge[i].w;
	for (int i=1;i<=k;++i){
		for(int j=0;j<=n;++j) cin>>a[i][j];
	}
	if (k==0){
		sort(edge+1,edge+m+1,cmp);
		ans+=edge[1].w;vis[edge[1].u]=vis[edge[1].v]=1;
		for (int i=3;i<=n;++i){
			for (int j=1;j<=m;++j){
				if (vis[edge[j].u]!=vis[edge[j].v]){
					ans+=edge[j].w;vis[edge[j].u]=vis[edge[j].v]=1;
					break;
				}
			}
		}
		cout<<ans;
	}
	else{
		for (int p=0;p<=(1<<k)-1;++p){
			int pp=p;res=0;cnt=0;
			memset(vis,0,sizeof(vis));
			for (int i=1;i<=k;++i){
				if (pp&1){
					res+=a[i][0];
					for (int i=1;i<=n;++i){
						for (int j=i+1;j<=n;++j){
							edge[++m].u=i;edge[m].v=j;
							edge[m].w=a[pp][i]+a[pp][j];
						}
					}
				}
				pp>>=1;
			}
			sort(edge+1,edge+m+1,cmp);
			res+=edge[1].w;vis[edge[1].u]=vis[edge[1].v]=1;
			for (int i=3;i<=n;++i){
				for (int j=1;j<=m;++j){
					if (vis[edge[j].u]!=vis[edge[j].v]){
						res+=edge[j].w;vis[edge[j].u]=vis[edge[j].v]=1;
						break;
					}
				}
			}
			if(p==0) ans=res;
			else ans=min(ans,res);	
		}
		cout<<ans;
	}
	return 0;
} 
