#include <bits/stdc++.h>
using namespace std;
int n, ans;
int a[5005];
//bool used[5005];
const int mod=998244353;
int cmn[5005][5005];
void func()
{
	for(int i = 1; i <= 5000; i++)
	{
		cmn[i][1] = 1;
		cmn[i][i] = 1;
	}
	for(int i = 3; i <= 5000; i++)
		for(int j = 2; j <= i; j++)
		{
			cmn[i][j] = (cmn[i - 1][j - 1] + cmn[i-1][j]) % mod;
		}
}
int main()
{
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for(int i = 1; i <= n; i++)
		cin >> a[i];
	func();
	for(int i = 3; i <= n; i++)
	{
		ans += (cmn[n-1][i-1] % mod);
		ans %= mod;
	}
	cout << ans;
	return 0;
}
