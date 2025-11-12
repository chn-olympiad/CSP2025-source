#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=1e4+25,M=2e6+5,inf=1e18;
ll u[M],v[M],w[M];
ll n,m,k,sum,ttm,ttn,ans=inf,c[N],a[11][N];
struct edge{ll u,v,w;}e[M];
bool cmp(edge xx,edge yy){return xx.w<yy.w;}
int fa[N],siz[N];
int find(int u){return u==fa[u]?u:fa[u]=find(fa[u]);}
ll solve(int sy){
	sum=0;ttm=m;ttn=n;
	for(int i=1;i<=m;++i)
		e[i]=edge{u[i],v[i],w[i]};
	for(int i=1;i<=k;++i)if((sy>>(i-1))&1){
		e[++ttm]=edge{ttn+1,ttn+2,c[i]};ttn+=2;
		for(int j=1;j<=n;++j)
			e[++ttm]=edge{ttn,j,a[i][j]};
	}
	sort(e+1,e+ttm+1,cmp);
//	printf("%d %lld\n",sy,ttm);
	for(int i=1;i<=ttn;i++)fa[i]=i,siz[i]=1;
	for(int i=1,cnt=ttn;i<=ttm&&cnt>1;++i){
		int u=e[i].u,v=e[i].v;
		int fu=find(u),fv=find(v);
		if(siz[fu]>siz[fv])swap(fu,fv);
		if(fu==fv)continue;
		else{fa[fu]=fv;siz[fv]+=siz[fu];cnt--;sum+=e[i].w;}
	}
	return sum;
}
inline void read(ll &x){
	x=0;
	char c=getchar();
	while(c<'0'||'9'<c)c=getchar();
	while('0'<=c&&c<='9'){
		x=(x<<3)+(x<<1)+(c-48);c=getchar();
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	read(n);read(m);read(k);
	for(int i=1;i<=m;i++){
		read(u[i]);read(v[i]);read(w[i]);
		e[i]=edge{u[i],v[i],w[i]};
	}
	for(int i=1;i<=k;i++){
		read(c[i]);
		for(int j=1;j<=n;j++)read(a[i][j]);
	}
	for(int i=0;i<(1<<k);i++)ans=min(ans,solve(i));
	printf("%lld\n",ans);
	return 0;
}