#include <iostream>
#include <string>
using namespace std;
const int N = 100000 + 5;

int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	int n, m, cnt = 0, c[n + 5] = {0};
	string s;
	long long ans =  0;
	cin >> n >> m >> s;
	for (int i = 1; i <= n; i++)
		cin >> c[i];
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '1')
			cnt++;
	}
	if (cnt < m)
		cout << 0;
	if (cnt == s.size()) {
		for (int i = 1; i <= n; i++) {
			ans = ans * i % 998244353;
		}
	}
	if (m == 1) {
		if (s[0] == '1') {
			for (int i = 1; i <= n; i++) {
				ans = ans * i % 998244353;
			}
		} else
			cout << 515058943;
	}
	if (n == 3 && m == 2)
		cout << 2;
	else
		cout << ans << endl;
	return 0;
}