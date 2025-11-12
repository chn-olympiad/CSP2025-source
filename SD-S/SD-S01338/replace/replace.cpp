#include <bits/stdc++.h>
using namespace std;
int n, q;
string s1[200005], s2[200005], t1[200005], t2[200005];
int B[200005];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	cin >> n >> q;
	bool flag = false;
	for (int i = 1; i <= n; i++) cin >> s1[i] >> s2[i];
	for (int i = 1; i <= q; i++) cin >> t1[i] >> t2[i];
	for (int i = 1; i <= n; i++) {
		int sum = 0;
		for (char it : s1[i]) {
			if (it != 'a' && it != 'b') {
				sum = 0;
				break;
			}
			sum += (it == 'b');
		}
		if (sum != 1) {
			flag = true;
			break;
		}
		sum = 0;
		for (char it : s2[i]) {
			if (it != 'a' && it != 'b') {
				sum = 0;
				break;
			}
			sum += (it == 'b');
		}
		if (sum != 1) {
			flag = true;
			break;
		}
	}
	for (int i = 1; i <= q; i++) {
		int sum = 0;
		for (char it : t1[i]) {
			if (it != 'a' && it != 'b') {
				sum = 0;
				break;
			}
			sum += (it == 'b');
		}
		if (sum != 1) {
			flag = true;
			break;
		}
		sum = 0;
		for (char it : t2[i]) {
			if (it != 'a' && it != 'b') {
				sum = 0;
				break;
			}
			sum += (it == 'b');
		}
		if (sum != 1) {
			flag = true;
			break;
		}
	}
	if (!flag) {
		for (int i = 1; i <= n; i++) {
			for (int j = 0; j < static_cast<int>(s1[i].length()); j++) {
				if (s1[i][j] == 'b') {
					B[i] = j;
					break;
				}
			}
//			cerr << i << " : " << B[i] << " ";
			for (int j = 0; j < static_cast<int>(s2[i].length()); j++) {
				if (s2[i][j] == 'b') {
					B[i] = j - B[i];
					break;
				}
			}
//			cerr << B[i] << "\n";
		}
//		cerr << "\n";
//		for (int i = 1; i <= n; i++) cerr << B[i] << "\n";
		sort(B + 1, B + n + 1);
		for (int i = 1; i <= q; i++) {
			int pos1 = 0;
			for (int j = 0; j < static_cast<int>(t1[i].length()); j++) {
				if (t1[i][j] == 'b') {
					pos1 = j;
					break;
				}
			}
			for (int j = 0; j < static_cast<int>(t2[i].length()); j++) {
				if (t2[i][j] == 'b') {
					pos1 = j - pos1;
					break;
				}
			}
			int p1 = lower_bound(B + 1, B + n + 1, pos1) - B;
			if (p1 != n + 1 && B[p1] == pos1) {
				cout << upper_bound(B + 1, B + n + 1, pos1) - B - p1 << "\n";
			}
		}
	}
	return 0;
}
/*
3 1
ab ba
aab aba
aba aba
aab aba
*/
