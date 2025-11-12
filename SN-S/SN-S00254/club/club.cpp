#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+5;
long long t,n,a[N][8];
long long ans = -1,sum = 0;
int main(void)
{
	cin >> t;
	while (t--)
	{
		cin >> n;
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= 3; j++)
			{
				cin >> a[i][j];
				ans = max(ans,a[i][j]);
			}
			sum = sum + ans;
		}
		cout << sum << endl;
		sum = 0;
		ans = 0;
	}
	return 0;
}
