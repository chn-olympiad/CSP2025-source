#include <bits/stdc++.h>
using namespace std;
int n, m, c[500], fra[500];
const int mod = 998244353;
int main()
{
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
	cin >> n >> m;
	string s;
	cin >> s;
	fra[0] = 1;
	for (int i = 1; i <= n; i++)
	{
		cin >> c[i];
		fra[i] = fra[i-1]*i%mod;
	}
	long long ans = 1;
	for (int i = 1; i <= n-m; i++)
	{
		ans = ans*2;
	}
	ans = ans*fra[n];
	ans = ans/(fra[n-m]*fra[m]);
	ans = ans%mod;
	cout << ans << endl;
	return 0;
}
