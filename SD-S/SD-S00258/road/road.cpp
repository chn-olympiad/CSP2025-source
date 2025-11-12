#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

constexpr int N=1e4+100,M=1e6+100;

constexpr int MOD=998244353;

int n,m,k;

vector<pair<int,int>> G[N];

namespace bao1{
	int fa[N];
	
	struct node{
		int u,v,w;
	};node edges[M];
	
	inline int find(int x){
		if(fa[x]!=x){
			return fa[x]=find(fa[x]);
		}
		return x;
	}
	
	inline void merge(int x,int y){
		fa[x]=y;
	}
	
	inline void doit(){
		for(int i=1;i<=n;i++){
			fa[i]=i;
		}
		for(int i=1;i<=m;i++){
			cin>>edges[i].u>>edges[i].v>>edges[i].w;
		}
		sort(edges+1,edges+m+1,[&](node x,node y){
			return x.w<y.w;
		});
		ll ans=0;
		for(int i=1;i<=m;i++){
			int fx=find(edges[i].u),fy=find(edges[i].v);
			if(fx!=fy){
				merge(fx,fy);
				ans+=edges[i].w;
			}
		}
		cout<<ans<<'\n';
	}
}

namespace bao2{
	int fa[N];
	
	int tot[11];
	
	int c[11][N];
	
	struct node{
		int u,v,w;
	};node edges[M<<1];
	
	inline int find(int x){
		if(fa[x]!=x){
			return fa[x]=find(fa[x]);
		}
		return x;
	}
	
	inline void merge(int x,int y){
		fa[x]=y;
	}
	
	inline int kru(int cnt){
		for(int i=1;i<=n+k;i++){
			fa[i]=i;
		}
		sort(edges+1,edges+cnt+1,[&](node x,node y){
			return x.w<y.w;
		});
		ll ans=0;
		for(int i=1;i<=cnt;i++){
			int fx=find(edges[i].u),fy=find(edges[i].v);
			if(fx!=fy){
				merge(fx,fy);
				ans+=edges[i].w;
			}
		}
		return ans;
	}
	
	inline void doit(){
		for(int i=1;i<=m;i++){
			cin>>edges[i].u>>edges[i].v>>edges[i].w;
		}
		for(int i=1;i<=k;i++){
			cin>>tot[i];
			for(int j=1;j<=n;j++){
				cin>>c[i][j];
			}
		}
		ll res=0,cnt=0,an=INT_MAX;
		for(int i=0;i<=(1<<k)-1;i++){
			res=0;
			cnt=0;
			for(int j=0;j<k;j++){
				if(i&(1<<j)){
					res+=tot[j+1];
					for(int l=1;l<=n;l++){
						cnt++;
						edges[m+cnt].u=l,edges[m+cnt].v=n+j+1,edges[m+cnt].w=c[j+1][l];
					}
				}
			}
			int kk=kru(m+cnt);
			an=min(an,kk+res);
		}
		cout<<an<<'\n';
	}
}

inline void solve(){
	cin>>n>>m>>k;
	if(k==0){
		bao1::doit();
	}
	bao2::doit();
}

signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(NULL);
	cin.tie(NULL),cout.tie(NULL);
	int T=1;
//	cin>>T;
	while(T--){
		solve();
	}
	return 0;
}

