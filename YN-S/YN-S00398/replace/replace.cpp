#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 10;
string a[maxn], b[maxn];

int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	int n, q;
	cin >> n >> q;

	for (int i = 1; i <= n; i++) {

		cin >> a[i] >> b[i];
	}

	for (int i = 1; i <= q; i++) {

		string s1, s2;
		int cnt = 0;
		cin >> s1 >> s2;

		for (int j = 1; j <= n; j++) {

			int ans1 = s1.find(a[j]), ans2 = s2.find(b[j]);

			if (ans1 != -1 && ans2 != -1) {
				string x = s1.substr(0, ans1), y = b[j], z = s1.substr(ans1 + b[j].size());

				if (x + y + z == s2) {
					cnt++;
				}
			}
		}

		cout << cnt << endl;
	}

	return 0;
}