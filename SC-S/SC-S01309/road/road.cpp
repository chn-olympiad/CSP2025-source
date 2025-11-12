#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e4 + 5;
const int M = 2e6 + 5;
struct edge{
	int u, v, w;
	bool operator <(const edge x)const{return w < x.w;}
}r1[M], r2[M];
int n, m, k, top, Ans;
int c[15], a[15][N];
int fa[N];
bool specA = true;
int find(int x){
	if(x == fa[x])return x;
	return fa[x] = find(fa[x]);
}
void SolveA(){
	top = m;
	for(int i = 1; i <= k; i++)
		for(int j = 1; j <= n; j++)
			r1[++top] = edge{n + i, j, a[i][j]};
	sort(r1 + 1, r1 + top + 1);
	for(int i = 1; i <= n + k; i++)fa[i] = i;
	int cnt = 0;
	for(int i = 1; i <= top; i++){
		int u = r1[i].u, v = r1[i].v, w = r1[i].w;
		int fu = find(u), fv = find(v);
		if(fu != fv)fa[fu] = fv, Ans += w, cnt++;
		if(cnt == n + k - 1)break;
	}
	return cout << Ans << endl, void();
}
void Solve(){
	Ans = 1e18;
	for(int bit = 0; bit < (1 << k); bit++){
		int exist = 0, len = 0;
		top = m;
		for(int i = 1; i <= m; i++)r2[i] = r1[i];
		for(int i = 0; i < k; i++){
			if((bit & (1 << i)) == 0)continue;
			exist++; len += c[i + 1]; 
			for(int j = 1; j <= n; j++)r2[++top] = edge{n + i + 1, j, a[i + 1][j]};
		}
		sort(r2 + 1, r2 + top + 1);
		for(int i = 1; i <= n + k; i++)fa[i] = i;
		int cnt = 0;
		for(int i = 1; i <= top; i++){
			int u = r2[i].u, v = r2[i].v, w = r2[i].w;
			int fu = find(u), fv = find(v);
			if(fu != fv)fa[fu] = fv, len += w, cnt++;
			if(cnt == n + exist - 1)break;
		}
		Ans = min(Ans, len);
	}
	return cout << Ans << endl, void(); 
}
signed main(){
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n >> m >> k;
	for(int i = 1; i <= m; i++){
		int u, v, w;
		cin >> u >> v >> w;
		r1[i] = edge{u, v, w};
	}
	for(int i = 1; i <= k; i++){
		cin >> c[i];
		specA &= (c[i] == 0);
		for(int j = 1; j <= n; j++)cin >> a[i][j];
	}
	if(specA)SolveA();
	else Solve();
	return 0;
}