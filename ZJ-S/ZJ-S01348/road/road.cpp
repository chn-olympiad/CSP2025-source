#include<bits/stdc++.h>
using namespace std;
int n,m,k,f[20001],l,vis[11];
struct edge{
	int u,v,bj;
	long long w;
}g[10000001],g1[10000001];
long long a[11],res=1e18;
bool cmp(edge a,edge b){
	return a.w<b.w;
}
int find(int x){
	if(f[x]==x){
		return x;
	}
	return f[x]=find(f[x]);
}
long long kruskal(){
	sort(g+1,g+l+1,cmp);
	for(int i=1;i<=n+k;i++){
		f[i]=i;
	}
	long long ans=0;
	int cnt=0;
	for(int i=1;i<=l;i++){
		int u=g[i].u,v=g[i].v,bj=g[i].bj;
		long long w=g[i].w;
		if(cnt==n-1){
			break;
		}if(find(u)!=find(v)){
			if(bj&&!vis[bj]){
				continue;
			}
			f[u]=f[v];
			if(bj&&vis[bj]){
				for(int j=i+1;j<=l;j++){
					if(g[j].bj==bj){
						g[j].bj=0;
						g[j].w-=a[bj];
					}
				}
				g[i].bj=0;
				sort(g+i+1,g+l+1,cmp);
				n++;
			}else{
				cnt++;
			}
			ans+=w;
		}
	}
	return ans;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++){
		scanf("%d%d%lld",&g1[i].u,&g1[i].v,&g1[i].w);
		g1[i].bj=0;
	}
	l=m;
	for(int i=1;i<=k;i++){
		scanf("%lld",&a[i]);
		for(int j=1;j<=n;j++){
			l++;
			scanf("%lld",&g1[l].w);
			g1[l].u=n+i;
			g1[l].v=j;
			g1[l].bj=i;
			g1[l].w+=a[i];
		}
	}
	for(int i=0;i<=(1<<k)-1;i++){
		int j=i,c=1;
		while(j){
			if(j&1){
				vis[c]=1;
			}
			c++;
			j>>=1;
		}
		for(int j=1;j<=l;j++){
			g[j].w=g1[j].w;
			g[j].bj=g1[j].bj;
			g[j].u=g1[j].u;
			g[j].v=g1[j].v;
		}
		res=min(res,kruskal());
	}
	printf("%lld",res);
	return 0;
}
