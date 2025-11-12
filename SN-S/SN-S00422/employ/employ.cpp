#include<bits/stdc++.h>
using namespace std;
const int mod = 998244353;

int main()
{
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	string s;
	cin >> s;
	int c[600];
	int ans = 0;
	for(int i = 1; i <= n; i++)
	{
		cin >> c[i];
		ans += c[i];
	}
	cout << ans % mod;
	return 0;
}
