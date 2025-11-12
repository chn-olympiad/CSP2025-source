#include <bits/stdc++.h>
using namespace std;

int n, k, a[500005], x[500005];

int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;
	for (int i = 1; i <= n; i++) cin >> a[i], x[i] = x[i - 1] ^ a[i];
	int l = 1, ans = 0;
	for (int i = 1; i <= n; i++)
	{
		for (int j = l; j <= i; j++)
		{
			int sum = x[i] ^ x[j - 1];
			if (sum == k)
			{
				ans++, l = i + 1;
				break;
			}
		}
	}
	cout << ans;
}