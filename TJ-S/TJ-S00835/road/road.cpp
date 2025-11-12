#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

int main()
{
	int n,m,k; // n座城市，m条路，k个乡镇 
	cin >> n >> m >> k;
	int u[1000005],v[1000005];
	vector <int> w(1000005);//两座城市，修复费用 
	for(int i = 1;i <= m;i++)
	{
		cin >> u[i]>> v[i]>> w[i]; 
	}
	int c[15],a[15][10005];
	for(int j = 1;j <= k;j++)
	{
		cin >> c[j];
		for(int i = 1;i <= n;i++)
		{
			cin >> a[j][i];
		}
	}
	sort(w.begin()，w.end());
	return 0;
}
