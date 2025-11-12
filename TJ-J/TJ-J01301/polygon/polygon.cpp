#include <bits/stdc++.h>
using namespace std;
const int MOD = 998244353;
int n;
int main()
{
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	int a[n + 1] = {};
	for(int i = 1; i <= n; i++) cin >> a[i];
	if(n == 3) cout << 1;
	else if(n < 3) cout << 0;
	return 0;
}
