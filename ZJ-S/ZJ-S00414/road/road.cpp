#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e4+25,M=1e6+5,K=15;
int n,m,k,c[K],a[K][N];
struct edge{
	int x,y,w;
}e[M],E[M];
bool cmp(edge x,edge y){
	return x.w<y.w;
}
int fa[N];
int get(int x){
	if(x==fa[x]) return x;
	return fa[x]=get(fa[x]);
}
ll ans=1e18,res;
bool vis[M];
void mst(int n_,int m){
	sort(e+1,e+m+1,cmp);
	for(int i=1;i<=n+k;i++) fa[i]=i;
	int cnt=0;
	for(int i=1;i<=m;i++){
		int x=e[i].x,y=e[i].y,w=e[i].w;
		x=get(x),y=get(y);
		if(x!=y){
			cnt++,fa[x]=y,res+=w,vis[i]=1;
			if(res>=ans) return;
			if(cnt==n_-1) break;
		}
	}
	ans=min(ans,res);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++) scanf("%d%d%d",&e[i].x,&e[i].y,&e[i].w);
	for(int i=1;i<=k;i++){
		scanf("%d",&c[i]);
		for(int j=1;j<=n;j++) scanf("%d",&a[i][j]);
	}
	mst(n,m);int ct=0;
	for(int i=1;i<=m;i++) if(vis[i]) ++ct,E[ct]=e[i];
	for(int S=1;S<(1<<k);S++){
		res=0,ct=n-1;int num=n;
		for(int i=1;i<=k;i++){
			if(S>>(i-1)&1){
				res+=c[i],num++;
				for(int j=1;j<=n;j++) E[++ct]={i+n,j,a[i][j]};
			}
		}
		for(int i=1;i<=ct;i++) e[i]=E[i];
		mst(num,ct);
	}
	printf("%lld\n",ans);
	return 0;
}