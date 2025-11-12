#include <bits/stdc++.h>
using namespace std;
string s;

int t[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, cn, maxx = 0, k;

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s;
	int len = s.size();
	//cout << len;
	for (int i = 0; i <= len - 1; i++) {
		if (s[i] >= '0' && s[i] <= '9') {
			int m = s[i] - '0';
			t[m]++;
			//cout << m << '\n';
			cn++;
		}
	}
	/*for (int i = 0; i <= 9; i++) {
		cout << t[i];

	}*/
	for (int i = 1; i <= cn; i++) {
		maxx = 0;
		for (int j = 0; j <= 9; j++) {
			if (t[j] >= 1) {
				maxx = max(maxx, j);
			}
		}
		t[maxx]--;
		k *= 10;
		k += maxx;
	}
	cout << k;
	return 0;
}