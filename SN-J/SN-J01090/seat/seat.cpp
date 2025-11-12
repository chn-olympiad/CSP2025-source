#include <bits/stdc++.h>
using namespace std;

int n,m,a[105];

signed main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	int t;
	for (int i = 1;i <= n;i++)
	{
		for (int j = 1;j <= m;j++)
		{
			int pos = (i-1)*m+j;
			cin >> a[pos];
			if (pos == 1) t = a[pos];
		}
	}
	sort(a+1,a+n*m+1);
	reverse(a+1,a+n*m+1);
	int rnk;
	for (int i = 1;i <= n*m;i++) if (a[i] == t) rnk = i;
	int l = (rnk-1)/n+1,h = rnk-(rnk-1)/n*n;
	if (l%2 == 0) h = n-h+1;
	cout << l << ' ' << h;
	return 0;
}
