#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

int a[500010];
map <int, int> mp;

int main()
{
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, k;
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		mp[a[i]]++;
	}
	if (mp[1] == n)
	{
		if (k == 0)
		{
			if (n % 2 == 0)
			{
				cout << n * n / 4;
				return 0;
			}
			else
			{
				cout << (n * n - 1) / 4 + 1;
				return 0;
			}
		}
	}
	int cnt = 0;
	for (int i = 1; i <= n; i++)
	{
		int x = 0;
		for (int j = i; j <= n; j++)
		{
			
			x = x ^ a[j];
			if (x == k)
			{
				cnt++;
				i = j;
				break;
			}
		}
		
	}
	cout << cnt;
	return 0;
}
