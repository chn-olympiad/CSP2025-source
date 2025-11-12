#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;
#define endl '\n'
#define int long long
const int MOD = 998244353;
signed main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin >> n;
	vector<int> a(n);
	for(int i = 0;i < n;i++) cin >> a[i];
	if(n <= 3)
	{
		int b = a[0] + a[1] + a[2];
		if(b > a[0] * 2 && b > a[1] * 2 && b > a[2] * 2) cout<<1<<endl;
		else cout<<0<<endl;
		return 0;
	}
	int ans = 0;
	int maxa = 0;
	for(int i = 0;i < n;i++) maxa = max(maxa, a[i]);
	int maxhe = 1;
	for(int i = 1;i <= n;i++)
	{
		maxhe *= i;
	}
	if(maxa <= 1)
	{
		for(int i = 3;i <= n;i++)
		{
			int thehe = 1;
			for(int j = i;j <= n;j++)
			{
				thehe *= j;
			}
			int zuhe = maxhe / (thehe * thehe);
			ans += zuhe;
		}
		cout<<ans % MOD<<endl;
		return 0;
	}
	else
	{
		for(int i = 3;i <= n;i++)
		{
			int thehe = 1;
			for(int j = i;j <= n;j++)
			{
				thehe *= j;
			}
			int zuhe = maxhe / (thehe * thehe);
			ans += zuhe;
			int temp = ans;
			for(int j = 0;j < temp;j++)
			{
				for(int k = 0;k < i;k++)
				{
					int he = (a[k] + a[i]) / (k - i);
					if(a[i] * 2 > he)
					{
						ans--;
					}
				}
			}
		}
		cout<<ans % MOD<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	
	return 0;
}
