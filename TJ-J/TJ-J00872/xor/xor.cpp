#include <bits/stdc++.h>
using namespace std;

long long a[500005];

//long long val[500001][500001];
bool flag[500005];

int main()
{
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	long long n, k, cnt = 0;
	cin >> n >> k;
	for (long long i = 1; i <= n; i++)
	{
		scanf("%lld", &a[i]);
	}
	for (int i = 1; i <= n; i++)
	{
		if (a[i] == k && !flag[i])
		{
			cnt++;
			flag[i] = 1;
		}
		if (flag[i]) continue;
		bool chk = 0;
		long long num = a[i], m;
		for (int j = i + 1; j <= n; j++)
		{
			if (flag[j])
			{
				break;
			}
			flag[j] = 1;
			m = j;
			num = num xor a[j];
			if (num == k)
			{
				chk = 1;
				cnt++;
				break;
			}
		}
		if (!chk)
		{
			for (int j = 1; j <= m; j++) flag[j] = 0;
		}
	}
	cout << cnt << endl;
	return 0;
}
