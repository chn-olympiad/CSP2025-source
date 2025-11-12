//1-4 16 + spj 32 
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n" 
const int inf = 1e18;
int n,m,k;
int u,v,w;
int flag = 1;
int c[15];
int a[15][10005];
int father[30005];
int tot;
int ans;
int cnt;
struct edge{
	int u,v;
	int w;
}e[3000005];
int cmp(edge p,edge q){
	return p.w < q.w;
}
void init(){
	for(int i=0;i<=2*n;i++){
		father[i] = i;
	}
}
int find(int x){
	if(father[x] == x) return x;
	return father[x] = find(father[x]);
}
void merge(int x,int y){
	int u = find(x),v = find(y);
	if(u != v) father[v] = u;
}
void add(int u,int v,int w){
	e[++ tot].u = u;
	e[tot].v = v;
	e[tot].w = w;
}
void kruskal(int need){
	ans = 0;
	cnt = 0;
	init();
	sort(e + 1,e + tot + 1,cmp);
	for(int i=1;i<=tot;i++){
		int u = e[i].u;
		int v = e[i].v;
		int w = e[i].w;
		if(find(u) == find(v)) continue;
		merge(u,v);
		ans += w;
		//cout << u << " " << v << " " << w << endl;
		if(++ cnt == need - 1) return ;
	}
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin >> n >> m >> k;
	for(int i=1;i<=m;i++){
		cin >> u >> v >> w;
		add(u,v,w);
	}
	for(int i=1;i<=k;i++){
		cin >> c[i];
		if(c[i]) flag = 0;
		for(int j=1;j<=n;j++){
			cin >> a[i][j];
		}
	}
	if(flag){
		for(int i=1;i<=k;i++){
			for(int j=1;j<=n;j++){
				add(n + i,j,a[i][j]);
			}
		}
		kruskal(n + k);
		cout << ans;
	}else{
		int res = 1e18;
		for(int i=0;i<(1<<k);i++){
			int pre = 0;
			tot = m;
			for(int j=0;j<k;j++){
				if(i & (1 << j)){//证明第j+1个被取用了 
					for(int p=1;p<=n;p++){
						add(n + j + 1,p,a[j + 1][p]);
					} 
					pre += c[j + 1];
					//cout << j + 1 << " ";
				}
			}
			//tot = m;
			//cout << endl << pre << endl;
			kruskal(n + __builtin_popcount(i));
			//cout << ans << " " << i << endl;
			//if(res > ans + pre) cout << i << endl;
			res = min(res,ans + pre);
			cout << i << endl;
		}
		cout << res;
	}
	return 0;
} 
//如果k=0,则为最小生成树算法 
//先近似跑一遍最短路,然后再最小生成树 
