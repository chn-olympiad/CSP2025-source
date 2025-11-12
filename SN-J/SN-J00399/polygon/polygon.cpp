#include <bits/stdc++.h>
using namespace std;
const int N = 5e3+5;
int n,a[N],c,b,ans = -1;
int main(void)
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		ans = max(ans,a[i]);
	}
	if (n < 3)
	{
		cout << 0;
		return 0;
	}
	else
	{
		c = a[1] + a[2] + a[3];
		if (c > ans*2)
		{
			
			cout << 1;
			return 0;
		}
		else
		{
			cout << 0;
			return 0;
		}
	}
	return 0;
}
