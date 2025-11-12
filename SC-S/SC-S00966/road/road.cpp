#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

const int MAXN = 1e6 + 50;
int u[MAXN], v[MAXN], w[MAXN], c[11][MAXN];
int n, m, k;

signed main(){
	
	
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);

	
	
	cin >> n >> m >> k;
	int ans = 0;
	for(int i = 1; i <= m; i ++)
	{
		cin >> u[i] >> v[i] >> w[i];
		ans += w[i];
	}
	int pd = 0;
	for(int i = 0; i < k; i ++)
	{
		for(int j = 0; j <= m + k; j ++)
		{
			cin >> c[i][j];
			if(c[i][j] != 0)
			{
				pd = 1;
			}
		}
	}
	if(k == 0 || pd == 0)
		cout << ans;
	
	return 0;
}