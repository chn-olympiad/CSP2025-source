#include <bits/stdc++.h>
using namespace std;
int arr[500 + 5];

int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	string s;
	cin >> s;
	long long sum = 1;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}
	for (int i = n; i >= 1; i--) {
		sum = sum % 998244353 * i;
	}
	if (m == n) {
		bool flag = true;
		for (int i = 0; i < m; i++) {
			if (int (s.at(i)) == 48) {
				flag = false;
				break;
			}
		}
		if (flag) {
			sum = sum;
		} else {
			sum = 0;
		}
	}
	cout << sum << endl;
	return 0;
}