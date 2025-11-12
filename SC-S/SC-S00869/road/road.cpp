#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define int LL
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9')x=x*10+ch-'0',ch=getchar();
	return x*f;
}
inline void write(int x){
	if(x<0)putchar('-'),x=-x;
	if(x>9)write(x/10);
	putchar('0'+x%10);
}
const int N=1e4+5,M=1e6+5,K=15;
int n,m,k,cnt,hd[N],c[N],fa[N],a[N][N];
struct node{
	int u,v,w;
	bool operator<(const node& x)const{
		return w<x.w;
	}
}e[M*4];
int find(int x){return fa[x]==x?x:fa[x]=find(fa[x]);}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read(),m=read(),k=read();
	for(int i=1;i<=m;++i)e[i].u=read(),e[i].v=read(),e[i].w=read();
	for(int i=1;i<=n;++i)fa[i]=i;
	for(int i=1;i<=k;++i){
		c[i]=read();
		for(int j=1;j<=n;++j)a[i][j]=read();
		for(int u=1;u<=n;++u)for(int v=1;v<=n;++v)if(u!=v)e[++m]=(node){u,v,a[i][u]+a[i][v]};
	}
	sort(e+1,e+m+1);
	int ans=0,ecnt=0;
	for(int i=1;i<=m;++i){
		int fu=find(e[i].u),fv=find(e[i].v);
		if(fu!=fv)fa[fv]=fu,++ecnt,ans+=e[i].w;
		if(ecnt>=n-1)break;
	}
	write(ans);
	return 0;
}