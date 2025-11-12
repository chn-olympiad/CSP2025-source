#include<bits/stdc++.h>
using namespace std;
const int mod = 998244353;
int n, m, c[505], f[505][505];
string s;
int main()	{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin >> n >> m >> s;
	for (int i = 1; i <= n; ++i)	cin >> c[i];
	f[0][0] = 1;
	for (int i = 1; i <= n; ++i)	{
		f[i][0] = 1;
		for (int j = 1; j <= m; ++j)	{
			if (j > i)	f[i][j] = 0;
			f[i][j] = (f[i - 1][j] + f[i - 1][j - 1]) % mod;
		}
	}
	cout << f[n][m] << endl;
	return 0;
}
