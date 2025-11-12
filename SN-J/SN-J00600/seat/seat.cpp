#include <iostream>
using namespace std;
int n, m, a[200];
int main()
{
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n*m; i++)
	{
		cin >> a[i];
	}
	int num = a[1];
	for(int i = 1 ;i <= n*m; i++)
	{
		for(int j = 1; j < n*m; j++)
		{
			if(a[j] < a[j+1])
			{
				int c = a[j];
				a[j] = a[j+1];
				a[j+1] = c;
			}
		}
	}
	for(int i = 1; i <= n*m; i++)
	{
		if(a[i] == num)
			num = i;
	}
	int ans1, ans2;
	if(num % n == 0)
	{
		 ans1 = num/n;
	}
	else
	{
		ans1 = num/n + 1;
	}
	ans2 = num%n;
	if(ans1 % 2 == 0)
	{
		if(ans2 == 0)
		{
			cout << ans1 << " " << 1 << endl;
		}
		else
		{
			cout << ans1 << " " << n-ans2+1 << endl;
		}
	}
	else
	{
		if(ans2 == 0)
		{
			cout << ans1 << " " << n << endl;
		}
		else
		{
			cout << ans1 << " " << ans2 << endl;
		}
	}
	return 0;
}
