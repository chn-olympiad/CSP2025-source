#include <bits/stdc++.h>

using namespace std;

int n, m, a[504], ans;
string s;

int main()
{
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> n >> m >> s;
	for (int i = 1;i <= n;i++) cin >> a[i];
	for (int i = 1;i <= n;i++) ans = ans* a[i] - a[i];
	return 0;
}
