#include <bits/stdc++.h>
using namespace std;
int n, k;
bool A = true, B = true, C = true;
int main()
{
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;
	int a[n + 1] = {};
	for(int i = 1; i <= n; i++) cin >> a[i];
	for(int i = 1; i <= n; i++)
	{
		if(a[i] != 1)
		{
			A = false;
			break;
		}
	}
	for(int i = 1; i <= n; i++)
	{
		if(a[i] > 1)
		{
			B = false;
			break;
		}
	}
	for(int i = 1; i <= n; i++)
	{
		if(a[i] > 255)
		{
			C = false;
			break;
		}
	}
	if(A)
	{
		if(n % 2) cout << 0;
		else cout << n / 2;
		return 0;
	}
	if(B)
	{
		int cnt = 0;
		for(int i = 1; i <= n; i++) if(a[i] == 1) cnt++;
		if(cnt % 2)
		{
			if(k == 0) cout << 0;
			else cout << n / 2;
			return 0;
		}
		else
		{
			if(k == 1) cout << 0;
			else cout << n / 2;
			return 0;
		}
	}
	return 0;
}
