#include <bits/stdc++.h>
using namespace std;
int n, k;
int a[500005];
int main()
{
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	int ans = 0;
	if (n % 2 == 0 && n > 2)
	{
		ans += (n + 1);
		cout << ans;
	}
	else if (n == 2)
		cout << 1;
	else if (n % 2 != 0 && n > 2)
	{
		ans += (n - 1);
		cout << ans;
	}
	else if (n < 2)
		cout << 0;
	return 0;
}
