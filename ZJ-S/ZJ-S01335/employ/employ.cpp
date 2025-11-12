// T4 employ
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int n, m, s[510], c[510], sum; 
ll ans;
string ss;
void solve1() {
	int a[110];
	for (int i = 1; i <= n; i++)
		a[i] = i;
	do {
		int rf = 0;
		for (int i = 1; i <= n; i++) 
			if (s[i] == 0 || rf >= c[a[i]]) rf++;
		if (rf <= n - m) ans++;
	} while (next_permutation(a + 1, a + 1 + n));
	cout << ans;
	exit(0);
}
int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> n >> m;
	cin >> ss;
	for (int i = 0; i < n; i++) {
		s[i + 1] = ss[i] - '0';
		sum += s[i + 1];
	}
	for (int i = 1; i <= n; i++)
		cin >> c[i];
	if (sum == n) cout << 0;
	else if (n <= 10) solve1();
	return 0;
}