#include<bits/stdc++.h>
using namespace std;

const int MAXN = 10100;
const int IES = 1e9+10;

struct node {
	int p, dis;
	bool operator>(const node &b) const {
		return dis > b.dis;
	}
};

vector<node> E[MAXN];
int n, m, k, rd[15][MAXN], mi_dis[MAXN];
bool vis[MAXN];
int a[15], cnt, c[15], sz, u, v;
node nd, now;
long long ans, res;

priority_queue< node, vector<node>, greater<node> > p;

void prim_() {
	res = 0;
	for (int i=1; i<=cnt; i++) res += c[a[i]];
	for (int i=1; i<=n+cnt; i++) {
		vis[i] = 0;
		mi_dis[i] = IES;
	}
	while (!p.empty()) p.pop();
	nd.p = 1; nd.dis = 0; mi_dis[1] = 0;
	p.push(nd);
	for (int i=1; i<=n+cnt; i++) {
	//	cout << i << endl;
		while (vis[p.top().p]) p.pop();
	//	if (p.empty()) printf("err\n");
		now = p.top();
		p.pop();
		res += now.dis;
		if (res > ans && ans != -1) return;
	//	cout << now.p << " " << now.dis << endl;
		vis[now.p] = 1;
		if (now.p <= n) {
			sz = E[now.p].size();
			for (int j=0; j<sz; j++) {
				if (!vis[E[now.p][j].p] && E[now.p][j].dis < mi_dis[E[now.p][j].p]) {
					mi_dis[E[now.p][j].p] = E[now.p][j].dis;
					nd = E[now.p][j];
					p.push(nd);
				} 
			}
			for (int j=1; j<=cnt; j++) {
				if (!vis[n + j] && rd[a[j]][now.p] < mi_dis[j+n]) {
					mi_dis[n+j] = rd[a[j]][now.p];
					nd.p = n+j;
					nd.dis = rd[a[j]][now.p];
					p.push(nd);
				}
			}
		} else {
			for (int j=1; j<=n; j++) {
				if (!vis[j] && rd[a[now.p-n]][j] < mi_dis[j]) {
					mi_dis[j] = rd[a[now.p-n]][j];
					nd.p = j;
					nd.dis = rd[a[now.p-n]][j];
					p.push(nd);
				}
			}
		}
	}
}

void dfs(int t) {
	if (t > k) {
//		for (int i=1; i<=cnt; i++) printf("%d ", a[i]);
//		printf("\n-------\n");
		prim_();
//		printf("res= %d\n*********\n", res);
		if (res < ans || ans == -1) ans = res;
		return;
	}
	dfs(t+1);
	cnt ++;
	a[cnt] = t;
	dfs(t+1);
	a[cnt] = 0;
	cnt --;
}

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	scanf("%d%d%d", &n, &m, &k);
	for (int i=1; i<=m; i++) {
		scanf("%d%d%d", &u, &v, &nd.dis);
		nd.p = v;
		E[u].push_back(nd);
		nd.p = u;
		E[v].push_back(nd);
	}
	for (int i=1; i<=k; i++) {
		scanf("%d", &c[i]);
		for (int j=1; j<=n; j++) {
			scanf("%d", &rd[i][j]);
		}
	}
	ans = -1;
	cnt = 0;
	dfs(1);
	printf("%lld\n", ans);
	return 0;
}

