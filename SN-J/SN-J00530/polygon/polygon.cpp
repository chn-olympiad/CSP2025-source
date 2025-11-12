#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	long long n,cnt = 0;
	cin >> n;
	if(n > 2)
	{
		for(int i = 0;i <= n;i++)
		{
			for(int j = i+3;j <= n;j++)
			{
				cnt++;
			}
		}
		cnt = 1;
	}
	cout << cnt%998%244%353;
	return 0;
}
