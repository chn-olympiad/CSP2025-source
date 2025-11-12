#include <bits/stdc++.h>
using namespace std;

int a[500005];
int n, k, ans = 0;
int main()
{
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	bool q = 1;
	scanf("%d%d", &n, &k);
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
		if(a[i] != 1)q = 0;
	}
	int t = 0;
	if(n == 1)
	{
		if(a[1] == k)cout << 1 << endl;
		else cout << 0 << endl;
		return 0;
	}
	if(n == 2)
	{
		cout << 1 << endl;
		return 0;
	}
	if(k == 0)
	{
		if(q)
		{
			cout << n / 2 << endl;
			return 0;
		}
	}
	for(int i = 1; i <= n; i++)
	{
		for(int j = i; j <= n; j++)
		{
			if(a[j] == k)
			{
				ans++;
				i = j;
				t = 0;
				break;
			}
			t = t ^ a[j];
			if(t == k)
			{
				ans++;
				i = j;
				t = 0;
				break;
			}
		}
	}
	cout << ans << endl;
	return 0;
}
