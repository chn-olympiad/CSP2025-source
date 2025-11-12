#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=1e4+100,maxk=10,maxm=2e6;
int n,m,k;
struct Node {
	int u,v,w;
	bool operator<(Node &x)const & {
		return w<x.w;
	}
} E[maxm],e[maxm];
int cnt,c[maxk],a[maxk][maxn-maxk],fa[maxn];
namespace pzh1 {
	bool isuse[maxk];
	int ans=1e18;
	int find(int x) {
		return (x==fa[x]?x:fa[x]=find(fa[x]));
	}
	void ppl() {
		int cnt1=cnt;
		for(int i=1; i<=cnt; i++) e[i]=E[i];
		int sum=0;
		for(int i=1; i<=k; i++) {
			if(!isuse[i]) continue;
			sum+=c[i];
			for(int j=1; j<=n; j++) e[++cnt1]= {i+n,j,a[i][j]};
		}
		for(int i=1; i<=n+k; i++) fa[i]=i;
		sort(e+1,e+cnt1+1);
		for(int i=1; i<=cnt1; i++) {
			int fu=find(e[i].u),fv=find(e[i].v),w=e[i].w;
			if(fu==fv) continue;
			fa[fu]=fv,sum+=w;
		}
		ans=min(ans,sum);
	}
	void dfs(int idx) {
		if(idx==k+1) {
			ppl();
			return;
		}
		dfs(idx+1);
		isuse[idx]=1;
		dfs(idx+1);
		isuse[idx]=0;
	}
	void solve1() {
		dfs(1);
		cout<<ans;
		exit(0);
	}
}
namespace pzh2 {
	bool isuse[maxk];
	int find(int x) {
		return (x==fa[x]?x:fa[x]=find(fa[x]));
	}
	void solve2() {
		int ans=0;
		for(int i=1; i<=k; i++) {
			for(int j=1; j<=n; j++) {
				E[++cnt]= {i+n,j,a[i][j]};
			}
		}
		for(int i=1; i<=n+k; i++) fa[i]=i;
		sort(E+1,E+cnt+1);
		for(int i=1; i<=cnt; i++) {
			int fu=find(E[i].u),fv=find(E[i].v),w=E[i].w;
			if(fu==fv) continue;
			fa[fu]=fv,ans+=w;
		}
		cout<<ans;
		exit(0);
	}
}
namespace bukeyizongsiling {
	bool isuse[maxk];
	int ans=1e18;
	int find(int x) {
		return (x==fa[x]?x:fa[x]=find(fa[x]));
	}
	void ppl() {
		int cnt1=cnt;
		for(int i=1; i<=cnt; i++) e[i]=E[i];
		int sum=0;
		for(int i=1; i<=k; i++) {
			if(!isuse[i]) continue;
			sum+=c[i];
			for(int j=1; j<=n; j++) e[++cnt1]= {i+n,j,a[i][j]};
		}
		for(int i=1; i<=n+k; i++) fa[i]=i;
		sort(e+1,e+cnt1+1);
		for(int i=1; i<=cnt1; i++) {
			int fu=find(e[i].u),fv=find(e[i].v),w=e[i].w;
			if(fu==fv) continue;
			fa[fu]=fv,sum+=w;
		}
		ans=min(ans,sum);
	}
	void yishu() {
		mt19937 rand(time(NULL));
		for(int i=1; i<=k; i++) isuse[i]=rand()%2;
		ppl();
	}
	void solve() {
		int tmp=m*log2(m)+10;
		for(int i=1e7+10; i>0; i-=tmp) yishu();
		cout<<ans;
		exit(0);
	}
}
signed main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m>>k;
	bool flag=1;
	for(int i=1,u,v,w; i<=m; i++) {
		cin>>u>>v>>w;
		E[++cnt]= {u,v,w};
	}
	for(int i=1; i<=k; i++) {
		cin>>c[i];
		if(c[i]!=0) flag=0;
		for(int j=1; j<=n; j++) cin>>a[i][j];
	}
	if(flag) pzh2::solve2();
	if(k<=5) pzh1::solve1();
	bukeyizongsiling::solve();
	return 0;
}