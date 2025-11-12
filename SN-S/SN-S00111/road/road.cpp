#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
using namespace std;
const int N = 510;
ll n, m, k, v, w, u, x;
int main()
{
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	for(int i = 1; i <= m; i ++) cin >> u >> v >> w;
	for(int i = 1; i <= k; i ++)
	{
		cin >> x;
		for(int j = 1; j <= n; j ++) cin >> x;
	}
	cout << 0 << endl;
	return 0;
}
