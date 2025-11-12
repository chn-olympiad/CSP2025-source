#include <bits/stdc++.h>
using namespace std;
const int MOD = 998244353;
int n,m;
long long ans;
string a;
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin >> n >> m;
	cin >> a;
	for (int i = 1;i <= n;i++)
	{
		int c;
		cin >> c;
	}
	ans = 1;
	for (int i = 1;i <= n;i++)
	{
		ans *= i;
		ans %= MOD;
	}
	cout << ans;
	return 0;
}
