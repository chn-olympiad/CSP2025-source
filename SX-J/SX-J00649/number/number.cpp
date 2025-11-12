#include <bits/stdc++.h>
using namespace std;
string s;
int a[1000005];
int nu;

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] >= '0' and s[i] <= '9') {
			a[++nu] = s[i] - '0';
		}
	}
	sort(a + 1, a + nu + 1);
	if (a[1] == 0) {
		cout << 0;
		return 0;
	}
	for (int i = nu; i > 0; i--) {
		cout << a[i];
	}
	return 0;
}
