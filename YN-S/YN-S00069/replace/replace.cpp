#include <bits/stdc++.h>
using namespace std;
int n, m, ans, len, syd, cs = 0;
string s1, s2, a1, a2;
int p;

int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	cin >> n >> m;

	for (int i = 0; i < m; i++) {

		ans = 0;

		if (p != -1) {
			cin >> s1;
			cin >> s2;
		}


		while (cin >> a1) {
			cin >> a2;

			for (int i = 0; i < len; i++) {

				if (s1[i] == a1[p]) {
					p++;
				} else {
					p = 0;

					if (s1[i] == a1[p]) {
						p++;
					} else {
						p = 0;
					}
				}

				if (p == len - 1) {
					cout << ans << endl;
					ans = 0;
					continue;
				}

			}



			if (n == 0) {
				break;
			}

			n--;
			p = 0;
			len = s1.length();
			syd = a1.length();


			for (int i = 0; i < len; i++) {

				if (s1[i] == a1[p]) {
					p++;
				} else {
					p = 0;

					if (s1[i] == a1[p]) {
						p++;
					} else {
						p = 0;
					}
				}

				if (p == len) {
					break;
				}

				if (p == syd) {
					ans++;
				}
			}


		}

		cout << ans << endl;
	}

	return 0;
}
