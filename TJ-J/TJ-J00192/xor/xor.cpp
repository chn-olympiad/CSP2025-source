#include<bits/stdc++.h>
using namespace std;

long long n, k, a[500005];

int main()
{
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	int d = 0, cnt = 0;
	for(int i = 1; i <= n; i++)
	{
		if(a[i] != k)
		{
			d = d ^ a[i];
			if(d == k)
			{
				cnt++;
				d = 0;
			}
		}
		else
		{
			cnt++;
			d = 0;
		}
	}
	cout << cnt;
	return 0;
}
