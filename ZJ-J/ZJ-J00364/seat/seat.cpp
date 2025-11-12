#include <bits/stdc++.h>
using namespace std;
int n, m, r, k, ansl, ansh;
int a[10001];
int main()
{
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++)
		cin >> a[i];
	r = a[1];
	sort(a + 1, a + m * n + 1);
	for (int i = n * m; i >= 1; i--)
	{
		if (a[i] == r) 
		{
			k = n * m - i + 1;
			break;
		}
	}
	if (k % n == 0) ansl = k / n;
	else ansl = k / n + 1;
	if (ansl % 2 != 0)
	{
		if (k % n == 0) ansh = n;
		else ansh = k % n;
	}
	else 
	{
		if (k % n == 0) ansh = n + 1 - n;
		else ansh = n + 1 - k % n;	
	}
	cout << ansl << " " << ansh << endl;
	return 0;
}
/*
3 3
94 95 96 97 98 99 100 93 92
*/
