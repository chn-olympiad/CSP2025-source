#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	int n, m;
	cin >> n, m;
	string s;
	cin >> s;
	vector<int>c(n);
	for (int i = 0; i < n; i++) {
		cin >> c[i];
	}
	vector<int> order(n);
	for (int i = 0; i < n; i++) {
		order[i] = i;
	}
	int count = 0;
	do {
		int hired = 0;
		int rejected = 0;
		bool valid = true;
		for (int i = 0; i < n; ++i) {
			int candidate = order[i];
			int patience = c[candidate];
			if (rejected >= c[patience]) {
				valid = false;
				break;
			}


			if (s[i] - '0' == 1) {
				hired++;
			} else {
				rejected++;
			}
		}
		if (valid == true && hired >= m) {
			count = (count + 1) % 998244353;
		}
	} while (next_permutation(order.begin(), order.end()));
	cout << count << endl;
	return 0;
}
