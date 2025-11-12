#include <iostream>
#include <algorithm>
using namespace std;
int n,m,k,sum = 0;
int main()
{
	cin >> n >> m >> k;
	int a[m+3][5],b[k+3][n+3];
	for (int i = 1;i <= m;i++)
	{
		for (int j = 1;j <= 3;j++)
		{
			cin >> a[i][j];
		}
	}
	for (int i = 1;i <= k;i++)
	{
		for (int j = 1;j <= n + 1;j++)
		{
			cin >> b[i][j];
		}
	}
	int c[m + 3];
	for (int i = 2;i <= m;i++)
	{
		c[i] = a[i][-1];
	}
	sort(c + 1,c + m + 1);
	sum = c[1] + c[2];
	
	cout << sum;
	return 0;
}
