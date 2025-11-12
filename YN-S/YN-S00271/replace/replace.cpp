#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	int n, q;
	cin >> n >> q;
	string s1, s2, t1, t2;
	for (int i = 1; i <= n; i++) {
		cin >> s1 >> s2;
	}
	for (int i = 1; i <= q; i++) {
		int cnt = 0;
		cin >> t1 >> t2;
		for (int i = 0; i < t1.length(); i++) {
			if (t1[i] != t2[i]) {
				cnt++;
			}
		}
		cout << cnt << endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}