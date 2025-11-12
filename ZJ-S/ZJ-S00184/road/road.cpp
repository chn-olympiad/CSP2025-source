#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e4 + 5, M = 1e6 + 5, K = 15;
int n, m, k, cnt, fa[N << 1];
struct Edge {
	int p1, p2, id;
	ll weight;
};
bool cmp1(Edge x, Edge y) {
	return x.weight < y.weight;
}
bool cmp2(Edge x, Edge y) {
	return x.id < y.id;
}

vector<Edge> e;
ll ans = 2e18, res, val[N][K], cost[K];

int getfa(int x) {
	if(x == fa[x]) {
		return x;
	}
	return fa[x] = getfa(fa[x]);
}


void Kruscal(int x) {
	int cntx = 0;
	for(int i = 0; i < e.size(); i++) {
		int fa1 = getfa(e[i].p1), fa2 = getfa(e[i].p2);
		if(fa1 != fa2) {
			res += e[i].weight;
			fa[fa1] = fa2;
			cntx++;
		}
		if(cntx >= x - 1) {
			break;
		}
	}
	return;
}

int main(){
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin >> n >> m >> k;
	int u, v, w, flag = 1;
	for(int i = 1; i <= m; i++) {
		cin >> u >> v >> w;
		e.push_back((Edge){u, v, i - 1, w});
	}
	for(int i = 0; i < k; i++) {
		cin >> cost[i];
		if(cost[i] != 0) flag = 0;
		int flagg = 0;
		for(int j = 1; j <= n; j++) {
			cin >> val[j][i];
			if(val[j][i] == 0) {
				flagg = 1;
			}
		}
		if(!flagg) flag = 0;
	}
	if(!flag) {
		for(int i = 0; i <= (1 << k) - 1; i++) {
			res = 0, cnt = 0;
			for(int j = 0; j < k; j++) {
				if(i & (1 << j)) {
					cnt++;
					res += cost[j];
					for(int l = 1; l <= n; l++) {
						e.push_back((Edge){n + cnt, l, (int)1e8, val[l][j]});
					}
				}
			}
			sort(e.begin(), e.end(), cmp1);
	//		for(int j = 0; j < e.size(); j++) {
	//			cout << e[j].id << " " << e[j].weight << endl;
	//		}
			for(int j = 1; j <= n + cnt; j++) {
				fa[j] = j;
			}
			Kruscal(n + cnt);
			ans = min(ans, res);
			sort(e.begin(), e.end(), cmp2);
			for(int j = 0; j < cnt * n; j++) {
				e.pop_back();
			}
		}
		cout << ans;
	}
	else {
		for(int j = 0; j < k; j++) {
			for(int i = 1; i <= n; i++) {
				e.push_back((Edge){n + j + 1, i, (int)1e8, val[i][j]});
			}
		}
		for(int i = 1; i <= n + k; i++) {
			fa[i] = i;
		}
		sort(e.begin(), e.end(), cmp1);
		Kruscal(n + k);
		cout << res;
	}
	return 0;
}
