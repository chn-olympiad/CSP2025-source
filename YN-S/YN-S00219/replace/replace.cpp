#include <bits/stdc++.h>
using namespace std;
string s[200010][2];
string t1, t2;

int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	int n, q;
	cin >> n >> q;
	for (int i = 0; i < n; i++) {
		cin >> s[i][0] >> s[i][1];
	}
	while (q--) {
		int cnt = 0;
		cin >> t1 >> t2;
		for (int i = 0; i < n; i++) {
			if (t1.find(s[i][0]) != -1) {
				int tmp = t1.find(s[i][0]), len = s[i][0].length();
				string ts = t1;
				ts.replace(tmp, len, s[i][1]);
				if (ts == t2)
					cnt++;
			}
		}
		cout << cnt << endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}