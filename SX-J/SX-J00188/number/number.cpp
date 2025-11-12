#include <bits/stdc++.h>
using namespace std;
bool cmp(int a, int b)
{
	return a > b;
}
int main()
{
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	char a[1000001];
	int n, m = 0, b[100001];
	cin >> a;
	for (int i = 0; i < 1000001; i++)
	{
		if (a[i] < '0' || a[i] > 'z')
		{
			n = i;
			break;
		}
	}
	for (int i = 0; i < n; i++)
	{
		if (a[i] >= '0' && a[i] <= '9')
		{
			b[m] = a[i] - '0';
			m++;
		}
	}
	sort(b, b+m, cmp);
	for (int i = 0; i < m; i++) cout << b[i];
	return 0;
}