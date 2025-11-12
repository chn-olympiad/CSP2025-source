#include <iostream>
using namespace std;
int main()
{
	int n,q;
	cin >> n >> q;
	string a[n + 5][5],b[q + 5][5];
	for (int i = 1;i <= n;i++)
	{
		for (int j = 1;j <= 2;j++)
		{
			cin >> a[i][j];
		}
	}
	for (int i = 1;i <= q;i++)
	{
		for (int j = 1;j <= 2;j++)
		{
			cin >> b[i][j];
		}
	}
	return 0;
}
