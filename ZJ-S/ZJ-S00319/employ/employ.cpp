#include <bits/stdc++.h>
using namespace std;
const int mod = 998244353;
char s[505];
int c[505];
int now[505];
int main()
{
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n, m, cnt = 0, tmp = 1;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		cin >> s[i];
		now[i] = i;
		if (s[i] == '0')
			tmp = 0;
	}
	for (int i = 1; i <= n; i++)
		cin >> c[i];
	do
	{
		int l = 0, res = 0;
		for (int i = 1; i <= n; i++)
		{
			if (c[now[i]] <= l || s[i] == '0')
				l++;
			else
				res++;
		}
		if (res >= m)
			cnt = (cnt + 1) % mod;
	} while (next_permutation(now + 1, now + 1 + n));
	cout << cnt;
	return 0;
}
