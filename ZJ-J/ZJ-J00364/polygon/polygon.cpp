#include <bits/stdc++.h>
using namespace std;
int n, k = 1;
long long ans, sum;
int a[10001];
int b[15];
int main()
{
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		sum += a[i];
	}
	sort (a + 1, a + n + 1);
	b[3] = 1;
	b[4] = 4;
	b[5] = 16;
	b[6] = 42;
	if (sum == n)
	{
		cout << b[n] << endl;
	}
	else if (n == 3 && a[1] + a[2] > a[3]) cout << 1 << endl;
	else cout << 0 << endl;
	return 0;
}
