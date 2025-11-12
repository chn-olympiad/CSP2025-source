#include<bits/stdc++.h>
#define int long long
#define rg register
#define gc getchar
#define pc putchar
using namespace std;
const long long inf=1e18;
namespace IO{
	inline int read(){
		int x=0,f=1;
		char ch=gc();
		while(!isdigit(ch)){
			if(ch=='-') f=-f;
			ch=gc();
		}
		while(isdigit(ch)) x=(x<<3)+(x<<1)+ch-'0',ch=gc();
		return x*f;
	}
	inline void write(int x){
		if(x<0) pc('-'),x=-x;
		if(x>9) write(x/10);
		pc(x%10+'0');
	}
}using namespace IO;
const int N=1e4+10;
const int M=2e6+10;
const int K=15;
struct edge{
	int u,v,w;
}e[M],g[M];
inline bool cmp(edge x, edge y){return x.w<y.w;}
bool vis[M];
int pos[N*K],c[K];
int n,m,k,tot,fa[N+K],h[N+K];
inline int find(int x){return (x==fa[x])?fa[x]:fa[x]=find(fa[x]);}
inline int Ruby(){
	sort(e+1,e+1+m,cmp);
	for(rg int i=n+1;i<=n+k;i++) vis[i]=0;
	for(rg int i=1;i<=n+k;i++) fa[i]=i,h[i]=1;
	int res=0,cnt=0;
	for(rg int i=1;i<=m;i++){
		if(!vis[e[i].u])continue;
		int fu=find(e[i].u),fv=find(e[i].v);
		if(fu^fv){
			if(h[fu]>h[fv]) swap(fu,fv);
			fa[fu]=fv,h[fv]=max(h[fv],h[fu]+1);
			res+=e[i].w,cnt++,g[++tot]={e[i].u,e[i].v,e[i].w};
		}
		if(cnt==n-1) break;
	}
	return res;
}
inline int MST(int S){
	int res=0,num=0;
	for(rg int i=0;i<k;i++){
		if(S&(1<<i)) vis[i+1+n]=1,num++,res+=c[i+1];
		else vis[i+1+n]=0;
	}
	for(rg int i=1;i<=n+k;i++) fa[i]=i,h[i]=1;
	int cnt=0;
	for(rg int i=1;i<=tot;i++){
		if(!vis[g[i].u]) continue;
		int fu=find(g[i].u),fv=find(g[i].v);
		if(fu^fv){
			if(h[fu]>h[fv]) swap(fu,fv);
			fa[fu]=fv,h[fv]=max(h[fv],h[fu]+1);
			res+=g[i].w,cnt++;
		}
		if(cnt==n+num-1) break;
	}
	return res;
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read(),m=read(),k=read();
	for(rg int i=1;i<=n+k;i++) vis[i]=1;
	for(rg int i=1;i<=m;i++) e[i].u=read(),e[i].v=read(),e[i].w=read();
	for(rg int i=1;i<=k;i++){
		c[i]=read();
		for(rg int j=1;j<=n;j++){
			int w=read();
			g[++tot]=e[++m]={i+n,j,w};
		}
	}
	int ans=Ruby();
//	write(ans),puts("");
	sort(g+1,g+1+tot,cmp);
	for(rg int S=1;S<(1<<k);S++){
		int res=MST(S);
		ans=min(ans,res);
	}
	write(ans);
	return 0;
}
