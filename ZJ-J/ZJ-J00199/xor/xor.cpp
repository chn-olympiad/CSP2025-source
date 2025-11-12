#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N = 5e5 + 5;

int n, k;
int a[N], c[25];
bool b[25][N];

signed main()
{
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;
	int xx = k, cc = 0;
	while(xx)
	{
		if((xx >> cc) & 1)
		{
			c[cc] = 1;
			xx -= (1 << cc);
		}
		cc++;
	}
	bool A = 1, B = 1;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
		if(a[i] != 1) A = 0;
		if(a[i] > 1) B = 0;
	}
	if(A == 1)
	{
		cout << n / 2 << "\n";
		return 0;
	}
	if(B == 1)
	{
		int res = 0, cnt1 = 0, cnt0 = 0;
		for(int i = 1; i <= n; i++)
		{
			if(a[i] == 1)
			{
				if(k == 0) res += cnt0;
				cnt1++;
				cnt0 = 0;
			}
			if(a[i] == 0)
			{
				if(k == 1) res += cnt1;
				if(k == 0) res += cnt1 / 2;
				cnt0++;
				cnt1 = 0;
			}
		}
		if(cnt1 && k == 1) res += cnt1;
		if(cnt1 && k == 0) res += cnt1 / 2;
		if(cnt0 && k == 0) res += cnt0;
		cout << res << "\n";
		return 0;
	}
	for(int i = 1; i <= n; i++)
	{
		int x = a[i], cnt = 0;
		while(x)
		{
			if((x >> cnt) & 1)
			{
				b[cnt][a[i]] = 1;
				x -= (1 << cnt);
			}
			cnt++;
		}
	}
	/*for(int i = 0; i <= 21; i++)
	{
		for(int j = 1; j <= n; j++)
		{
			if(a[i][j] == )
		}
	}*/
	return 0;
}
