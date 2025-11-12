# include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;

int n, m, k;

struct Node
{
	int u;
	int v;
	int w;
	bool operator < (const Node& s) const
	{
		return s.w < w;
	}
}road[N];

int main()
{
	freopen("road.in", "r". stdin);
	freopen("road.out", "w", stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	cin >> n >> m >> k;
	
	cout << "Hello World"  << '\n';
	
	return 0;
}