#include<bits/stdc++.h>
//#define DBG

#ifdef DBG
#define dbg(...) fprintf(stderr,__VA_ARGS__)
#else
#define dbg(...) void()
#endif

#define il inline __attribute((always_inline))

using u32=unsigned int;
using i64=long long;
using u64=unsigned long long;

template<typename T=int>
il T read(){
	T x=0;char c=getchar(),f=0;
	while(c<'0'||'9'<c) f=(c=='-'),c=getchar();
	while('0'<=c&&c<='9') x=x*10+(c&15),c=getchar();
	return f?-x:x;
}

template<typename T>
void print(T x){
	if(x==0) return putchar('0'),void();
	if(x<0) putchar('-'),x=-x;
	if(x>=10) print(x/10),x%=10;
	putchar(x|'0');
}

using E=std::array<int,3>;

E es[1000010],ee[1000010];

int par[20010],siz[20010],c[20010];

il int find(int u){
	while(u!=par[u]){
		u=par[u]=par[par[u]]=par[par[par[u]]];
	}
	return u;
}

il bool merge(int u,int v){
	u=find(u),v=find(v);
	if(u==v) return false;
	if(siz[u]>siz[v]) std::swap(u,v);
	par[u]=v;
	siz[v]+=siz[u];
	return true;
}

il void build(int n){
	for(int i=1;i<=n;++i) par[i]=i,siz[i]=1;
	return;
}

int main(){
#ifndef ZIGAO
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
#endif
	
	int i,j,u,v,w,cnte=0,s,maxs,cnt;
	i64 res=0,now;
	int n=read();
	int m=read();
	int K=read();
	maxs=1<<K;
	
	for(i=0;i<m;++i){
		es[i][1]=read();
		es[i][2]=read();
		es[i][0]=read();
	}
	
	std::sort(es,es+m);
	
	build(n);
	for(i=0;i<m;++i){
		auto [w,u,v]=es[i];
		if(merge(u,v)) ee[cnte++]={w,u,v},res+=w;
	}
	
	for(i=1;i<=K;++i){
		c[i]=read();
		for(j=1;j<=n;++j){
			ee[cnte++]={read(),i+n,j};
		}
	}
	
	std::sort(ee,ee+cnte);
	
	for(s=0;s<maxs;++s){
		now=cnt=0;
		for(i=0;i<K;++i) if((s>>i)&1) now+=c[i+1],--cnt;
		build(n+K);
		for(i=0;i<cnte&&now<res&&cnt<n-1;++i){
			auto [w,u,v]=ee[i];
			if((u<=n||((s>>(u-n-1))&1))&&merge(u,v)) now+=w,++cnt;
		}
		res=std::min(res,now);
	}
	
	print(res);
	
	dbg("\n%lf\n",1.0*clock()/CLOCKS_PER_SEC);
	
	return 0;
}