#include<bits/stdc++.h>
using namespace std;
int a[105];
int main()
{
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	int ai, k;
	for (int i = 1; i <= n * m; i ++)
	{
		cin >> a[i];
		if (i == 1) ai = a[i];
	}
	sort(a + 1, a + n * m + 1);
	for (int i = n * m; i >= 1; i --)
	{
		if (a[i] == ai) k = i; 
	}
	k = n * m - k + 1;
	if (k % n == 0) {cout << k / n << ' ' << ((k / n) % 2 == 0 ? 1 : m);}
	else {cout << k / n + 1 << ' ' << ((k / n + 1) % 2 == 1 ? k - m * (k / n) : m * (k / n + 1) - k);}
} 
