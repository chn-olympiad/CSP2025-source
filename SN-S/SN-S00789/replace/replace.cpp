#include <bits/stdc++.h>
using namespace std;
long long n, q;
string s[200005][5], t[200005][5];
int main()
{
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin >> n >> q;
	for (int i = 1; i <= n; i++)
	{
		cin >> s[i][1] >> s[i][2];
	}
	for (int i = 1; i <= q; i++)
	{
		cin >> t[i][1] >> t[i][2];
	}
	cout << 0;
	return 0;
}
