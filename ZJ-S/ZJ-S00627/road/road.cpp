#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int maxn=1e4+5,maxm=1e6+5;
int n,m,k,fa[maxn+10],c[maxn];
ll ans;
struct Miku{
	int x,y,z;
	inline bool operator <(const Miku &B)const{return z<B.z;}
}e[maxm],C[maxm],E[11][maxn];
inline int read(){
	int ret=0,f=1;
	char c=getchar();
	while(!isdigit(c)){if(c=='-')f=-f;c=getchar();}
	while(isdigit(c)){ret=ret*10+(c&15);c=getchar();}
	return ret*f;
}
inline int getfa(int x){return fa[x]==x?x:fa[x]=getfa(fa[x]);}
inline void solve(int l,int r){
	if(l>=r)return;
	int mid=l+r>>1;
	solve(l,mid),solve(mid+1,r);
	int L=(l-1)*n+(l==1),M=mid*n-1,R=r*n-1;
	for(int k=L;k<=R;k++)C[k]=e[k];
	int i=L,j=M+1;
	for(int k=L;k<=R;k++)
		if(i<=M&&(j>R||C[i]<C[j]))e[k]=C[i++];else e[k]=C[j++];
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read(),m=read(),k=read();
	for(int i=1;i<=m;i++)e[i].x=read(),e[i].y=read(),e[i].z=read();
	for(int i=1;i<=k;i++){
		c[i]=read();
		for(int j=1;j<=n;j++)E[i][j]={n+i,j,read()};
		sort(E[i]+1,E[i]+n+1);
	}
	sort(e+1,e+m+1),iota(fa+1,fa+n+1,1);int cnt=0;
	for(int i=1;i<=m;i++){
		int fx=getfa(e[i].x),fy=getfa(e[i].y);
		if(fx==fy)continue;
		fa[fx]=fy,ans+=e[i].z,E[0][++cnt]=e[i];
	}
	for(int s=1;s<1<<k;s++){
		ll cst=0;
		for(int i=0;i<k;i++)
			if(s&1<<i)cst+=c[i+1];
		if(cst>=ans)continue;
		int tot=0;
		for(int i=1;i<=cnt;i++)e[++tot]=E[0][i];
		for(int i=0;i<k;i++)
			if(s&1<<i)
				for(int j=1;j<=n;j++)e[++tot]=E[i+1][j];
		solve(1,__builtin_popcount(s)+1);
		iota(fa+1,fa+n+k+1,1);
		ll now=cst;
		for(int i=1;i<=tot;i++){
			int fx=getfa(e[i].x),fy=getfa(e[i].y);
			if(fx==fy)continue;
			fa[fx]=fy,now+=e[i].z;
			if(now>=ans)break;
		}
		ans=min(ans,now);
	}
	printf("%lld\n",ans);
	return 0;
}