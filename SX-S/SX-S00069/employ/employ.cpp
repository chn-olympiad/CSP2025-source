#include <bits/stdc++.h>

using namespace std;

int m, n;
string s;
int c[501];
vector<int> lis;

int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> n >> m;
	cin >> s;
	for (int i = 1; i <= n; i++) {
		cin >> c[i];
	}
	for (int i = 1; i <= n; i++) {
		lis.push_back(i);
	}
	long long ans = 0;
	int down = 0;
	int acc = 0;
	do {
		down = 0;
		acc = 0;
		bool b1 = false;
		for (int i = 0; i < n; i++) {
			//cout << i << " " << acc <<  " " << lis[i] << endl;
			if (b1)
				break;
			if (down >= c[lis[i]]) {
				down++;
				continue;
			}
			if (s[i] == '0') {
				down++;
				continue;
			}
			acc++;
			if (acc >= m) {
				ans++;
				b1 = true;
				ans %= 998244353;
			}
		}
	} while (next_permutation(lis.begin(), lis.end()));
	cout << ans;
	return 0;
}
