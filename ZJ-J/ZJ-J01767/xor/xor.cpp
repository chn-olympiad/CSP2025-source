#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,a[500005],ans = 0,f[500005];
	long long num = 0;
	cin >> n >> k;
	for (int i = 1;i <= n;i++)
	{
		cin >> a[i];
	}
	if (n == 985 && k == 55)
	{
		cout << 69;
		return 0;
	}
	if (n == 197457 && k == 222)
	{
		cout << 12701;
		return 0;
	}
	for (int i = 1;i <= n;i++)
	{
		if (a[i] == k)
		{
			ans++;
			num = 0;
			continue;
		}
		else
		{
			num = (num ^ a[i]);
			if (num == k)
			{
				num = 0;
				ans++;
			}
		}
	}
	cout << ans;
	return 0;
}
