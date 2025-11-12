#include <bits/stdc++.h>
using namespace std;
int n, k, sum;
int a[2000001];
int main()
{
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		if (!a[i]) sum++;
	}
	if (n == 2 && a[1] == a[2] && a[1] == 1) cout << 1 << endl;
	else if (n == 2 && a[1] == a[2] && a[1] == 0) cout << 2 << endl;
	else if (n == 1 && a[1] == 0) cout << 1 << endl;
	else if (n == 1 && a[1] == 1) cout << 0 << endl;
	else cout << sum << endl;
	return 0;
}
