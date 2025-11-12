#include<bits/stdc++.h>
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();
	while(!isdigit(c)){if(c=='-') f=-1;c=getchar();}
	while(isdigit(c)) x=(x<<1)+(x<<3)+(c^48),c=getchar();return x*f;
}
int n,m,k,fa[10005],ans,cnt;
struct Edge{int u,v,w;}e[1000005];
inline bool cmp(Edge x,Edge y){return x.w<y.w;}
inline int find(int x){return fa[x]==x?fa[x]:find(fa[x]);}
signed main(){
	ios::sync_with_stdio(0);cin.tie(0);
	freopen("road.in","r",stdin);freopen("road.out","w",stdout);
	n=read(),m=read(),k=read();
	for(int i=1;i<=m;++i) e[i].u=read(),e[i].v=read(),e[i].w=read();
	sort(e+1,e+1+m,cmp);
	for(int i=1;i<=n;++i) fa[i]=i;
	for(int i=1,j;i<=k;++i) for(j=0;j<=n;++j) read();
	for(int i=1;i<=m;++i){
		if(find(e[i].u)!=find(e[i].v)) ans+=e[i].w,fa[e[i].u]=e[i].v,++cnt;
		if(cnt==n-1) break;
	}
	cout<<ans;
	return 0;
} 
