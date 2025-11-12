#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	string s, s1;
	cin >> s;
	int l = s.size();
	int a[l + 5], sum = 0;
	for (int i = 0; i < l; i++) {
		if (s[i] >= '0' && s[i] <= '9') {
			s1[++sum] = s[i];
		}
	}
	for (int i = 1; i <= sum; i++) {
		a[i] = s1[i] - '0';
	}
	sort(a + 1, a + sum + 1);
	if (a[sum] == 0) {
		cout << 0 << endl;
		return 0;
	}
	for (int i = sum; i > 0; i--)
		cout << a[i];
	return 0;
}
