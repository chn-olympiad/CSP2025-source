#include <bits/stdc++.h>

using namespace std;

const int N = 2e6 + 5;

struct node{
	int u, v, w;
}ed[N], fl[N];
int vil[N];
int n, m, k;
bool flagA = true;
int fa[N];
bool cmp(node x, node y)
{
	return x.w < y.w;
}

int find(int x)
{
	if(fa[x] == x) return x;
	else return fa[x] = find(fa[x]);
}
void kru()
{
	int res = 0;
	for(int i = 1; i <= n; i ++ ){
		fa[i] = i;
	}
	sort(fl + 1, fl + m + 1, cmp);
	for(int i = 1; i <= m; i ++ ){
		int u = fl[i].u, v = fl[i].v;
		int fu = find(u), fv = find(v);
		if(fu != fv){
			res += fl[i].w;
			fa[fu] = fv;
		}
	}
	cout << res << endl;
}
int main()
{
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> m >> k;
	for(int i = 1; i <= m; i ++ ){
		cin >> ed[i].u >> ed[i].v >> ed[i].w;
		fl[i] = ed[i];
	}
	for(int i = 1; i <= k; i ++ ){
		cin >> vil[i];
		for(int j = 1; j <= n; j ++ ){
			int t; cin >> t;
			if(t != 0) flagA = false;
			ed[i + m] = {i + n, j, t};
		}
	}
	kru();
	return 0;
}