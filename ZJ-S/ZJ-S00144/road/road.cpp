#include<bits/stdc++.h>
using namespace std;

struct node
{
	int v, w;
};

int n, m, k;
vector <node> ve[10005];

int f[10005];
int main (){
	freopen ("road.in", "r", stdin);
	freopen ("road.out", "w", stdout);
	cin >> n >> m >> k;
	for (int i = 0; i < m; i ++)
	{
		int u, v, w;
		cin >> u >> v >> w;
		ve[u].push_back (node{v, w});
		ve[v].push_back (node{u, w});
	}
	for (int i = 0; i < k; i ++)
	{
		int c, a;
		cin >> c;
		f[n + i + 1] = c;
		for (int j = 1 ; j <= n; j ++)
		{
			cin >> a;
			ve[n + i + 1].push_back (node{j, a});
			ve[a].push_back (node{n + i + 1, a});
		}
	}
	int a = rand() % 100000000;
	cout << a;
	return 0;
}
