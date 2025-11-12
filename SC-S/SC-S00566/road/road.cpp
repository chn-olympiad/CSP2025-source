#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e4+5,M=1e6+5,K=11;
const ll inf=1e18;
struct Edge{
	int u,v,w;
	friend bool operator<(const Edge& A,const Edge& B){
		return A.w<B.w;
	}
} e[M],te[M];
int a[K][N],c[K];
struct Dsu{
	int fa[N];
	void init(int n){
		for(int i=1;i<=n;i++) fa[i]=i;
	}
	int find(int x){
		if(x==fa[x]) return x;
		return fa[x]=find(fa[x]);
	}
	inline void merge(int x,int y){ fa[find(x)]=find(y); }
} dsu;
int n,m,k,cnt;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++) cin>>e[i].u>>e[i].v>>e[i].w;
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++) cin>>a[i][j];
	}
	sort(e+1,e+m+1);
	dsu.init(n);
	for(int i=1;i<=m;i++){
		int u=e[i].u,v=e[i].v;
		if(dsu.find(u)!=dsu.find(v)){
			dsu.merge(u,v);
			te[++cnt]=e[i];
		}
	}
	for(int i=1;i<=k;i++){
		for(int j=1;j<=n;j++){
			te[++cnt]={i+n,j,a[i][j]};
		}
	}
	sort(te+1,te+cnt+1);
	ll ans=inf;
	for(int s=0;s<(1<<k);s++){
		dsu.init(n+k);
		ll sum=0;
		for(int i=1;i<=k;i++){
			if((s>>(i-1))&1) sum+=c[i];
		}
		for(int i=1;i<=cnt;i++){
			if(sum>ans) continue;
			int u=te[i].u,v=te[i].v,w=te[i].w;
			if(u<=n || ((s>>(u-n-1))&1)){
				if(dsu.find(u)!=dsu.find(v)) sum+=w,dsu.merge(u,v);
			}
		}
		ans=min(ans,sum);
	}
	cout<<ans<<"\n";
}
//??