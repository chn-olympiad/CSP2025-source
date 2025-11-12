#include <bits/stdc++.h>
using namespace std;
string s;
char a[1000010];
int c;
string ans;

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s;
	int len = s.size();
	for (int i = 0; i < len; i++) {
		if (s[i] <= '9' && s[i] >= '0') {
			a[c++] = s[i];
		}
	}
	sort(a, a + c);
	for (int i = c - 1; i >= 0; i--) {
		ans += a[i];
	}
	cout << ans << endl;
	return 0;
}
