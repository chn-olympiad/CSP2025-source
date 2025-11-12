#include <iostream>
#include <vector>
#define int long long
#define F(i, m, n) for(int i = m; i <= n; i++)
using namespace std;
const int N = 1e6+5;
struct Node{
    int v, cost;
    bool have_built;
};
vector<Node> g[10005];
int n, m, k, sum;
int a[15][10005];
void dfs(int u, int s, int p) {
    for(auto x:g[u]) {
        if(x.have_built)continue;

    }
}
signed main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin >> n >> m >> k;
	F(i, 1, m) {
	    int u, v, w;
	    cin >> u >> v >> w;
	    sum+=w;
	}
	F(i, 1, k) {
        F(j, 1, n) {
            cin >> a[i][j];
        }
	}
	cout << sum;
	return 0;
}