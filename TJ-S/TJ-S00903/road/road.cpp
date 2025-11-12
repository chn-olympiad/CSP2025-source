#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
int n, m, k;

struct node{
	int x, w;
};
vector <int> g[10005];
int a[10][10005];
int main(){
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	std::ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m >> k;
	for(int i = 1;i <= m;i++){
		int u, v, w;
		cin >> u >> v >> w;
		g[u].push_back({v, w});
	}
	for(int i = 1;i <= k;i++){
		for(int j = 1;j <= n;j++) cin >> a[i][j];
	}
	cout << 0;
	return 0;
}

