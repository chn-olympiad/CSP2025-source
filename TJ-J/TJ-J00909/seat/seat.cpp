#include<bits/stdc++.h>
using namespace std;
const int N = 12;
int n,m;
int f[N];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >>n >> m;
	for (int i = 1;i <= n * m;++i)
		cin >> f[i];
	int y = f[1];
	sort(f + 1,f + n * m + 1);
	if (n == 1)
	{
		if (m == 1)
		{
			cout << n << ' ' << m;
			return 0;
		}	
		for (int i = 1;i <= m;++i)
		{
			if (f[i] == y)
			{
				cout << 1 << ' ' << m - i;
				return 0;
			}
		}
			
	}
	if (m == 1)
	{
		for (int i = 1;i <= n;++i)
		{
			if (f[i] == y)
			{
				cout << n - i << ' ' << 1;
				return 0;
			}
		}
	}
	return 0;
}
