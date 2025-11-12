#include <bits/stdc++.h>
using namespace std;
int n, q;
string s1[200005], s2[200005], t1, t2;
int ans[200005];

int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	cin >> n >> q;
	for (int i = 0; i < n; i++) {
		cin >> s1[i] >> s2[i];
	}
	for (int i = 0; i < q; i++) {
		string r1 = "", r2 = "";
		cin >> t1 >> t2;
		int len = t1.length();
		for (int j = 0; j < len; j++) {
			if (t1[j] == t2[j]) {
				t1[j] = ' ';
				t2[j] = ' ';
			} else
				break;
		}
		for (int j = len - 1; j > 0; j--) {
			if (t1[j] == t2[j]) {
				t1[j] = ' ';
				t2[j] = ' ';
			} else
				break;
		}
		for (int j = 0; j < len; j++) {
			if (t1[j] != ' ')
				r1 += t1[j];
			if (t2[j] != ' ')
				r2 += t2[j];
		}
		for (int j = 0; j < n; j++) {
			if (r1 == s1[j] && r2 == s2[j])
				ans[i]++;
		}
	}
	for (int i = 0; i < q; i++)
		cout << ans[i] << endl;

	return 0;
}
