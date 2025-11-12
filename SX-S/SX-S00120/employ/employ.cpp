#include <bits/stdc++.h>
using namespace std;
int c[505], ss[505];
const int mod = 998244353;

int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	string s;
	cin >> s;
	for (int i = 1; i <= n; i++) {
		cin >> c[i];
		if (s[i - 1] == '1')
			ss[i] = ss[i - 1] + c[i];
	}
	long long cnt = 0;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '1') {
			for (int j = 1; j <= n; j++) {
				if (ss[j - 1] <= c[i]) {
					cnt++;
					cnt %= mod;
				}
			}
		}
	}
	cout << cnt % mod << endl;
	return 0;
}
