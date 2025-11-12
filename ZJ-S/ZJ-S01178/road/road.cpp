#include<bits/stdc++.h>
using namespace std;
long long n,m,k,ans=1e18;
struct node{
	long long u,v,w;
}e[2000001],tmpe[2000001];
int fa[100015];
int dis[15][10001];
int c[10001];
int vis[10001];
bool cmp(node a,node b){
	return a.w<b.w;
}
int find(int x){
	return (fa[x]==x?x:fa[x]=find(fa[x]));
}
void solve1(){
	long long u,v,w;
	for(int i=1;i<=n;i++) fa[i]=i;
	for(int i=1;i<=m;i++){
		scanf("%lld%lld%lld",&e[i].u,&e[i].v,&e[i].w);
	}
	sort(e+1,e+m+1,cmp);
	for(int i=1;i<=m;i++){
		int tx=find(e[i].u),ty=find(e[i].v);
		if(tx!=ty){
			ans+=e[i].w;
			fa[tx]=ty;
		}
	}
	cout<<ans<<'\n';
	return;
}
void dfs(int step,int bian,int sum){
	if(step==k+1){
//		cout<<step<<" "<<bian<<" "<<sum<<'\n';
		for(int i=1;i<=m;i++) tmpe[i]=e[i];
		for(int i=1;i<=k;i++){
			if(vis[i]==1) for(int j=1;j<=n;j++){
				tmpe[++bian].u=j;
				tmpe[bian].v=n+i;
				tmpe[bian].w=dis[i][j];
			}
		}
		long long tt=sum;
		sort(tmpe+1,tmpe+bian+1,cmp);
		for(int i=1;i<=n+k;i++) fa[i]=i;
		for(int i=1;i<=bian;i++){
			int tx=find(tmpe[i].u),ty=find(tmpe[i].v);
			if(tx!=ty){
				tt+=tmpe[i].w;
				fa[tx]=ty;
			}
		}
		ans=min(ans,tt);
//		cout<<tt<<" "<<ans<<'\n'<<'\n';
		return;
	}
	dfs(step+1,bian,sum);
	vis[step]=1;
	dfs(step+1,bian,sum+c[step]);
	vis[step]=0;
}
void solve2(){
	for(int i=1;i<=m;i++){
		scanf("%lld%lld%lld",&e[i].u,&e[i].v,&e[i].w);
	}
	for(int i=1;i<=k;i++){
		scanf("%lld",&c[i]);
		for(int j=1;j<=n;j++) scanf("%lld",&dis[i][j]);
	}
	dfs(1,m,0);
	cout<<ans<<'\n';
	return;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&k);
	if(k==0){
		solve1();
		return 0;
	}
	if(m<=100000){
		solve2();
		return 0;
	}
		for(int i=1;i<=m;i++){
		scanf("%lld%lld%lld",&e[i].u,&e[i].v,&e[i].w);
	}
	for(int i=1;i<=k;i++){
		scanf("%lld",&c[i]);
		for(int j=1;j<=n;j++) scanf("%lld",&dis[i][j]);
	}
	for(int i=1;i<=k;i++){
		for(int j=1;j<=n;j++){
			e[++m].u=j;
			e[++m].v=n+i;
			e[++m].w=dis[i][j];
		}
	}
	sort(e+1,e+m+1,cmp);
	for(int i=1;i<=n+k;i++) fa[i]=i;
	ans=0;
	for(int i=1;i<=m;i++){
		int tx=find(e[i].u),ty=find(e[i].v);
		if(tx!=ty){
			ans+=e[i].w;
			fa[tx]=ty;
		}
	}
	cout<<ans<<endl;
	return 0;
}
//natural water of boneau