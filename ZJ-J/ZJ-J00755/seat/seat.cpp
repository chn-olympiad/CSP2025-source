#include <bits/stdc++.h>
using namespace std;
const int N = 500;
int n, m, l, a[N], ss;

signed main()
{
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n >> m;
	l = n * m;
	for(int i = 1; i <= l; i ++) cin >> a[i];
	ss = a[1];
	sort(a + 1, a + l + 1, greater<int>());
	int cur = 0;
	for(int i = 1; i <= m; i ++)
	{
		if(i & 1)
		{
			for(int j = 1; j <= n; j ++) 
			{
				cur ++;
				if(a[cur] == ss) 
				{
					cout << i << " " << j << '\n';
					return 0;
				}
			}
		}else
		{
			for(int j = n; j >= 1; j --) 
			{
				cur ++;
				if(a[cur] == ss) 
				{
					cout << i << " " << j << '\n';
					return 0;
				}
			}
		}
	}
	return 0;
}

