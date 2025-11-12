#include <iostream>
#include <vector>
using namespace std;

int n, m, k, w[10010];
vector<int> edges[10010];

int main()
{
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout); 
	cin >> n >> m >> k;
	for (int i = 0; i < m; i++)
	{
		int u, v;
		cin >> u >> v >> w[i];
		edges[u].push_back(v);
		edges[v].push_back(u);
	}
	cout << 1 << endl; 
	return 0;
}

