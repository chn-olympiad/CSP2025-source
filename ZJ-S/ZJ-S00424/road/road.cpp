#include<bits/stdc++.h>
#define ll long long
#define M 1000050
#define N 10050
#define K 15
using namespace std;
int fa[N];
int find(int x){
	if(x==fa[x])return x;
	else return fa[x]=find(fa[x]);
}
int merge(int x,int y){
	x=find(x);y=find(y);
	if(x==y)return 0;
	fa[x]=y;
	return 1;
}
struct node{
	int u,v,w;
};
int vis[M];
ll solve(node *edge,int n,int m){
	for(int i=1;i<=m;i++)vis[i]=0;
	for(int i=1;i<=n;i++)fa[i]=i;
	sort(edge+1,edge+m+1,[&](node x,node y){
		return x.w<y.w;
	});
	ll ans=0;
	for(int i=1;i<=m;i++){
		vis[i]=merge(edge[i].u,edge[i].v);
		if(vis[i])ans+=edge[i].w;
	}
	return ans;
}
node edge[M],edge2[M],edge3[M];
int c[K];
int a[K][N];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++){
		scanf("%d%d%d",&edge[i].u,&edge[i].v,&edge[i].w);
	}
	for(int i=1;i<=k;i++){
		scanf("%d",&c[i]);
		for(int j=1;j<=n;j++)scanf("%d",&a[i][j]);
	}
	ll ans=solve(edge,n,m);
	int cnt=0;
	for(int i=1;i<=m;i++){
		if(vis[i])edge2[++cnt]=edge[i];
	}
	for(int s=1;s<(1<<k);s++){
		ll sum=0;
		for(int i=1;i<n;i++){
			edge3[i]=edge2[i];
		}
		cnt=n-1;
		int duo=0;
		for(int i=1;i<=k;i++){
			if((s>>(i-1))&1){
				sum+=c[i];
				duo++;
				for(int j=1;j<=n;j++){
					edge3[++cnt]=node{n+duo,j,a[i][j]};
				}
			}
		}
		ans=min(ans,sum+solve(edge3,n+duo,cnt));
	}
	printf("%lld\n",ans);
	return 0;
}
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4

13
*/