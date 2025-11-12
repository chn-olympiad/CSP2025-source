//吴红燊 SN-S00118 西安湖滨中学
/*
luogu uid:743127
this is the way I still love something
bye,someone
CSP-S2025 RP++
*/
#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef long long ll;
const int T1 = 2e4+20,T2 = 1e6+10,inf = 1e18;
const int T3 = 15;
int n,m,k;
struct ee {
	int u,v,w;
}e[T2],e2[T1],lin[T1],e3[T3][T1];
int g = 0;
bool cmp(ee a,ee b) {
	return a.w < b.w;
}
int c[T3],a[T3][T1];

int fa[T1];
int find(int x) {
	if(fa[x] == x) return x;
	return fa[x] = find(fa[x]);
//	return (fa[x] == x ? x : fa[x] = find(fa[x]));
}
void merge(int x,int y) {
	x = find(x),y = find(y);
	fa[y] = x;
}
int zans = inf;
void init() {
	for(int i = 1;i <= n;i++) fa[i] = i;
	sort(e+1,e+m+1,cmp);
	int lans = 0;
	g = 0;
	for(int i = 1,u,v,w;i <= m;i++) {
		if(g == n-1) break;
		u = e[i].u,v = e[i].v,w = e[i].w;
		if(find(u) != find(v)) {
			merge(u,v);
			lans += w;
			
			g++;
			e2[g] = e[i];
		}
	}
	zans = min(zans,lans);
//	cout << zans << '\n';
}
int lei_val = 0;
int lei_cnt = 0;
void dfs(int ceng) {
	if(ceng > k) return ;
	
	if(ceng == 2) {
		dfs(ceng+1);
		return ;
	}
	//do nothing
	int xia1 = 0,xia2 = 0,lans = 0;
	for(int i = 1;i <= n+k;i++) fa[i] = i;
	ee lin2[T1];
	
	for(int i = 1;i <= g;i++) lin2[i] = lin[i];
	
	lei_val += c[ceng];
	lei_cnt++;
	int lg = g;
	g = 0;
	
	
	int u,v,w;
	while(g < lg+1) {
		if(xia2 == n || (xia1 < lg && lin2[xia1+1].w < e3[ceng][xia2+1].w)) {
			xia1++;
			u = lin2[xia1].u,v = lin2[xia1].v,w = lin2[xia1].w;
		}
		else {
			xia2++;
			u = e3[ceng][xia2].u,v = e3[ceng][xia2].v,w = e3[ceng][xia2].w;
		}
		if(find(u) != find(v)) {
			merge(u,v);
			lin[++g] = (ee){u,v,w};
			lans += w;
			
		}
	}
	zans = min(zans,lans+lei_val);
	dfs(ceng+1);
	
	g = lg;
	for(int i = 1;i <= g;i++) lin[i] = lin2[i];
	lei_val -= c[ceng];
	lei_cnt--;
	
	dfs(ceng+1);
}
void solve() {
	cin >> n >> m >> k;
	for(int i = 1;i <= m;i++) {
		cin >> e[i].u >> e[i].v >> e[i].w;
	}
	for(int i = 1;i <= k;i++) {
		cin >> c[i];
		for(int j = 1;j <= n;j++)
			cin >> a[i][j],e3[i][j] = (ee){i+n,j,a[i][j]};
		sort(e3[i]+1,e3[i]+n+1,cmp);
	}
	zans = inf;
	init();
	g = n-1;
	for(int i = 1;i <= g;i++) lin[i] = e2[i];
	dfs(1);
	cout << zans;
}
signed main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(0);
//	int t;cin >> t;while(t--)
	solve();
	return 0;
}
