#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin >> n;
	int s[n];
	int a[n];
	if (n < 10)
	{
		cout<<n;
		return n;
	}
	for (int i = 1;i <= n;i++)
	{
		s[i] = n % ((i + 1) * 10);
	}
	for (int i = 1;i <= n;i++)
	{
		for (int j = 1;j <= n;j++)
		{
			if (s[j] > a[i])
			{
				a[i] = s[j];
			}
		}
	}
	cout << a;

}
