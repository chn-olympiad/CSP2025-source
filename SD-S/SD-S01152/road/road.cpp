#include<bits/stdc++.h>
using namespace std;
namespace file_read{
	char ib[1<<25],*ip1=ib,*ip2=ib;
	inline char gc(){
		return (((ip1==ip2&&(ip2=(ip1=ib)+fread(ib,1,1<<24,stdin))),ip1==ip2?EOF:*ip1++));
	}
	inline int read(){//no long long!!!
		int x=0;char c=gc();
		while(c<'0'||c>'9')c=gc();
		while(c>='0'&&c<='9')x=(x<<3)+(x<<1)+(c^'0'),c=gc();
		return x;
	}
}
using namespace file_read;
struct apple{
	int u,v,w;
	bool operator<(const apple &other)const{
		return w<other.w;
	}
}e[1100005];
int fa[10005];
int findfather(int x){
	return x==fa[x]?x:fa[x]=findfather(fa[x]);
}
int c[10005],a[15][10005],p[15][10005],bh[15][10005],xx[10005];
int z[1<<10][10005];
long long h1[10005];
int hd[10005],nxt[20005],dy[20005],tot;
inline void addedge(int u,int v){
	nxt[++tot]=hd[u];hd[u]=tot,dy[tot]=v;
	nxt[++tot]=hd[v];hd[v]=tot,dy[tot]=u;
}
bool ok[10005];
void dfs(int x){
	ok[x]=1;
	for(int i=hd[x];i;i=nxt[i]){
		int y=dy[i];
		if(!ok[y])dfs(y);
	}
}
long long hs;
int XY,S2;
inline void jia(int hb){
	int u=e[hb].u,v=e[hb].v;
	if(ok[u]){
		if(ok[v])return;
		hs+=e[hb].w;z[S2][XY++]=hb;
		dfs(v);
	}else{
		hs+=e[hb].w;z[S2][XY++]=hb;
		if(ok[v]){
			dfs(u);
		}else{
			addedge(u,v);
		}
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n=read(),m=read(),k=read();
	for(int i=1;i<=m;++i){
		e[i].u=read(),e[i].v=read(),e[i].w=read();
	}
	sort(e+1,e+m+1);
	long long he=0;
	for(int i=1;i<=n;++i)fa[i]=i;
	int cnt=0;
	for(int i=1;i<=m;++i){
		int fu=findfather(e[i].u),fv=findfather(e[i].v);
		if(fu==fv)continue;
		fa[fu]=fv;he+=e[i].w;
		z[0][++cnt]=i;
	}
	for(int i=1;i<=k;++i){
		c[i]=read();
		int mn=INT_MAX,wz=0;
		for(int j=1;j<=n;++j){
			a[i][j]=read();p[i][j]=j;
			if(mn>a[i][j])mn=a[i][j],wz=j;
		}
		c[i]+=a[i][wz];a[i][wz]=0;
		sort(p[i]+1,p[i]+n+1,[&](int x,int y){
			return a[i][x]<a[i][y];
		});
		xx[i]=p[i][1];
		for(int j=2;j<=n;++j){
			bh[i][j-1]=++m;
			e[m].u=xx[i],e[m].v=p[i][j],e[m].w=a[i][p[i][j]];
		}
	}
	long long ans=he;
	for(int S=1;S<(1<<k);++S){
		int d=__builtin_ctz(S),SS=S^(1<<d);
		h1[S]=h1[SS]+c[++d];
		tot=0;int y=xx[d];
		memset(ok,0,sizeof(ok));ok[y]=1;
		tot=0;memset(hd,0,sizeof(hd));
		hs=0;int X=1,Y=1;XY=1,S2=S;
		while(X<n&&Y<n){
			int aa=z[SS][X],bb=bh[d][Y];
			if(e[aa].w<e[bb].w)jia(aa),++X;
			else jia(bb),++Y;
		}
		while(X<n)jia(z[SS][X++]);
		while(Y<n)jia(bh[d][Y++]);
		ans=min(ans,h1[S]+hs);
		//z[SS][1~n-1]
		//bh[d][1~n-1]
	}
	printf("%lld\n",ans);
	return 0;
}
