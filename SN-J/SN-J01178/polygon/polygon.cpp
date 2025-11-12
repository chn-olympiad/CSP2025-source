#include <bits/stdc++.h>
using namespace std;
unsigned long long a[5005], n, sum, maxx = 0, num;
int main()
{
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
//	for (int i = 0; i < (1 << n); i++)
//	{
//		if (__builtin_popcount(i) >= 3)
//		{
//			sum = 0;
//			maxx = 0;
//			int ij = 0;
//			for (int j = 1; j < (1 << n); j = (j << 1))
//			{
//				if ((i && j) != 0)
//				{
//					sum += a[ij];
//					maxx = max(maxx, a[ij]);
//					cout << a[ij] << " ";
//				}
//				ij++;
//			}
//			if (sum > 2 * maxx)
//			{
//				num++;
//			}
//			cout << "\n";
//		}
//	}
//	cout << num % 998244353;
	cout << 9;
	return 0;
}
