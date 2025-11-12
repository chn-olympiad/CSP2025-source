#include <bits/stdc++.h>
using namespace std;
int n, q;
string s1[5000004], s2[5000002];
string t1, t2;
string y;
int l, r;
int ans;
int ac;

bool s1d(int s, int l, int r) {
	for (int i = l; i <= r; i++) {

		if (s1[s] != "a")
			return false;
	}

	return true;
}

bool s2d(int s, int l, int r) {
	for (int i = l; i <= r; i++) {

		if (s2[s] != "a")
			return false;
	}

	return true;
}

int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	cin >> n >> q;

	for (int i = 1; i <= n; i++) {

		cin >> s1[i] >> s2[i];
	}

	while (q--) {
		ac = 1;
		cin >> t1 >> t2;

		for (int i = 1; i <= t1.size(); i++) {

			if (t1[i] != t2[i] && ac == 1) {
				l = i;
				ac++;
			}

			if (t1[i] != t2[i] && ac == 2) {
				r = i;
				ac++;
			}
		}

		int acc = r - l;

		for (int i = 1; i <= n; i++) {

			for (int j = 1; j <= n; j++) {

				if (s1[i][j] == 'b' && s1d(i, j + 1, j + acc) && s2[i][j + acc] == 'b' && s2d(i, j - acc, j - 1)) {
					ans++;
				}
			}
		}

		cout << ans;
	}

	return 0;
}