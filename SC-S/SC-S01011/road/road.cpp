#include<iostream>
#include<algorithm>
#include<bitset>
#include<vector>
#define ll long long
using namespace std;

const int N=1e5+5;
const int M=1e6+5;

int tot;
int n,m,k;

ll a[20][N];
ll c[20];

int id[N],nid[N];

bitset<N>flag[N];
bitset<N>used;

vector<ll>val;

namespace OIfast{
	
	#define gc getchar()
	
	inline int read(){
		int n=0;static char c=gc;
		while(!isdigit(c))c=gc;
		while(isdigit(c))n=(n<<3)+(n<<1)+(c^48),c=gc;
		return n;
	}
	
}using namespace OIfast;

inline void getmn(ll &a,ll b){
	return a=(a<b?a:b),void();
}

namespace DSU{
	
	int fa[N<<1];
	
	inline void init(){
		for(int i=1;i<=n+k;++i)fa[i]=i;
		return ;
	}
	
	inline int find(int x){
		return x==fa[x]?x:fa[x]=find(fa[x]);
	}
	
}using namespace DSU;

struct info{
	
	int id;
	
	bool type;//0 -> 实边，1 -> 虚边
	
	ll w;
	
	int u,v;
	
}tmp[M];

namespace graph{
	
	int idx;
	
	struct edge{
		int u,v;ll w;
	}e[M<<2];
	
	inline void add(int u,int v,ll w){
		return e[++idx]={u,v,w},void();
	}
	
//	struct node{
//		
////		int idx;
//		int c;
//		
//		ll a[N];
//		
//		edge e2[M];
//		
//		inline void add(int u,int v,ll w){
//			return e2[++idx]={u,v,w},void();
//		}
//		
//	}nd[20];
//	
//	inline void add1(int u,int v,ll w){
//		return e1[++idx]={u,v,w},void();
//	}
	
	inline ll Kruskal(){
		ll res=0;
//		sort(e1+1,e1+m+1,[](edge a,edge b){return a.w<b.w;});
//		sort(nd+1,nd+k+1,[](node a,node b){return a.c<b.c;});
//		for(int i=1;i<=k;++i)sort(nd[i].e2+1,nd[i].e2+nd[i].idx+1,[](edge a,edge b){return a.w<b.w;});
		sort(e+1,e+idx+1,[](edge a,edge b){return a.w<b.w;});
		for(int i=1;i<=idx;++i){
			res=0;
			init();
			for(int j=1;j<=i;++j){
				int u=e[j].u,v=e[j].v;
				int fu=find(u),fv=find(v);
				if(fu^fv){
					res+=e[j].w,fa[fu]=fv;
					if(u>n)res+=c[u-n];
					if(v>n)res+=c[v-n];
				}
			}
			int tmp=find(1);
			bool f=1;
			for(int i=1;i<=n;++i)if(tmp^find(i))f=0;
			if(f)return res;
		}
		return res;
	}
	
}using namespace graph;

signed main(){
	freopen("road.in","r",stdin),freopen("road.out","w",stdout);
	n=read(),m=read(),k=read();
	for(int i=1;i<=m;++i){
		int u=read(),v=read();ll w=read();
		add(u,v,w),val.push_back(w),tmp[idx]={idx,0,w,u,v};
	}
	for(int i=1;i<=k;++i){
		c[i]=read();
		for(int j=1;j<=n;++j)a[i][j]=read(),add(i,j,a[i][j]);
	}
	return printf("%lld\n",Kruskal()),0;
}

/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4

13

*/