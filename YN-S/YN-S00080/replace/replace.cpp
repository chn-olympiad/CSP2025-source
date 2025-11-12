#include <iostream>
using namespace std;
int n, q;
string a[1005];
string b[1005];

int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);

	cin >> n >> q;

	for (int i = 1; i <= n; i++) {

		cin >> a[i] >> b[i];
	}

	while (q--) {
		string s, to;
		cin >> s >> to;
		int ans = 0;

		for (int i = 1; i <= n; i++) {

			int len = s.length() - a[i].length() + 1;

			for (int j = 0; j < len; j++) {

				bool b1 = 0;

				for (int k = 0; k < a[i].length(); k++) {

					if (a[i][k] != s[j + k]) {
						b1 = 1;
					}
				}

				if (b1 == 0) {
					string s1 = s;

					for (int k = 0; k < a[i].length(); k++) {

						s1[j + k] = b[i][k];
					}

					bool b1 = 0;

					for (int k = 0; k < s.length(); k++) {

						if (s1[k] != to[k])
							b1 = 1;

					}

					if (b1 == 0) {
						ans++;
					}

				}
			}
		}

		cout << ans << endl;
	}

	return 0;
}
