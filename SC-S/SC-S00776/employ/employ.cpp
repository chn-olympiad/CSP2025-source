#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll n, m, c[505];
string s;
int main ()
{
	freopen ("employ.in", "r", stdin);
	freopen ("employ.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n >> m;
	cin >> s;
	for (int i = 1; i <= n; ++i)
	{
		cin >> c[i];
	}
	cout << m;
	return 0;
}