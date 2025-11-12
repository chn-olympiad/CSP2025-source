#include <bits/stdc++.h>
using namespace std;
const int N=10004,M=1000006;
int n,m,k,c,a[15][N],f[N];
long long ans;
struct edge{
	int u,v,w;
}e[M];
inline bool cmp(edge a,edge b){return a.w<b.w;}
inline int find(int x){
	if (x==f[x]) return x;
	f[x]=find(f[x]);
	return f[x];
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for (register int i=1;i<=m;i++)
		scanf("%d%d%d",&e[i].u,&e[i].v,&e[i].w);
	for (register int i=1;i<=k;i++){
		scanf("%d",&c);
		for (register int j=1;j<=n;j++){
			scanf("%d",&a[i][j]);
			for (register int l=1;l<j;l++)
				e[++m].u=j,e[m].v=l,e[m].w=c+a[i][j]+a[i][l];
		}                                          
	}
	sort(e+1,e+1+m,cmp);
	for (register int i=1;i<=n;i++) f[i]=i;
	for (register int i=1;i<=m;i++){
		edge p=e[i];
		int x=find(p.u),y=find(p.v);
		if (x==y) continue;
		f[x]=y;
		find(p.v);
		ans+=(long long)p.w;
	}
	printf("%lld",ans);
	return 0;
}