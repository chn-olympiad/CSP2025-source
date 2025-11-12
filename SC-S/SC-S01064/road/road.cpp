#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define fi first
#define se second
#define ptc putchar
using namespace std;
const int N=1e4+10;
const int M=2e6+10;
int n,m,k;
int nowm;
struct node{
	int u,v,w;
}e[M];
int c[12];
int a[12][N];
bool vis[12];
int fa[N];
ll ans;
int find(int x){
	if(fa[x]==x) return x;
	return fa[x]=find(fa[x]);
}
void dfs(int now){
	if(now==k+1){
		ll cnt=0;
		int sum=n;
		for(int i=1;i<=k;i++){
			if(vis[i]){
				cnt+=c[i];
				if(cnt>=ans) return;
				++sum;
			}
		}
		for(int i=1;i<=n+k;i++) fa[i]=i;
		int g=1;
		for(int i=1;i<=nowm;i++){
			int x=e[i].u,y=e[i].v;
			if(x>n&&vis[x-n]==0||y>n&&vis[y-n]==0) continue;
			int fx=find(x),fy=find(y);
			if(fx!=fy){
				fa[fx]=fy;
				cnt+=e[i].w;
				++g;
				if(g==sum) break;
				if(cnt>=ans) return;
			}
		}
		ans=min(ans,cnt);
		return;
	}
	vis[now]=0;
	dfs(now+1);
	vis[now]=1;
	dfs(now+1);
	return;
}
bool cmp(node x,node y){
	return x.w<y.w;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++){
		scanf("%d%d%d",&e[i].u,&e[i].v,&e[i].w);
	}
	for(int i=1;i<=k;i++){
		scanf("%d",c+i);
		for(int j=1;j<=n;j++){
			scanf("%d",&a[i][j]);
		}
	}
	for(int i=1;i<=n;i++) fa[i]=i;
	if(!k){
		sort(e+1,e+m+1,cmp);
		for(int i=1;i<=m;i++){
			int fx=find(e[i].u),fy=find(e[i].v);
			if(fx!=fy){
				fa[fx]=fy;
				ans+=e[i].w;
			}
		}
		printf("%lld\n",ans);
	}
	else{
		ans=1e17;
		nowm=m;
		for(int i=1;i<=k;i++){
			for(int j=1;j<=n;j++){
				e[++nowm]={n+i,j,a[i][j]};
			}
		}
		sort(e+1,e+nowm+1,cmp);
		dfs(1);
		printf("%lld\n",ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}