#include<bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define L(i,l,r) for(int i(l);i<=(r);++i)
#define R(i,r,l) for(int i(r);i>=(l);--i)
using namespace std;
const int N=1e4+30,inf=0x7fffffff,mod=998244353; 
struct dsu{
	int siz[N],f[N];
	void init(int n){
		L(i,1,n)siz[i]=1,f[i]=i;
	}
	inline int get_f(int t){
		if(f[t]==t)return t;
		return f[t]=get_f(f[t]);
	}
	inline bool merge(int u,int v){
		u=get_f(u),v=get_f(v);
		if(u==v)return 0;
		if(siz[u]<siz[v])swap(u,v);
		f[v]=u;
		siz[u]+=siz[v];
		return 1;
	}
}d0,D[1<<10];
int n,m,k,ans[1<<10],tot[1<<10],c[N];
vector<array<int,3> >e,tr;
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m>>k;
	L(i,1,(1<<k)-1)D[i].init(n+k);
	L(i,1,m){
		int u,v,w;
		cin>>u>>v>>w;
		e.push_back({u,v,w});
	}
	L(i,1,k){
		cin>>c[i];
		L(j,1,n){
			int x;
			cin>>x;
			tr.push_back({i+n,j,x});
		}
	}
	L(s,1,(1<<k)-1){
		tot[s]=n-1;
		L(i,1,k){
			if(s>>(i-1)&1){
				++tot[s];
				ans[s]+=c[i];
			}
		}
	}
	sort(e.begin(),e.end(),[&](array<int,3>x,array<int,3>y){
		return x[2]<y[2];	
	});
	d0.init(n);
	int cnt=n-1,res=0;
	for(auto giao:e){
		int u=giao[0];
		int v=giao[1];
		int w=giao[2];
		if(d0.merge(u,v))
			--cnt,tr.push_back({u,v,w}),res+=w;
		if(!cnt)break;
	}
	sort(tr.begin(),tr.end(),[&](array<int,3>x,array<int,3>y){
		return x[2]<y[2];	
	});
	for(auto giao:tr){
		int u=giao[0];
		int v=giao[1];
		int w=giao[2];
		if(u<=n){
			L(s,1,(1<<k)-1)if(tot[s]){
				if(D[s].merge(u,v)){
					--tot[s],ans[s]+=w;
				}
			}
		}
		else{
			L(s,1,(1<<k)-1)if(tot[s]){
				if(s>>(u-n-1)&1){
					if(D[s].merge(u,v))
						--tot[s],ans[s]+=w;
				}
			}
		}
	}
//	cerr<<res<<'\n';
	L(i,1,(1<<k)-1){
//		cerr<<tot[i]<<" "<<ans[i]<<'\n';
		res=min(res,ans[i]);
	}
	cout<<res<<'\n';
	return 0;
}
