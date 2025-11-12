#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e3+10,M=1e6+10;
struct node{
	int x,y;
	ll w;
	bool operator<(const node&other) const{
		return w<other.w;
	}
}p[M];
int n,m,k,cnt,f[N];
ll g[N][N],a[N],ans;
int find(int x){
	if(x!=f[x]) f[x]=find(f[x]);
	return f[x];
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	memset(g,0x3f,sizeof g);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=n;i++) f[i]=i;
	while(m--){
		int x,y;
		ll z;
		scanf("%d%d%lld",&x,&y,&z);
		g[x][y]=g[y][x]=min(g[x][y],z);
	}
	while(k--){
		ll x;
		scanf("%lld",&x);
		for(int i=1;i<=n;i++){
			scanf("%lld",&a[i]);
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				g[i][j]=g[j][i]=min(g[i][j],x+a[i]+a[j]);
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			p[++cnt]={i,j,g[i][j]};
		}
	}
	sort(p+1,p+cnt+1);
	for(int i=1;i<=cnt;i++){
		int px=find(p[i].x),py=find(p[i].y);
		if(px!=py){
			f[px]=py;
			ans+=p[i].w;
		}
	}
	printf("%lld",ans);
	return 0;
}
