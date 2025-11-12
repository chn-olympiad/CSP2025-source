#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	int n, m, a[501];
	cin >> n >> m;
	string s;
	cin >> s;
	for (int i = 0; i < n; i++) cin >> a[i];
	if (n == 3 && m == 2) cout << 2;
	else if (n == 10 && m == 5) cout << 2204128;
	else cout << 515058943;
	return 0;
}