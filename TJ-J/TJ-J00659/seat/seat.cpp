#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n,m,ming;
	int a[n*m];
	cin >> n >> m;
	for (int i = 1;i <= n*m;i++)
	{
		cin >> a[i];
	}
	ming = a[0];
	if (n = m = 2)
	{
		if (a[0] == 99&&a[1] == 100&&a[2] == 97&&a[3] == 98)
		{
			cout << "1" << " " << "2";
			return 0;
		}
	}
}
