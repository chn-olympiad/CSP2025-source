#include <bits/stdc++.h>
using namespace std;
int n, m, c[510], b[510], MOD = 998244353;
unsigned long long ans;
string s;
long long j(int x)
{
	if (x == 1) return 1;
	return x * j(x-1);
}

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(false);
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> n >> m;
	cin >> s;
	bool is1 = true;
	for (int i = 1; i <= n; i++)
	{
		cin >> c[i];
		b[i] = i;
		is1 &= (s[i-1]==1);
	}
	if (is1) cout << j(n) / j(n-m);
	do {
		unsigned long long int fai = 0, cnt = 0;
		for (int i = 1; i <= n; i++)
		{
			if (fai >= c[b[i]])
			{
				fai ++;
				continue;
			} else if (s[i-1] == '1') {
				cnt ++;
				continue;
			} else if (s[i-1] == '0') {
				fai ++;
			}
		}
		if (cnt >= m) ans ++;
	} while (next_permutation(b+1, b+n+1));
	cout << ans % MOD;
}