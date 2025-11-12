#include<bits/stdc++.h>
typedef long long ll;
typedef __int128 lll;
typedef double db;
typedef long double ld;
#define fir first
#define sec second
#define pb push_back
#define ppc __builtin_popcountll
using namespace std;
void rd(){}
template<typename T,typename ...U> void rd(T &x,U &...arg){
	x=0;int f=1,c=getchar();
	while(c<'0'||c>'9'){if(c=='-') f=-1;c=getchar();}
	while(c>='0'&&c<='9') x=x*10+c-48,c=getchar();
	x*=f;rd(arg...);
}
void rds(char *s){
	int c=getchar();
	while(c<'a'||c>'z') c=getchar();
	while(c>='a'&&c<='z') *s=char(c),s++,c=getchar();
	*s='\0';
}

bool Mbe;

typedef pair<int,int> pii;
const int maxn=2e5+5,maxl=2.5e6+5,maxN=maxn*100,V=5e6;

int N,Q;
char s[maxl<<1],__s[maxl<<1];//warning, |t| can > maxl
int ans[maxn];

struct ACAM{
	static const int V=26;
	static const char C='a';
	struct node{
		int son[26],fail,ln;
	}t[maxl];
	int tn;
	vector<int> E[maxl];
	ACAM(){
		tn=0;
		for(int i=0;i<V;i++) t[0].son[i]=0;
		t[0].fail=0;
		t[0].ln=0;
		E[0].clear();
	}
	inline int allot(){
		tn++;
		for(int i=0;i<V;i++) t[tn].son[i]=0;
		t[tn].fail=0;
		t[tn].ln=0;
		E[tn].clear(); 
		return tn;
	}
	int Insert(char *s){
		int n=int(strlen(s)),u=0;
		for(int i=0;i<n;i++){
			int &v=t[u].son[s[i]-C];
			if(!v) v=allot(),t[v].ln=i+1;
			u=v;
		}
		return u;
	}
	int par[maxl],sz[maxl],son[maxl];
	void dfs1(int u,int fa){
		par[u]=fa,sz[u]=1,son[u]=-1;
		for(int v:E[u])
			dfs1(v,u),sz[u]+=sz[v],
			son[u]=son[u]==-1||sz[v]>sz[son[u]]?v:son[u];
	}
	int dfn[maxl],dfnn,rev[maxl],top[maxl];
	void dfs2(int u,int tp){
		dfn[u]=++dfnn,rev[dfnn]=u,top[u]=tp;
		if(~son[u]) dfs2(son[u],tp);
		for(int v:E[u])
			if(v!=son[u])
				dfs2(v,v);
	}
	void build(){
		queue<int> q;
		for(int i=0;i<V;i++)
			if(t[0].son[i])
				q.push(t[0].son[i]),t[t[0].son[i]].fail=0;
		while(!q.empty()){
			int u=q.front();q.pop();
			for(int i=0;i<V;i++)
				if(!t[u].son[i]) t[u].son[i]=t[t[u].fail].son[i];
				else t[t[u].son[i]].fail=t[t[u].fail].son[i],q.push(t[u].son[i]);
		}
		for(int i=1;i<=tn;i++){
			E[t[i].fail].pb(i);
		}
		dfnn=0;
		dfs1(0,-1);
		dfs2(0,0);
	}
	void walk1(char *s,int *q){
		int n=int(strlen(s));
		for(int i=0,u=0;i<n;i++){
			u=t[u].son[s[i]-C];
			q[i]=u;
		}
	}
	int fd(int u,int lim){
		while(t[top[u]].ln>=lim){
			u=par[top[u]];
		}
		int l=dfn[top[u]],r=dfn[u];
		while(l<=r){
			int mid=(l+r)>>1;
			if(t[rev[mid]].ln>=lim) r=mid-1;
			else l=mid+1;
		}
		return rev[r];
	}
}ac[2];

int q1[maxl<<1],q2[maxl<<1];

vector<int> vc[maxl];

#define mid ((l+r)>>1)
struct segment{
	int ls,rs,s;
}t[maxN];
int tn;
inline int allot(){
	t[++tn]={0,0,0};
	return tn;
}
inline void update(int L,int R,int &x,int y,int l=1,int r=V){
	if(L>R||L>r||R<l) return;
	x=allot();
	t[x]=t[y];
	if(l>=L&&r<=R){
		t[x].s++;
		return;
	}
	if(L<=mid) update(L,R,t[x].ls,t[y].ls,l,mid);
	if(R>mid) update(L,R,t[x].rs,t[y].rs,mid+1,r);
}
inline int qry(int p,int x,int y,int l=1,int r=V){
	if(l==r) return t[x].s-t[y].s;
	return t[x].s-t[y].s+(p<=mid?qry(p,t[x].ls,t[y].ls,l,mid):qry(p,t[x].rs,t[y].rs,mid+1,r));
}
#undef mid

int rt[maxl];
void dfs1(int u){
	for(auto i:vc[u]){
		int l=ac[0].dfn[i],r=ac[0].dfn[i]+ac[0].sz[i]-1;
		update(l,r,rt[u],rt[u]);
	}
	for(int v:ac[1].E[u]){
		rt[v]=rt[u];
		dfs1(v);
	}
}

bool Med;

int main(){
	cerr<<(&Mbe-&Med)/1048576.0L<<" MB\n";

	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);

//	ll sln=0;

	rd(N,Q);
	for(int i=1;i<=N;i++){
		rds(s);
		int ed1=ac[0].Insert(s);
		rds(s);
		int ed2=ac[1].Insert(s);
		vc[ed2].pb(ed1);
//		sln+=strlen(s);
	}

//	cerr<<"sln = "<<sln<<"\n";
//	cerr<<"tn = "<<ac[0].tn<<"\n";

	ac[0].build();
	ac[1].build();
	dfs1(0);
//	cerr<<"tn = "<<tn<<", maxN = "<<maxN<<"\n";

	for(int i=1;i<=Q;i++){
		rds(s),rds(__s);
		int n=int(strlen(s));
		if(n!=int(strlen(__s))){
			continue;
		}
		ac[1].walk1(__s,q1);
		ac[0].walk1(s,q2);
		int l=n,r=0;
		for(int j=0;j<n;j++){
			if(s[j]!=__s[j]){
				l=min(l,j);
				r=j;
			}
		}
		for(int j=r;j<n;j++){
			int u=q1[j],lim=j-l+1;
			if(ac[1].t[u].ln<lim) continue;
			int v=ac[1].fd(u,lim);
			ans[i]+=qry(ac[0].dfn[q2[j]],rt[u],rt[v]);
		}
	}

	for(int i=1;i<=Q;i++) printf("%d\n",ans[i]);
	return 0;
}

