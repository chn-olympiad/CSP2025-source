#include<bits/stdc++.h> 
#define ll long long
#define N 10025
#define M 1000005
using namespace std;
int n,m,k;
int vis[N];
int cnt;
struct node{
	int u,v;
	int w;
};
node edge[M*3];
bool cmp(node a,node b){
	return a.w<b.w;
}
ll sum;
int c[15];
int d[15];
int a[15][10005];
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;++i){
		int u,v,w;
		++cnt;
		scanf("%d%d%d",&edge[cnt].u,&edge[cnt].v,&edge[cnt].w);
//		addedge(u,v,w);
	} 
//	for(int i=1;i<=k;++i){
//		int id=n+i;
//		scanf("%d",&c[id]);
//		int nw=0;
//		for(int j=1;j<=n;++j){
//			int w;
//			scanf("%d",&w);
//			if(w==0)nw=j;
//			a[i][j]=w;
//		}
//		for(int j=1;j<=n;++j){
//			if(j==nw)continue;
//			edge[++cnt].u=nw;
//			edge[cnt].v=j;
//			edge[cnt].w=a[i][j];
//		}
//	}
//	cout<<cnt<<endl;
	sort(edge+1,edge+m+1,cmp);
	for(int i=1;i<=m;++i){
		if(vis[edge[i].u]&&vis[edge[i].v])continue;
		sum+=edge[i].w;
//		if(edge[i].u>n)d[edge[i].u-n]=edge[i].w-c[edge[i].u];
//		if(edge[i].v>n)sum-=c[edge[i].v],d[edge[i].v-n]=edge[i].w-c[edge[i].v];
//		cout<<sum<<endl;
		++vis[edge[i].u];
		++vis[edge[i].v];
	}
	printf("%lld",sum);
	return 0;
}
