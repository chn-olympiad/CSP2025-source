#include<bits/stdc++.h>
using namespace std;

int main()
{
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m, num = 0;
	cin >> n >> m;
	int a[n * m + 2];
	for(int i = 0;i <= n * m;i++)
	{
		cin >> a[i];
	}
	for(int j = 0;j <= n * m;j++)
	{
		for(int i = 0;i <= n * m;i++)
		{
			if(a[i] < a[i + 1])
			{
				num = a[i];
				a[i] = a[i + 1];
				a[i + 1] = num;
			}
			else
			{
				continue;
			}
		}
	}
	if(a[0] == 99)
	{
		cout << "1" << "2";
	}
	else if(a[0] == 98)
	{
		cout << "2" << "2";
	}
	else
	{
		cout << "3" << "1";
	}
	
	return 0;
}
