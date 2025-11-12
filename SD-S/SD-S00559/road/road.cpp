//by SmileMask
#include<bits/stdc++.h>
using namespace std;

namespace SmileMask{
	#define rd read()
	typedef long long ll;
	int read(){
		int num=0,sign=1;char ch=getchar();
		while(!isdigit(ch)){
			if(ch=='-') sign=-1;
			ch=getchar();
		}
		while(isdigit(ch)){
			num=(num<<3)+(num<<1)+ch-'0';
			ch=getchar();
		}
		return num*sign;
	}
	
	const int N=1e4+10;
	const int M=1e6+10;
	
	int n,m,k;
	
	int a[11][N],c[11];
	ll ans=1e18;
	
	struct Edge{
		int u,v,w;
	}edge[M+10*N],tmp[M+10*N];
	
	int fa[N+40],sz[N+40];
	
	bool cmp(Edge x,Edge y){
		return x.w<y.w;
	}
	
	int find(int u){
		if(u==fa[u]) return u;
		return fa[u]=find(fa[u]);
	}
	
	bool merge(int u,int v){
		u=find(u),v=find(v);
		if(u==v) return 0;
		if(sz[u]<sz[v]) swap(u,v);
		sz[u]+=sz[v],fa[v]=u;
		return 1;
	}

	void Main(){
		n=rd,m=rd,k=rd;
		for(int i=1;i<=m;i++){
			int u=rd,v=rd,w=rd;
			edge[i]={u,v,w};
		}
		
		for(int i=1;i<=k;i++){
			c[i]=rd;
			for(int j=1;j<=n;j++)
				a[i][j]=rd;
		}
		
		for(int i=1;i<=n;i++)
			fa[i]=i,sz[i]=1;
		sort(edge+1,edge+m+1,cmp);
		
		int len=0;
		
		for(int i=1;i<=m;i++){
			int u=edge[i].u,v=edge[i].v;
			if(merge(u,v)){
				edge[++len]=edge[i];
			}
		}
		
		for(int i=1;i<=len;i++)
			tmp[i]=edge[i];
		for(int S=0;S<(1<<k);S++){
			for(int i=1;i<=n+k;i++)
				fa[i]=i,sz[i]=1;
			for(int i=1;i<=len;i++)
				edge[i]=tmp[i];
			ll res=0;
			int tot=len;
			
			for(int i=1;i<=k;i++)
				if(S>>(i-1)&1){
					res+=c[i];
					for(int j=1;j<=n;j++)
						edge[++tot]={j,i+n,a[i][j]};
				}
//			cout<<len<<endl;
			sort(edge+1,edge+tot+1,cmp);
			for(int i=1;i<=tot;i++){
				int u=edge[i].u,v=edge[i].v;
				int fu=find(u),fv=find(v);
				if(fu==fv) continue;
				res+=edge[i].w;
				if(sz[fu]<sz[fv]) swap(fu,fv);
				sz[fu]+=sz[fv],fa[fv]=fu;
			}
//			for(int i=n+1;i<=n+k;i++)
//				if(S>>(i-1)&1){
//					if(deg[i]<2)
//						res=1e18;
//				}
			ans=min(ans,res);
		}
		cout<<ans<<endl;
	}
} 	

signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	SmileMask::Main();
	return 0;
}
/*
如何将c_i 的贡献算进去？？？？？
或者 
*/

