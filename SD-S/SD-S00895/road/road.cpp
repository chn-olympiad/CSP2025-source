//ni zhen!
#include<bits/stdc++.h>

#define _vc_(_6,_5,_4,_3,_2,_1,_,...) _
#define _vc(a...) _vc_(a,6,5,4,3,2,1)
#define _ct_(a,b) a##b
#define _ct(a,b) _ct_(a,b)
#define deb1(a) <<#a<<"="<<(a)<<"; "
#define deb2(a,b...) deb1(a)deb1(b)
#define deb3(a,b...) deb1(a)deb2(b)
#define deb4(a,b...) deb1(a)deb3(b)
#define deb5(a,b...) deb1(a)deb4(b)
#define deb6(a,b...) deb1(a)deb5(b)
#define deb(a...) cerr<<string(_dep*3,' ')<<"deb"<<__LINE__<<"|:" _ct(deb,_vc(a)) (a) <<endl
unsigned _dep;

using namespace std;
using i64=long long;

const int maxn=1e4+10+10,max_k=10,maxm=1e6+10;

int n,m,k;
struct node{
	int u,v,w;
}E[maxm],E_extra[max_k][maxn],E_cur[max_k+1][maxn];

bool operator<(node a,node b){return a.w<b.w;}

struct{
	int fa[maxn];
	int gfa(int x){
		return fa[x]<0?x:fa[x]=gfa(fa[x]);
	}
	void mer(int u,int v){
		u=gfa(u),v=gfa(v);
		if(fa[u]>fa[v])swap(u,v);
		fa[u]+=fa[v],fa[v]=u;
	}
	void init(int n){
		memset(fa+1,-1,n*sizeof fa[0]);
	}
}dsu;

int c[max_k],a[max_k][maxn];

i64 ans=LLONG_MAX;


void dfs(int i,i64 bas){
	if(i == k)return;
	memcpy(E_cur[i+1],E_cur[i],(1+E_cur[i][0].w) * sizeof E_cur[0][0] );
	dfs(i+1,bas);
	bas+=c[i];
	
	dsu.init(n+k); 
	
	int l=1,r=1, l_n=E_cur[i][0].w, r_n=n;
	int&tp=E_cur[i+1][0].w;tp=0;i64 res=0;
	
	while(l<=l_n || r<=r_n){
		node cE={};
		if(r>r_n || (l<=l_n && E_cur[i][l].w < E_extra[i][r].w)){
			cE=E_cur[i][l++];
		}else cE=E_extra[i][r++];
		
		
		int u=dsu.gfa(cE.u),v=dsu.gfa(cE.v),w=cE.w;
		
		if(u==v)continue;
		res += w;
		E_cur[i+1][++tp]=cE;
		
		dsu.mer(u,v);		
	}
	
	ans = min(ans, bas + res);
	dfs(i+1,bas);
}



signed main(){
	
//	cerr<<(sizeof E + sizeof E_extra + sizeof E_cur + sizeof dsu + sizeof c+ sizeof a >> 20);
	
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	cin>>n>>m>>k;
	for(int i=1,u,v,w;i<=m;++i)cin>>u>>v>>w,E[i]={u,v,w};
	sort(E+1,E+m+1);
	for(int i=0;i<k;++i){
		cin>>c[i];for(int j=1;j<=n;++j)cin>>a[i][j];
		for(int j=1;j<=n;++j)E_extra[i][j]={n+1+i,j,a[i][j]};
		sort(E_extra[i]+1,E_extra[i]+n+1);
	}
	
	dsu.init(n);
	i64 res=0;
	for(int i=1;i<=m;++i){
		int u=dsu.gfa(E[i].u),v=dsu.gfa(E[i].v),w=E[i].w;
		
		if(u==v)continue;
		res += w;
		E_cur[0][++E_cur[0][0].w]=E[i];
		
		dsu.mer(u,v);		
	}
	ans=res;
	
//	deb(ans);
	
	dfs(0,0);
	cout<<ans;
	
//	cerr<<(clock()*1./CLOCKS_PER_SEC);
}

