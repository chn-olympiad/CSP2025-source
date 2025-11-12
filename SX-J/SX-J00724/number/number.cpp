#include <bits/stdc++.h>
using namespace std;
string s, r;
int n[10001];

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] >= '0' && s[i] <= '9') {
			r[i] = s[i];
		}
	}
	int max = -1;
	for (int i = 0; i < r.size(); i++) {
		if (r[i] > max) {
			max = r[i];
			cout << max;
		}
	}
	return 0;
}