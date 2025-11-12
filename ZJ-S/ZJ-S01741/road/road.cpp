#include <bits/stdc++.h>
using namespace std;
#define int long long
#define inf 0x3f3f3f3f3f3f3f3fll
#define For(i,l,r) for(int i=(l);i<=(r);++i)
#define Rof(i,l,r) for(int i=(l);i>=(r);--i)
namespace cjr2010{
	template<typename ta,typename tb>
	void MIN(ta &a,tb b){if(a>b) a=b;}
	template<typename ta,typename tb>
	void MAX(ta &a,tb b){if(a<b) a=b;}
	int n,m,k,c[11],a[11][10005];
	array<int,3> E[1100005];
	template<int N>
	struct DSU{
		int fa[N],sz[N];
		void init(int n){
			For(i,1,n) fa[i]=i,sz[i]=1;
		}
		int find(int x){
			return fa[x]==x?x:fa[x]=find(fa[x]);
		}
		bool merge(int x,int y){
			x=find(x),y=find(y);
			if(x==y) return 0;
			if(sz[x]>sz[y]) swap(x,y);
			fa[x]=y,sz[y]+=sz[x];
			return 1;
		}
	};
	namespace SUBA{
		DSU<10015> dsu;
		void MAIN(){
			For(i,1,k){
				For(j,1,n){
					E[++m]={i+n,j,a[i][j]};
				}
			}
			sort(E+1,E+m+1,[](array<int,3> A,array<int,3> B){
				return A[2]<B[2];
			});
			dsu.init(n+k);
			int ans=0;
			For(i,1,m){
				auto [u,v,w]=E[i];
				ans+=dsu.merge(u,v)*w;
			}
			cout<<ans<<"\n";
		}
	}
	namespace SUB{
		DSU<10015> dsu;
		void MAIN(){
			For(i,1,k){
				For(j,1,n){
					E[++m]={i+n,j,a[i][j]};
				}
			}
			sort(E+1,E+m+1,[](array<int,3> A,array<int,3> B){
				return A[2]<B[2];
			});
			int ans=inf;
			For(s,0,(1<<k)-1){
				dsu.init(n+k);
				int res=0;
				For(i,1,k) if(s&(1<<(i-1))) res+=c[i];
				For(i,1,m){
					auto [u,v,w]=E[i];
					if(u>n){
						if(s&(1<<(u-n-1)));
						else continue;
					}
					res+=dsu.merge(u,v)*w;
				}
				MIN(ans,res);
			}
			cout<<ans<<"\n";
		}
	}
	void MAIN(){
		cin>>n>>m>>k;
		For(i,1,m) For(j,0,2) cin>>E[i][j];
		bool FSUBA=1;
		For(i,1,k){
			cin>>c[i];
			FSUBA&=(c[i]==0);
			bool _FSUBA=0;
			For(j,1,n) cin>>a[i][j],_FSUBA|=(a[i][j]==0);
			FSUBA&=_FSUBA;
		}
		if(FSUBA){SUBA::MAIN();return ;}
		SUB::MAIN();
	}
}
signed main(){
	freopen("road.in","r",stdin),freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0),cout.tie(0);cjr2010::MAIN();
	return 0;
}
/*
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define inf 0x3f3f3f3f3f3f3f3fll
#define For(i,l,r) for(int i=(l);i<=(r);++i)
#define Rof(i,l,r) for(int i=(l);i>=(r);--i)
namespace cjr2010{
	template<typename ta,typename tb>
	void MIN(ta &a,tb b){if(a>b) a=b;}
	template<typename ta,typename tb>
	void MAX(ta &a,tb b){if(a<b) a=b;}
	int n,m,k,_c[11],c[11],_a[11][10005],a[11][10005];
	array<int,3> E[1100005];
	template<int N>
	struct DSU{
		int fa[N],sz[N];
		void init(int n){
			For(i,1,n) fa[i]=i,sz[i]=1;
		}
		int find(int x){
			return fa[x]==x?x:fa[x]=find(fa[x]);
		}
		bool merge(int x,int y){
			x=find(x),y=find(y);
			if(x==y) return 0;
			if(sz[x]>sz[y]) swap(x,y);
			fa[x]=y,sz[y]+=sz[x];
			return 1;
		}
	};
	namespace SUBA{
		DSU<10015> dsu;
		void MAIN(){
			For(i,1,k){
				For(j,1,n){
					E[++m]={i+n,j,a[i][j]};
				}
			}
			sort(E+1,E+m+1,[](array<int,3> A,array<int,3> B){
				return A[2]<B[2];
			});
			dsu.init(n+k);
			int ans=0;
			For(i,1,m){
				auto [u,v,w]=E[i];
				ans+=dsu.merge(u,v)*w;
			}
			cout<<ans<<"\n";
		}
	}
	namespace SUB{
		DSU<10015> dsu;
		array<int,3> E0[1100005];
		void MAIN(){
			For(i,1,m) E0[i]=E[i];
			sort(E+1,E+m+1,[](array<int,3> A,array<int,3> B){
				return A[2]<B[2];
			});
			int ans=0;
			dsu.init(n);
			For(i,1,m){
				auto [u,v,w]=E[i];
				ans+=dsu.merge(u,v)*w;
			}
			For(i,1,m) E[i]=E0[i];
			int sum=0;
			For(i,1,k){
				int res=0;
				For(j,1,n){
					E[++m]={i+n,j,a[i][j]};
				}
				// For(i,1,m) E0[i]=E[i];
				sort(E+1,E+m+1,[](array<int,3> A,array<int,3> B){
					return A[2]<B[2];
				});
				dsu.init(n+i);
				int _s=0,s=0;
				For(i,1,m){
					auto [u,v,w]=E[i];
					bool fff=dsu.merge(u,v);
					if(fff&&u>n){
						if(_s&(1<<(u-n-1))) s|=(1<<(u-n-1));
						else _s|=(1<<(u-n-1));
					}
					res+=fff*w;
				}
				cout<<s<<"\n";
				For(j,1,k) if(s&(1<<(j-1))) res+=c[j];
				MIN(ans,res);
				// For(i,1,m) E[i]=E0[i];
			}
			cout<<ans<<"\n";
		}
	}
	int id[11];
	void MAIN(){
		cin>>n>>m>>k;
		For(i,1,m) For(j,0,2) cin>>E[i][j];
		bool FSUBA=1;
		For(i,1,k){
			cin>>_c[i],id[i]=i;
			FSUBA&=(_c[i]==0);
			bool _FSUBA=0;
			For(j,1,n) cin>>_a[i][j],_FSUBA|=(a[i][j]==0);
			FSUBA&=_FSUBA;
		}
		sort(id+1,id+k+1,[](int A,int B){return _c[A]<_c[B];});
		For(i,1,k){
			c[i]=_c[id[i]];
			For(j,1,n) a[i][j]=_a[id[i]][j];
		}
		// if(FSUBA){SUBA::MAIN();return ;}
		SUB::MAIN();
	}
}
signed main(){
	// freopen("road.in","r",stdin),freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0),cout.tie(0);cjr2010::MAIN();
	return 0;
}
*/