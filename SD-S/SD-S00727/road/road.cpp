#include <bits/stdc++.h>
#define LL long long
#define ULL unsigned long long
#define FOR(i,l,r) for(int i=(l);i<=(r);++i)
#define ROF(i,r,l) for(int i=(r);i>=(l);--i)
#define eb emplace_back
#define fr first
#define se second
#define cmin(x,y) x=min(x,y)
using namespace std;
bool __ST;
void Document() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
}
int read() {
	int s=0,t=1;char ch=getchar();
	while(!isdigit(ch)) {if(ch=='-') t=-1;ch=getchar();}
	while(isdigit(ch)) {s=(s<<3)+(s<<1)+(ch^48);ch=getchar();}
	return s*t;
}
const int N=1e5+10;
int n,m,k,tot,cnt,fa[N],cst[12][N],c[N],siz[N];
LL ans=1e15;
struct edge {
	int u,v,w;
}e[N*10],g[N*10],f[N*10],mg[N*20];
int cmp(edge x,edge y) {
	return x.w<y.w;
}
int Get(int x) {
	if(x==fa[x]) return x;
	return fa[x]=Get(fa[x]);
}
void Merge(int x,int y) {
	int fx=Get(x),fy=Get(y);
	if(fx<fy) swap(fx,fy);
	fa[fy]=fx;siz[fx]+=siz[fy];
}
vector<int> usd;
bool vis[12];
void calc() {
	LL pres=0,tc=0;
	FOR(i,1,k) if(vis[i]) pres+=c[i];
	FOR(i,1,n+k) fa[i]=i,siz[i]=1;
	int p=1,q=1;tc=1;
	while(p<=cnt&&q<=tot) {
		if(!vis[g[q].u-n]) {
			++q;
			continue;
		}
		if(f[p].w<=g[q].w) {
			mg[tc++]=f[p++];
		} else mg[tc++]=g[q++];
	}
	while(p<=cnt) mg[tc++]=f[p++];
	while(q<=tot) {
		if(!vis[g[q].u-n]) {++q;continue;}
		mg[tc++]=g[q++];
	}
	FOR(i,1,tc) {
		int u=mg[i].u,v=mg[i].v;
		if(Get(u)==Get(v)) continue;
		pres+=mg[i].w;Merge(u,v);
	}
	cmin(ans,pres);
}
bool __ED;
int main() { cerr<<(&__ED-&__ST)/1048576.<<"\n";
	Document();
	cin>>n>>m>>k;
	FOR(i,1,n+k) fa[i]=i;
	FOR(i,1,m) {
		int u=read(),v=read(),w=read();
		e[i]={u,v,w};
	}
	sort(e+1,e+m+1,cmp);
	LL res=0;
	FOR(i,1,m) {
		int u=e[i].u,v=e[i].v;
		if(Get(u)!=Get(v)) {
			fa[Get(u)]=Get(v);
			res+=e[i].w;
			f[++cnt]=e[i];
		}
	}
	cmin(ans,res);
	FOR(i,1,k) {
		c[i]=read();
		FOR(j,1,n) cst[i][j]=read();
	} tot=0;
	FOR(i,1,k) FOR(j,1,n) g[++tot]={i+n,j,cst[i][j]};
	sort(g+1,g+tot+1,cmp);
	FOR(S,1,(1<<k)-1) {
		FOR(j,1,k) {
			if(S>>(j-1)&1) {
				vis[j]=1;
			} else vis[j]=0;
		}
		calc();
	}
	cout<<ans<<"\n";
	return 0;
}
