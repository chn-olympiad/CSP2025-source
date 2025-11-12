#include <bits/stdc++.h>
using namespace std;
int n, q;
string s1[1000006];
string s2[1000006];
int sum;

int main(void) {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	cin >> n >> q;
	for (int i = 1; i <= n; i++) {
		cin >> s1[i] >> s2[i];
	}
	for (int i = 1; i <= q; i++) {
		bool f = true;
		string q1, q2;
		cin >> q1 >> q2;
		for (int j = 1; j <= n; j++) {
			sum = 0;
			if (s1[j] == s2[j]) {
				cout << 0;
				f = false;
				break;
			}
			if (q1.size() > s1[j].size() || q2.size() > s2[j].size()) {
				cout << 0;
				f = false;
				break;
			}
			if (q1 == s2[j] || q2 == s2[j]) {
				sum++;
			}
		}
		if (f)
			cout << sum;
	}

	return 0;
}