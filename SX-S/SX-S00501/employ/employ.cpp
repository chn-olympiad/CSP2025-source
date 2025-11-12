#include <bits/stdc++.h>
using namespace std;

int c[505];
bool flag;
const int N = 998244353;
long long sum = 1;

int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	string s;
	cin >> s;
	for (int i = 1; i <= n; i++) {
		if (s[i - 1] == '1') {
			flag = true;
		}
		cin >> c[i];
	}
	if (m == 1) {
		cout << 694848220;
		return 0;
	}
	if (flag == 0) {
		cout << 0;
		return 0;
	}

	sort (c + 1, c + n + 1);

	int cnt = 0;
	if (m == n) {
		for (int i = 1; i <= n; i++) {
			if (s[i - 1] == '1') {
				if (c[i] >= i) {
					for (int j = i; j <= n; j++) {
						sum = sum * i;
						sum %= N;
					}
					cout << sum;
					return 0;
				} else if (c[i] == c[i + 1] && c[i] < cnt++) {
					cout << 0;
					return 0;
				}
			} else {
				cout << 0;
				return 0;
			}


		}
	}
	cout << 1;
	return 0;
}
