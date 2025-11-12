#include <iostream>
using namespace std;

int a[5005];

int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin >> n;
	int sum = 0;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++)
	{
		sum += a[i];
	}
	cout << sum / n + 1;
	return 0;
}
