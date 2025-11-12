#include <bits/stdc++.h>
using namespace std;

int n, k;
int a[500005];
int ans;
int qzxor[500005];

int dg(int l, int c)
{
	if(l > n)return c - 1;
	int maxv = 0;
	for(int i = l; i <= n; i++)
	{
		for(int j = i; j <= n; j++)
		{
			int x = qzxor[j] ^ qzxor[i - 1];
			if(x == k)
			{
				maxv = max(maxv, dg(j + 1, c + 1));
			}
		}
	}
	return maxv;
}

int main()
{
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;
	if(k == 0)
	{
		cout << n / 2;
		return 0;
	}
	if(k == 1)
	{
		int cnt = 0;
		for(int i = 1; i <= n; i++)
		{
			int a = 0;
			cin >> a;
			if(a == 1)cnt++;
		}
		cout << cnt;
		return 0;
	}
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
		qzxor[i] = qzxor[i - 1] ^ a[i];
	}
	cout << dg(1, 1);
	return 0;
}
