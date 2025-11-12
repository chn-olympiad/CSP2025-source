#include <bits/stdc++.h>
using namespace std;

string s;

long long c[505], plans[505];
const long long mod = 998244353;

bool cmp(long long x, long long y)
{
	return x > y;
}

int main()
{
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	plans[1] = 1;
	for (int i = 2; i <= 500; i++) plans[i] = (plans[i - 1] * i) % mod;
	long long ans = 0, cnt = 0;
	int n, m;
	cin >> n >> m;
	cin >> s;
	for (int i = 1; i <= n; i++) cin >> c[i];
	sort(c + 1, c + n + 1, cmp);
	for (int i = 1; i <= n; i++)
	{
		if (c[i] <= cnt) break;
		if (s[i - 1] == '0') cnt++;
	}
	cout << (plans[m] % mod + plans[n - m] % mod) % mod - 1 << endl;
	return 0;
}
