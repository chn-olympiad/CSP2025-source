#include <iostream>
using namespace std;
int main()
{
	int t,sum = 0;
	cin >> t;
	for (int i = 1;i <= t;i++)
	{
		int n;
		cin >> n;
		int a[n][5];
		for (int j = 1;j <= n;j++)
		{
			for (int k = 1;k <= 3;k++)
			{
				cin >> a[j][k];
			}
		}
		for (int j = 1;j <= n;j++)
		{
			int max = 0;
			for (int k = 1;k <= 3;k++)
			{
				if (a[j][k] > max)
				{
					max = a[j][k];
				}
			}
			sum += max;
		}
		cout << sum << endl;
	}
	return 0;
}
