#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,k,a[10005],ans,fa[10005],c,tot,sum,t[10005][10005];
struct graph{
	int u,v,w;
}g[30000005];
inline int get(int x){
	if(x==fa[x])	return x;
	return fa[x]=get(fa[x]);
}
inline void merge(int x,int y){
	fa[get(x)]=get(y);
}
bool cmp(graph s,graph t){
	return s.w<t.w;
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout); 
	scanf("%lld%lld%lld",&n,&m,&k);
	tot=m;
	for(int i=1;i<=n;i++)	fa[i]=i;
	for(int i=1;i<=m;i++){
		scanf("%lld%lld%lld",&g[i].u,&g[i].v,&g[i].w);
		t[g[i].u][g[i].v]=g[i].w;
		t[g[i].v][g[i].u]=g[i].w;
	}
	for(int i=1;i<=k;i++){
		scanf("%lld",&c);
		for(int j=1;j<=n;j++){
			scanf("%lld",&a[j]);
			for(int o=j-1;o>=1;o--){
				if(t[j][o]&&t[j][o]<c+a[j]+a[o])	continue;
				++tot;
				g[tot].u=j;
				g[tot].v=o;
				g[tot].w=c+a[j]+a[o];
				t[j][o]=g[tot].w;
				t[o][j]=g[tot].w;
			}
		}
	}
	sort(g+1,g+1+tot,cmp);	
	for(int i=1;i<=tot;i++){
		int x,y;
		x=get(g[i].u);
		y=get(g[i].v);
		if(x==y)	continue;
		sum++;
		merge(x,y);
		ans+=g[i].w;
		if(sum==n-1)	break;
	}
	printf("%lld",ans);
	return 0;
}