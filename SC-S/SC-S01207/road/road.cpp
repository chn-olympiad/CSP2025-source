#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1e4 + 5;
const int M = 1e6 + 5;

int n, m, k, cnt, ans;
int sa;
int fa[N], c[N], vis[N];

struct edge
{
	int from;
	int to;
	int w;
} e[M];

bool cmp(struct edge x, struct edge y)
{
	return x.w < y.w;
}

int sfa(int x)
{
	if (fa[x] != x) fa[x] = sfa(fa[x]);
	return fa[x];
}

void add(int x, int y)
{
	int fax = sfa(x);
	int fay = sfa(y);
	if (fax != fay) {
		fa[x] = y;
	}
}

signed main()
{
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin >> n >> m >> k;
	
	for (int i = 1; i <= n; i++) fa[i] = i;
	
	for (int i = 1; i <= m; i++) {
		cin >> e[i].from >> e[i].to >> e[i].w;
	}
	int mm = m;
	
	sa = true;
	for (int i = 1; i <= k; i++) {
		cin >> c[i + n];
		if (c[i + n] != 0) sa = false;
		for (int j = 1; j <= n; j++) {
			cin >> e[++m].w;
			e[m].from = i + n, e[m].to = j, e[m].w += c[i + n];
		}
	}
	
	if (sa) {
		cout << 0;
		return 0;
	}
	
	// 最小生成树 
	sort(e + 1, e + 1 + m, cmp);
	m = mm;
	cnt = n;
	for (int i = 1; i <= n; i++) {
//		cout << e[i].from << " " << e[i].to << " " << e[i].w << "\n";
		add(e[i].from, e[i].to);
		if (e[i].from > m) {
			if (vis[e[i].from] == 0) {
				ans += e[i].w;
				vis[e[i].from] = 1;
			} else {
				ans += e[i].w - c[e[i].from];
			}
		}
		else if (e[i].to > m) {
			if (vis[e[i].to] == 0) {
				ans += e[i].w;
				vis[e[i].to] = 1;
			} else {
				ans += e[i].w - c[e[i].to];
			}
		}
		else ans += e[i].w;
		cnt--;
		if (cnt == 0) {
			cout << ans;
			break;
		}
	}
	
	return 0;	 
}