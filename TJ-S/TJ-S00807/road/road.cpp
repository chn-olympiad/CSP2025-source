#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int N = 1e4+1,M = 1e6+1;
int n,m,k,a[11][N];
struct edge{
	int u,v,w;
}edges[M+N*10],t[M+N*10];
inline bool cmp(const edge &x,const edge &y){
	return x.w<y.w;
}
namespace DSU{
	int fa[N+10],siz[N+10];
	void init(){
		for(int i = 1;i<=n+k;++i){
			fa[i] = i;
			siz[i] = 1;
		}
	}
	inline int find(const int &x){
		return x == fa[x]?x:fa[x] = find(fa[x]);
	}
	inline bool merge(const int &x,const int &y){
		int rootx = find(x),rooty = find(y);
		if(rootx == rooty){
			return false;
		}
		if(siz[rootx]>siz[rooty]){
			swap(rootx,rooty);
		}
		fa[rootx] = rooty;
		siz[rooty]+=siz[rootx];
		return true;
	}
}using namespace DSU;
int kruskal(){
	stable_sort(edges+1,edges+m+1,cmp);
	init();
	int res = 0;
	for(int i = 1;i<=m;++i){
		if(merge(edges[i].u,edges[i].v)){
			res+=edges[i].w;
		}
	}
	return res;
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin >> n >> m >> k;
	for(int i = 1;i<=m;++i){
		cin >> edges[i].u >> edges[i].v >> edges[i].w;
		t[i] = edges[i];
	}
	bool flag = true;
	for(int i = 1;i<=k;++i){
		for(int j = 0;j<=n;++j){
			cin >> a[i][j];
		}
		if(a[i][0]!=0){
			flag = false;
		}
	}
	if(!flag){
		int ans = LLONG_MAX;
		for(int num = 0;num<(1<<k);++num){
			int res = 0;
			int tmp = m;
			for(int i = 1;i<=k;++i){
				if(num&(1<<i-1)){
					res+=a[i][0];
					for(int j = 1;j<=n;++j){
						edges[++m] = {j,n+i,a[i][j]};
						t[m] = edges[m];
					}
				}
			}
			res+=kruskal();
			for(int i = 1;i<=tmp;++i){
				edges[i] = t[i];
			}
			m = tmp;
			ans = min(ans,res);
		}
		cout << ans;
	}else{
		for(int i = 1;i<=k;++i){
			for(int j = 1;j<=n;++j){
				edges[++m] = {j,n+i,a[i][j]};
			}
		}
		cout << kruskal();
	}
	return 0;
}
