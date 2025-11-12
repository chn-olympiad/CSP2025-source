#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define int ll
const int N=1e4+5,M=1e6+5,K=12;
template<typename T=int>inline T read(){
	T x=0;bool f=false;char c=getchar();
	while(c<'0'||c>'9') f|=(c=='-'),c=getchar();
	while(c>='0'&&c<='9') x=x*10+c-'0',c=getchar();
	return f?-x:x;
}
int n,m,tot,k,res,bd,a[K][N],d[N];
struct Edge{int x,y,z;}e[M*2];
vector<Edge> G[N+K];
namespace KRUSKAL{
	Edge e1[M*2];int cnt,fa[N+K];ll res;
	inline bool cmp(Edge x,Edge y){return x.z<y.z;}
	inline int get(int x){
		if(x==fa[x]) return x;
		return fa[x]=get(fa[x]);
	}
	inline ll main(){
		res=cnt=0;
		for(int i=1;i<=tot;++i) e1[i]=e[i];
		sort(e+1,e+tot+1,cmp);
		for(int i=1;i<=n+k;++i) fa[i]=i;
		for(int i=1,x,y,z,fx,fy;i<=tot;++i){
			x=e[i].x,y=e[i].y,z=e[i].z;
			fx=get(x),fy=get(y);
			if(fx==fy) continue;
			++cnt,res+=z,fa[fx]=fy;
			if(cnt==n+bd-1) break;
		}
		for(int i=1;i<=tot;++i) e[i]=e1[i];
		return res;
	}
}
namespace SUBA{
	ll res;
	inline ll main(){
		bd=k;
		for(int i=1;i<=k;++i)
			for(int j=1;j<=n;++j)
				e[++tot]=(Edge){i+n,j,a[i][j]};
		res=KRUSKAL::main();
		return res;
	}
}
namespace SUB1_12{
	ll res;
	inline void dfs(int p,ll c){
		if(c>=res) return;
		if(p==k+1){
			res=min(res,c+KRUSKAL::main());
			return;
		}
		dfs(p+1,c);++bd;
		for(int i=1;i<=n;++i) e[++tot]=(Edge){p+n,i,a[p][i]};
		dfs(p+1,c+d[p]);
		tot-=n,--bd;
		return;
	}
	inline ll main(){
		res=(1ll<<62);
		dfs(1,0);
		return res;
	}
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	bool A=true;
	n=read(),tot=m=read(),k=read();
	for(int i=1,x,y,z;i<=m;++i){
		x=read(),y=read(),z=read();
		e[i]=(Edge){x,y,z};
		G[x].push_back((Edge){x,y,z}); 
		G[y].push_back((Edge){y,x,z}); 
	}
	for(int i=1;i<=k;++i){
		d[i]=read();
		if(d[i]!=0) A=false;
		for(int j=1;j<=n;++j) a[i][j]=read();
	}
	if(k==0) res=KRUSKAL::main();
	else if(A) res=SUBA::main();
	else res=SUB1_12::main();
	cout<<res;
	return 0;
}
/*
这road3.in要1.048s，会赢吗？ 
不是怎么满数据暴力也才8s
666还要开long long
不是哥们我到底哪里没开了
找不到，只能define int long long了
这下卡常更不可能过了 
但是这电脑好像比CCF少爷机菜一点
也许有希望（
等等prim是不是过了
我想啥呢我又不会prim 
哦并非满数据啊，那没事了 
*/