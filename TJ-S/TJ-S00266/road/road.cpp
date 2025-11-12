#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e4+5,M=1e6+5,mod=1e9+7;
int n,m,k,cnt,tot,nn,ans,w[11],a[11][N],fa[N];
struct edge{
	int u,v,w;
}e[M],g[M<<3],gg[M];
inline int read(){int x(0),f(1);char ch=getchar();for(;!isdigit(ch);ch=getchar())if(ch=='-') f=-1;for(;isdigit(ch);ch=getchar())x=(x<<1)+(x<<3)+(ch^48);return x*f;}
int find(int x){return fa[x]==x?x:fa[x]=find(fa[x]);}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
//	int cc=clock();
	n=read(),m=read(),k=read();
	for(int i=1;i<=n;i++) fa[i]=i;
	for(int i=1;i<=m;i++){
		e[i].u=read(),e[i].v=read(),e[i].w=read();
	}
	for(int i=1;i<=k;i++){
		w[i]=read();
		for(int j=1;j<=n;j++) a[i][j]=read();
	}
	sort(e+1,e+m+1,[](edge a,edge b){return a.w<b.w;});
	for(int i=1;i<=m;i++){
		if(find(e[i].u)!=find(e[i].v)){
			fa[find(e[i].u)]=find(e[i].v);
			ans+=e[i].w;
			gg[++cnt]=e[i];
		}
	}
//	printf("%lld ",ans);
	for(int i=1;i<(1<<k);i++){
		tot=cnt;
		nn=n;
		int res=0;
		for(int i=1;i<=cnt;i++) g[i]=gg[i];
		for(int j=1;j<=k;j++) if((1<<(j-1))&i){
			nn++;
			for(int k=1;k<=n;k++){
				g[++tot].u=k,g[tot].v=nn,g[tot].w=a[j][k];
			}
			res+=w[j];
		}
		for(int i=1;i<=nn;i++) fa[i]=i;
		sort(g+1,g+tot+1,[](edge a,edge b){return a.w<b.w;});
		int count=nn-1;
		for(int i=1;i<=tot;i++){
			if(find(g[i].u)!=find(g[i].v)){
				fa[find(g[i].u)]=find(g[i].v);
				res+=g[i].w;
				if(res>ans){res=2e18;break;}
				count--;
				if(!count) break;
			}
		}
		ans=min(ans,res);
//		printf("%d ",tot);
//		printf("%lld %lld %lld\n",i,ans,res);
	}
	printf("%lld",ans);
//	printf("\n%d",clock()-cc);
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

*/
