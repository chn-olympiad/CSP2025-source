#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
const int N=1e4+10,K=11;
int g[N][N],ng[N][N],a[K][N],c[K];
int dist[N];
int n,m,k;
bool st[N];

LL prim(){
	memset(dist,0x7f,sizeof(dist));
	memset(st,false,sizeof(st));
	LL res=0;
	//puts("");
	for(int i=0;i<n;++i){
		int t=-1;
		for(int j=1;j<=n;++j){
			if(!st[j]&&(t==-1||dist[j]<dist[t]))
				t=j;
		}
		st[t]=true;
		//printf("t=%d\n",t);
		if(i)res+=(LL)dist[t];
		for(int j=1;j<=n;++j){
			dist[j]=min(dist[j],g[t][j]);
			//cout<<dist[j]<<' ';
		}
		//puts("");
	}
	return res;
}

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);

	scanf("%d%d%d",&n,&m,&k);
	memset(g,0x7f,sizeof(g));
	for(int i=1;i<=n;++i)g[i][i]=0;
	while(m--){
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		g[u][v]=g[v][u]=min(g[u][v],w);
	}

//	for(int i=1;i<=n;++i){
//		for(int j=1;j<=n;++j)cout<<g[i][j]<<' ';
//		puts("");
//	}

	int special=0;
	for(int i=1;i<=k;++i){
		scanf("%d",&c[i]);
		special+=c[i]==0?0:1;
		for(int j=1;j<=n;++j)
			scanf("%d",&a[i][j]);
	}

	if(k==0){
		printf("%lld\n",prim());
		return 0;
	}

	if(special==0){
		// ** c_i=0, for every i.
		for(int i=1;i<=n;++i)
			for(int j=i+1;j<=n;++j)
				for(int p=1;p<=k;++p)
					g[i][j]=g[j][i]=min(g[i][j],a[p][i]+a[p][j]);
		printf("%lld\n",prim());
		return 0;
	}

	LL ans=0x7fffffffffffffff;
	memcpy(ng,g,sizeof(ng));
	for(int i=0;i<(1<<k);++i){
		memcpy(g,ng,sizeof(g));
		LL build=0;
		for(int j=1;j<=k;++j){
			if(((i>>(j-1))&1)==0)continue;
			build+=(LL)c[j];
			for(int u=1;u<=n;++u)
				for(int v=i+1;v<=n;++v)
					g[u][v]=g[v][u]=min(g[u][v],a[j][u]+a[j][v]);
		}
		ans=min(ans,build+prim());
	}
	printf("%lld\n",ans);

	return 0;
}
/*

4 5 0
1 2 100
1 4 6
2 3 7
2 4 5
3 4 4

*/
