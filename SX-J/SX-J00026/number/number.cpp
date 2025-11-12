#include <bits/stdc++.h>
using namespace std;
const int N = 1e6+5;
int c = 1, a[N], cnt = 0;
string s;

int main() {
	freopen("number.in","r",stdin);
	freopen("seat.in","w",stdout);
	cin >> s;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] - '0' > 0 && s[i] - '0' < 10) {
			a[c] = s[i] - '0';
			c++;
		}
		if (s[i] - '0' == 0) {
			cnt++;
		}
	}
	c--;
	sort(a + 1, a + 1 + c);
	for (int i = c; i >= 1; i--) {
		cout << a[i];
	}
	if (cnt != 0) {
		for (int i = 1; i <= cnt; i++) {
			cout << 0;
		}
	}
	return 0;
}
