#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	long long n, k;
	cin >> n >> k;
	long long a[100005];
	for (int i = 1;i <= n;i++)
	{
		cin >> a[i];
	}
	int p = 0;
	int sum = 0;
	for (int i = 1;i <= n;i++)
	{
		if (a[i] == k && i > p)
		{
			sum++;
			p = i;
		}
		for (int j = i + 1;j <= n;j++)
		{
			if ((a[i] ^ a[j]) == k && i > p)
			{
				sum++;
				p = j;
			}
		}
	}
	cout << sum;
	return 0;
}
