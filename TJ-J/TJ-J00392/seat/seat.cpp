#include <bits/stdc++.h>
using namespace std;
int a[105], ans;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n, m;
	cin >> n >> m;
	cin >> a[1];
	for (int i = 2; i <= n * m; i ++)
	{
		cin >> a[i];
		if (a[i] >= a[1])
			ans ++;
	}
	cout << ans / n + 1 << " " << ans % n + 1;
	return 0;
}
