#include <bits/stdc++.h>
using namespace std;

const int MAXN = 5e5 + 10;

int n;
int k;

int a[MAXN];

int main()
{ 
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> k;
	
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	
	if (k == 0)
	{
		
		int ans = 0;
		
		for (int i = 1; i <= n; i++)
		{
			if (a[i] == 0)
			{
				ans++;
			} 
		}
		
		cout << ans << "\n";
		
	}
	
	else if (k == 1)
	{
		
		int ans = 0;
		
		for (int i = 1; i <= n; i++)
		{
			if (a[i] == 0)
			{
				ans++;
			}
		}
		
		cout << ans << "\n";
		
	}

	return 0;
}
