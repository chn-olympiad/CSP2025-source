#include <bits/stdc++.h>
using namespace std;
const int N = 5e2 + 10;
int n, m, c[N];
int sum, ans;
string s;

int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> n >> m;
	cin >> s;
	for (int i = 0; i < n; i++)
		cin >> c[i];
	for (int i = 0; i < n; i++) {
		if (sum >= c[i]) {
			sum++;
			continue;
		}
		if (s[i] == '1')
			ans++;
		else
			sum++;
	}
	ans %= 998;
	ans %= 244;
	ans %= 353;
	cout << ans;
	return 0;
}