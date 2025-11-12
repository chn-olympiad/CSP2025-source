#include<bits/stdc++.h>
using namespace std;
int n, k, a[500005];
int main()
{
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	int f1 = 1, f2 = 1;
	cin >> n >> k;
	for(int i=1;i<=n;i++)
	{
		cin >> a[i];
		if(a[i] != 1) f1 = 0;
		if(a[i] != 0 && a[i] != 1) f2 = 0;
	}
	if(f1 == 1)
	{
		cout << n / 2;
		return 0;
	}
	if(f2 == 1)
	{
		if(k == 0)
		{
			int ans1 = 0;
			int res1 = 0;
			int maxn = 0;
			for(int i=1;i<=n;i++)
			{
				res1 ^= a[i];
				if(res1 == 0) ans1 ++;
			}
			int res = 0, ans = 0;
			for(int i=1;i<n;i++)
			{
				if(a[i] == 0)
					res ++;
				else 
					if(a[i] == a[i+1])
						res ++, i ++;
					else res = 0;
				ans = max(ans, res);
			}
			maxn = max(ans1, ans);
			cout << maxn << "\n";
		}
		else
		{
			int cnt = 0;
			for(int i=1;i<=n;i++)
				if(a[i] == 1) cnt ++;
			cout << cnt << "\n";
		}
	}
	
	else
	{
		int maxn1 = 0;
		int maxn2 = 0;
		for(int l=1;l<=n;l++)
		{
			int cnt = 0;
			int res = 0;
			int ans = 0;
			for(int i=l;i<=n;i++)
			{
				res ^= a[i];
				if(res == k)
					ans ++, res = 0;	
			}
			maxn1 = max(maxn1, ans);
		}
		
		for(int l=n;l>=1;l--)
		{
			int cnt = 0;
			int res = 0;
			int ans = 0;
			for(int i=n;i>=l;i--)
			{
				res ^= a[i];
				if(res == k)
					ans ++, res = 0;	
			}
			maxn2 = max(maxn2, ans);
		}
		cout << max(maxn1, maxn2) << "\n";
	}
	return 0;
}
