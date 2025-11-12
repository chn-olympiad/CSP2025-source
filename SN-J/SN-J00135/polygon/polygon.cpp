#include<bits/stdc++.h>

using namespace std;

#define int long long

int n;
int a[10000];

int he;
int mx;

int x, y;
int ans;

void input();

signed main()
{
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	
	int i, j;
	
	input();
	if(n == 3)
	{
		if(he > 2 * mx)
		{
			cout << 1;
		}
		else
		{
			cout << 0;
		}
	}
	else
	{
		for(i = 3; i <= n; i++)
		{
			x = 1;
			y = 1;
			for(j = 1; j <= i; j++)
			{
				x = x * j;
				y = y * (n - j + 1);
			}
			ans += y / x;
		}
		cout << ans;
	}
}

void input()
{
	int i;
	
	cin >> n;
	for(i = 1; i <= n; i++)
	{
		cin >> a[i];
		he += a[i];
		mx = max(mx, a[i]);
	}
}
