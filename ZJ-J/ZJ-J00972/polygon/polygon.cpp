#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e5 + 10, Mod = 998244353;
int n, m;
int cnt;
int a[N];
int op[N];
int C(int x, int y)
{
	if(y > x) return 0;
	return op[x] / op[y] / op[x - y] % Mod;
}
signed main()
{
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		if(a[i] == 1) cnt++;
	}
	sort(a + 1, a + 1 + n);
	if(n == 1 || n == 2) {
		cout << 0;
		return 0;
	}
	if(n <= 3)
	{
		if(a[1] + a[2] > a[3]) cout << 1 << '\n';
		else cout << 0;
		return 0;
	}
	if(n == 4)
	{
		int cc = 0;
		if(a[1] + a[2] > a[3]) cc++;
		if(a[1] + a[2] > a[4]) cc++;
		if(a[2] + a[3] > a[4]) cc++;
		if(a[1] + a[3] > a[4]) cc++;
		if(a[1] + a[2] + a[3] > a[4]) cc++;
		cout << cc << '\n';
		return 0;
	}
	if(n == 5)
	{
		int cc = 0;
		if(a[1] + a[2] > a[3]) cc++;
		if(a[1] + a[2] > a[4]) cc++;
		if(a[1] + a[2] > a[5]) cc++;
		if(a[1] + a[3] > a[4]) cc++;
		if(a[1] + a[3] > a[5]) cc++;
		if(a[1] + a[4] > a[5]) cc++;
		if(a[2] + a[3] > a[4]) cc++;
		if(a[2] + a[3] > a[5]) cc++;
		if(a[2] + a[4] > a[5]) cc++;
		if(a[3] + a[4] > a[5]) cc++;
		if(a[1] + a[2] + a[3] > a[4]) cc++;
		if(a[1] + a[2] + a[3] > a[5]) cc++;
		if(a[1] + a[2] + a[4] > a[5]) cc++;
		if(a[1] + a[3] + a[4] > a[5]) cc++;
		if(a[2] + a[3] + a[4] > a[5]) cc++;
		if(a[1] + a[2] + a[3] + a[4] > a[5]) cc++;
		cout << cc << '\n';
		return 0;
	}
	op[1] = 1;
	int ans = 1;
	for (int i = 2; i <= cnt; i++) op[i] = op[i - 1] * i;
	for (int i = 3; i < cnt; i++)
	{
		ans = ans + C(cnt, i);
		ans = (ans + Mod) % Mod;
	}
	cout << (ans + Mod) % Mod << '\n';
}

