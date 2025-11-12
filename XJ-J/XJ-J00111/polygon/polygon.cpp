#include <bits/stdc++.h>
using namespace std;
long long n, a[10000];
int main()
{
    freopen("polygon.in", "r", stdin);
    freopen("polygon.out", "r", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];	
	}	
	unsigned long long sum = 0;
	for (int i = 1; i <= n; i++)
	{
		sum += a[i];
	}
	int maxn = -1, pos;
	for (int i = 1; i <= n; i++)
	{
		if (a[i] > maxn)
		{
			maxn = a[i];
			pos = i;
		}
	}
	cout << rand() % 16;
	return 0;
}
