#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin >> n >> k;
	int a[500005];
	for (int i = 1; i<= n;i++)
	{
		cin >> a[i];
		if (a[i] = 1 && k == 0)
		{
			cout << 1;
		}
		else if (a[i] >= 0 && a[i] <= 1)
		{
			if (k == 1)
			{
				cout << 1;
			}
		}
		else if (a[i] >= 0 && a[i] <= 255)
		{
			cout << a[n];
		}
	}
	return 0;
}
