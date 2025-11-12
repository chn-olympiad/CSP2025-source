#include <bits/stdc++.h>
using namespace std;
string s;
int l, a[10], sum;

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);

	cin >> s;
	l = s.size();
	for (int i = 0; i <= l - 1; i++) {
		if (s[i] >= '0' && s[i] <= '9') {
			int k = int(s[i]) - 48;
			a[k]++;
		}
	}
	for (int i = 9; i >= 0; i--) {
		if (a[i] > 0) {
			cout << i;
			a[i]--;
			i++;
		}
	}
	return 0;
}
