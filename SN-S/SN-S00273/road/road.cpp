#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","r",stdout);
	int n,m,k;
	cin >> n >> m >> k;
	int ans = 0;
	int a[100005][3];
	if (k == 0)
	{
		for (int i = 1;i <= m;i++)
		{
			for (int j = 1;j <= 3;j++)
			{
				cin >> a[i][j];
			}
			
		}
		ans += a[i][3];
	}
	cout << ans;
	return 0;
} 
