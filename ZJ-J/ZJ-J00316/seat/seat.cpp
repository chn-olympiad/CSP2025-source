#include<bits/stdc++.h>
using namespace std;
int n , m , a[110] , r;
int main()
{
	freopen("seat.in" , "r" , stdin);
	freopen("seat.out" , "w" , stdout);
	cin >> n >> m;
	cin >> a[1];
	r = a[1];
	int rk = 1;
	int cnt = 0;
	for(int i = 2; i <= n * m; i++)
	{
		cin >> a[i];
		if(a[i] > r) rk++;
	}
	if(rk % n == 0)
	{
		if(rk / n % 2 == 0)
		{
			cout << rk / n << " " << 1;
			return 0; 
		}
		else
		{
			cout << rk / n << " " << n;
			return 0;
		}
	}
	if(rk / m % 2 == 0)
	{
		cout << rk / n + 1 << " " << rk % n;
		return 0;
	}
	cout << rk / n + 1 << " " << n - rk % n + 1;
	return 0;
}