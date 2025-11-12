#include<bits/stdc++.h>
using namespace std;
#define il inline
#define getbit(x,y) (((x)>>(y))&1)
#define lowbit(x) ((x)&(-x))
#define mkp make_pair
#define fi first
#define se second
#define N 10005
#define M 1000005
#define K 13
typedef long long ll;
typedef double db;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef __int128 i128;
typedef unsigned uint;
const int inf=0x3f3f3f3f;
il ll read() {
	ll x=0;bool f=1;char c=getchar();
	while(!isdigit(c)) {if(c=='-')f=0;c=getchar();}
	while(isdigit(c)) {x=(x<<3)+(x<<1)+(c^48);c=getchar();}
	return f?x:-x;
}
struct Edge {
	int u,v,w;
	Edge(int _u=0,int _v=0,int _w=0):u(_u),v(_v),w(_w){}
	bool operator <(const Edge &b)const {return w<b.w;}
};
int n,m,k;
Edge E[M<<1],E2[M<<1],E3[N];
ll fa[N],h[N],minn[N];
il int findf(int x) {return x==fa[x]?x:fa[x]=findf(fa[x]);}
il bool Union(int x,int y) {
	x=findf(x),y=findf(y);
	if(x==y) return 0;
	if(h[x]>h[y]) swap(x,y);
	fa[x]=y,h[y]+=(h[x]==h[y]);
	return 1;
}
il ll kruskal(int nn,int mm,bool sp=0) {
	int cnt=nn-1,p=1,q=1,l=m;ll sum=0,tmp=0;
	for(int i=1;i<=nn;++i) fa[i]=i,h[i]=1;
	if(!sp) l=n-1;
	while(cnt!=0) {
		Edge now;
		if(p==l+1) now=E2[q++];
		else if(q==mm+1) now=E[p++];
		else {
			if(E[p].w<E2[q].w) now=E[p++];
			else now=E2[q++];
		}
		bool flg=Union(now.u,now.v);
		if(flg) {
			sum+=now.w,--cnt;
			if(sp) E3[++tmp]=now;
		}
	}
	return sum;
}
ll c[K],a[K][N],val[N],ans;
int main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read(),m=read(),k=read();
	for(int i=1,u,v,w;i<=m;++i) {
		u=read(),v=read(),w=read();
		E[i]=Edge(u,v,w);
	}
	sort(E+1,E+m+1);
	ans=kruskal(n,0,1);
	for(int i=1;i<n;++i) E[i]=E3[i];
	for(int _=0;_<k;++_) {
		c[_]=read();
		int mpos=0;a[_][0]=inf;
		for(int i=1;i<=n;++i) {
			a[_][i]=read();
			if(a[_][i]<a[_][mpos]) mpos=i;
		}
//		c[_]+=a[_][mpos];
//		a[_][mpos]=0;
	}
	for(int S=1;S<(1<<k);++S) {
		int mm=0,tot=0;
		ll sum=0;
		for(int j=0;j<k;++j) {
			if(getbit(S,j)) {
				sum+=c[j];
				++tot;
				for(int i=1;i<=n;++i) E2[++mm]=Edge(n+tot,i,a[j][i]);
			}
		}
		sort(E2+1,E2+mm+1);
		ans=min(ans,sum+kruskal(n+tot,mm));
	}
	printf("%lld\n",ans);
	return 0;
}

