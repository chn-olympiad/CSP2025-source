#include<bits/stdc++.h>
using namespace std;
#define For(i, j, k) for(int i = j; i <= k; i++)
#define int long long
#define MaxN 10005
#define MaxM 1000005
#define MaxK 15

struct edge{
	int u, v, w;
	edge(){}
	edge(int U, int V, int W):u(U), v(V), w(W){}
	bool operator<(const edge x) const{
		return w < x.w;
	}
};

int n, m, k, ans = (long long)1e18;
int fa[MaxN], b[MaxN];
int c[MaxK];
int a[MaxK][MaxN];
vector<edge> e, e2;

int find(int x){
	if(fa[x] == x) return x;
	return find(fa[x]);
}

int sol1(){
	int res = 0;
	sort(e.begin(), e.end());
	for(auto[u, v, w] : e){
		if(find(u) == find(v)) continue;
//		cout << "connect " << u << ' ' << v << endl;
		res += w;
		if(fa[v] == v) fa[v] = u;
		else fa[u] = v;
//		fa[u] = find(v);
//		For(i, 1, n) cout << fa[i] << ' ';
//		cout << endl;
	}
	
	return res;
}

void work(){
	int res = 0;
	For(i, 1, n) fa[i] = i;
	For(i, 1, k){
		if(b[i]){
			res += c[i];
			m += n;
			n++;
			For(j, 1, n){
				e.push_back(edge(n, j, a[i][j]));
			}
		}
	}
	For(i, 1, n) fa[i] = i;
	res += sol1();
//	cout << sol1() << endl;
//	cout << "res = " << res << endl;
	ans = min(ans, res);
	For(i, 1, k) if(b[i]) m -= n, n--;
	vector<edge> tmp;
	swap(e, tmp);
	for(auto E : e2){
		e.push_back(E);
	}
}

void dfs(int x){
	if(x == k+1){
		work();
		return ;
	}
	b[x] = 0; dfs(x+1);
	b[x] = 1; dfs(x+1);
}

void sol2(){
	dfs(1);
	cout << ans << endl;
}

void sol3(){
	For(i, 1, k) b[i] = 1;
	work();
	cout << ans << endl;
}

signed main()
{
	freopen("road.in", "r", stdin);
	freopen("road.out","w", stdout);
	cin >> n >> m >> k;
	For(i, 1, n) fa[i] = i;
	For(i, 1, m){
		int u, v, w;
		cin >> u >> v >> w;
		e.push_back(edge(u, v, w));
		e2.push_back(edge(u, v, w));
	}
	int flag = 1;
	For(i, 1, k){
		cin >> c[i];
		For(j, 1, n) cin >> a[i][j];
		if(c[i]) flag = 0;
	}
	if(k == 0){
		cout << sol1() << endl;
	}else if(flag){
		sol3();
	}else if(k <= 5){
//		cout << sol1() << endl;
		sol2();
	}
    return 0;
}
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4
*/