#include<bits/stdc++.h> 
using namespace std ;

//#define int ll
typedef long long ll; 
typedef unsigned long long ull ;

using pii=pair<int,int> ;
#define fi first
#define se second
#define mk make_pair

#define sz(x) (int)(x.size()) 
#define eb emplace_back 
#define btpc(x) __builtin_popcount(x) 
#define btpcll(x) __builtin_popcountll(x)

#define ReadIn(s) freopen(s,"r",stdin)
#define OutPut(s) freopen(s,"w",stdout)

bool Mst ;

template<class T>
inline void read (T& x) {
	int sgn=0;char ch=getchar() ;x=0;
	while(!isdigit(ch)) sgn|=(ch=='-'),ch=getchar();
	while(isdigit(ch)) x=x*10+ch-'0',ch=getchar();
	sgn?x=-x:1;
}

const int M=1e6+10;

int n,m,k;

struct edge {
	int u,v;
	ll w;
	bool operator < (const edge &a) const {
		return w<a.w;
	}
}tmp[M],e[M];

int tot[M] ;
edge ed[1<<10][10010] ;

int fa[M] ;

int find(int x) {
	return x==fa[x]?x:fa[x]=find(fa[x]) ;
}
void merge(int x,int y) {
	x=find(x);y=find(y) ;
	if(x==y) return ;
	fa[x]=y;
}

ll res=0;

void init_kru() {
	sort(tmp+1,tmp+m+1) ;
	for(int i=1;i<=n;i++) fa[i]=i;
	res=0;
	int con=n,o=0;
	for(auto it:tmp) {
		int u=find(it.u),v=find(it.v);
		ll w=it.w;
		if(u==v) continue ;
		fa[u]=v;res+=w;e[++o]=it;
		if((--con)==1) return ;
	}
	
}

ll c[M] ;
edge t[20][10010] ;

ll kru (int S,int id) {
	for(int i=1;i<=n+k;i++) {
		fa[i]=i;
	}
	
	int lp=1,rp=1;
	
	ll va=0;
	
	int o=0;
	
	while(lp<=tot[S]||rp<=n) {
		edge it;
		if(rp>n) it=ed[S][lp],lp++;
		else if(lp>tot[S]) it=t[id][rp],rp++;
		else if(ed[S][lp]<t[id][rp]) it=ed[S][lp],lp++;
		else it=t[id][rp],rp++;
		int u=find(it.u),v=find(it.v);
		ll w=it.w;
		if(u==v) continue ;
		
//		cout<<it.u<<" "<<it.v<<" "<<it.w<<"\n";
		
		fa[u]=v;va+=w;ed[S+(1<<id-1)][++o]=it;
		
	}
	
	tot[S+(1<<id-1)]=o;
	
//	assert(con==1) ;
	
	return va;
	
}

void solve() {
	read(n);read(m);read(k) ;
	for(int i=1;i<=m;i++) {
		int u,v;ll w;read(u);read(v);read(w) ;
		tmp[i]=edge{u,v,w} ;
	}
	
	for(int i=1;i<=k;i++) {
		read(c[i]) ;int id=0;
		for(int j=1;j<=n;j++) {
			int x;read(x) ;
			t[i][++id]=edge{n+i,j,x} ;
		}
		sort(t[i]+1,t[i]+id) ;
	}
	
	init_kru() ;
	
	ll Ans=res;
	
	for(int i=1;i<n;i++) ed[0][i]=e[i] ;tot[0]=n-1;
	
	for(int S=1;S<1<<k;S++) {
		
		ll v=0;
		for(int i=0;i<k;i++) if(S>>i&1) v+=c[i+1] ;
		
		v+=kru(S-(S&-S),__lg(S&-S)+1) ;
		
//		cout<<S<<" "<<v<<"\n" ;
		
		Ans=min(Ans,v);
	}
	
	cout<<Ans;
	
}

bool Med ;

signed main() {
	ReadIn("road.in");
	OutPut("road.out");
	
	solve() ;
	
	cerr<<"\n" ;
	cerr<<1.0*clock () /CLOCKS_PER_SEC*1000<<" ms\n" ;
	cerr<<(&Med-&Mst) /1024.0/1024.0<<" mb\n" ;
	
	return 0;
}