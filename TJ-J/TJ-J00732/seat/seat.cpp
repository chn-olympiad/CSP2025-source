#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	long long n,m,xr,sum = 1,mm = 1,ii = 1;
	cin >> n >> m;
	for (int i = 1;i <= n*m;i++)
	{
		int a;
		cin >> a;
		if (i == 1) xr = a;
		if (a > xr) sum++;
	}
	while (true)
	{
		sum -= n;
		if (sum > n) mm++;
		else 
		{
			if (sum != 0)	mm++;
			if (sum == 0) sum = n;
			if (mm%2 == 0) cout << mm << " " << n-sum+1;
			else	cout << mm << " " << sum;
			break;
		}
	}
	return 0;
}
