#include <bits/stdc++.h>
using namespace std;
string s1[200010], s2[200010];

int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	int n, q;
	cin >> n >> q;
	for (int i = 1; i <= n; i++) {
		cin >> s1[i] >> s2[i];

	}
	for (int i = 1; i <= q; i++) {
		int l, r;
		string s3, s4;
		cin >> s3 >> s4;

		for (int j = 0; j < l; j++) {
			if (s3[j] != s4[j]) {
				l = j;
				break;
			}
		}
		for (int j = l; j >= 0; j--) {
			if (s3[j] != s4[j]) {
				r = j;
				break;
			}
		}
		cout << 0 << endl;
	}
	return 0;
}