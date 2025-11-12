#include <bits/stdc++.h> 
using namespace std;

const int maxn = 2e6 + 5;
typedef long long ll;

int n, m, k, now_m;
ll temp;
ll ans = 1e18;
int a[maxn], b[12][100005];

struct edge {
	int u, v, x;
}e[maxn], g[maxn]; 

bool cmp(edge x, edge y) {
	return x.x < y.x;
}

int fa[maxn];

int _find(int x) {
	return fa[x] == x ? x : fa[x] = _find(fa[x]);
}

bool choose[maxn]; //choose[i]: whether use vertex i

bool used[maxn];
void initMST() {
	sort(e + 1, e + 1 + m, cmp);
	for (int i = 1; i <= n; i++) fa[i] = i;
	int cnt = 0;
	for (int i = 1; i <= m; i++) {
		int u = e[i].u, v = e[i].v, x = e[i].x;
		int fu = _find(u), fv = _find(v);
		if (fu == fv) continue ;
//		cout << u << " " << v << ' ' << x << endl;
		temp += x;
		fa[fu] = fv;
		cnt++;
		used[i] = true;
		if (cnt == n - 1) break;
	}
}

void MST(int num) {
	sort(g + 1, g + 1 + now_m, cmp);
	for (int i = 1; i <= n + k; i++) fa[i] = i;
	int cnt = 0;
//	cout << endl << now_m << ":" <<  endl;
	for (int i = 1; i <= now_m; i++) {
		int u = g[i].u, v = g[i].v, x = g[i].x;
		int fu = _find(u), fv = _find(v);
		if (fu == fv) continue ;
//		cout << u << " " << v << ' ' << x << endl;
		temp += x;
		fa[fu] = fv;
		cnt++;
		if (cnt == n + num - 1) break;
	}
}

void qidong() {
	now_m = m;
	temp = 0; // current cost
	
	for (int i = 1; i <= m; i++) {
		g[i] = e[i];
	}
	int num = 0;
	for (int i = 1; i <= k; i++) {
		if (choose[i]) {
			temp += a[i];
			for (int j =1; j <= n; j++) {
				g[++now_m] = {n + i, j, b[i][j]};
			}
			num++;
		}
		
	}
//	cout << temp << ":: \n";
	MST(num);
//	cout << temp << endl;
	ans = min(ans, temp);
}

void dfs(int now) {
	if (now == k + 1) {
		qidong();
		return ;
	}
	choose[now] = true;
	dfs(now + 1);
	choose[now] = false;
	dfs(now + 1);
}

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> m >> k; 
	
	for (int i = 1; i <= m; i++) {
		scanf("%d %d %d", &e[i].u, &e[i].v, &e[i].x);
//		cin >> e[i].u >> e[i].v >> e[i].x;
//		cout << e[i].u << " " << e[i].v << " " << e[i].x << endl;
	}
	bool all0 = true;
	for (int i = 1; i <= k ;i++) {
		cin >> a[i];
		if (a[i] != 0) all0 = false;
//		cout << a[i] << endl;
		bool found0 = false;
		for (int j = 1; j <= n; j++) {
			cin >> b[i][j];
			if (b[i][j] == 0) found0 = true;
		}
		if (!found0) all0 = false;
	}
	if (all0) {
		for (int i = 1; i <= k; i++) choose[i] = true;
		qidong();
		cout << temp << endl;
		return 0;
	}
	
	
	initMST();
	int mm = 0;
	for (int i = 1; i <= m ;i ++) {
		if (used[i]) e[++mm] = e[i]; 
	}
	m = mm;
	
	dfs(1);
	cout << ans << endl;
		
	
}






