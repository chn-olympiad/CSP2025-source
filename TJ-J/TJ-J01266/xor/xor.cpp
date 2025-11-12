#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll n, k, a[500001], ans = 0, b[500001], m = 1;

int main()
{
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		b[i] = a[i];
		b[i] ^= b[i - 1];
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = m; j <= i; j++)
		{
			if ((b[i] ^ b[j - 1]) == k) 
			{
				m = i + 1;
				ans++;
				break;
			}
		}
	}
	cout << ans;
	return 0;
}
