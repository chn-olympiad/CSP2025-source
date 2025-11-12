#include <bits/stdc++.h>
using namespace std;
string s, ans;
long long len;
map<int, int>m;

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s;
	len = s.size();
	for (int i = 0; i <= len - 1; i++) {
		if (isdigit(s[i])) {
			if (s[i] == '0') {
				m[0]++;
			}
			if (s[i] == '1') {
				m[1]++;
			}
			if (s[i] == '2') {
				m[2]++;
			}
			if (s[i] == '3') {
				m[3]++;
			}
			if (s[i] == '4') {
				m[4]++;
			}
			if (s[i] == '5') {
				m[5]++;
			}
			if (s[i] == '6') {
				m[6]++;
			}
			if (s[i] == '7') {
				m[7]++;
			}
			if (s[i] == '8') {
				m[8]++;
			}
			if (s[i] == '9') {
				m[9]++;
			}
		}
	}
	for (int i = 9; i >= 0; i--) {
		while (m[i] > 0) {
			ans += to_string(i);
			m[i]--;
		}
	}
	cout << ans;
	return 0;
}
