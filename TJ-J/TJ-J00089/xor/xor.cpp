#include <iostream>
using namespace std;

int a[500005];

int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	int x = -1;
	int ans1 = a[1];
	int ans2 = a[n];
	int maxn = -1e9;
	int z = 1;
	for (int j = 1; j <= n; j++)
	{
		x++;
		int cnt1 = 0;
		int cnt2 = 0;
		for (int i = 2; i <= x+1; i++)
		{
			ans1 = a[i] & ans1;
			cnt1++;
		}
		z++;
		for (int i = x+z; i <= n-1; i++)
		{
			ans2 = ans2 & a[i];
			cnt2++;
		}
		if (ans1 == ans2)
		{
			maxn = max(maxn,max(cnt1,cnt2));
		}
	}
	cout << maxn << endl;
	return 0;
}
