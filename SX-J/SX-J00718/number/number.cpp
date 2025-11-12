#include <bits/stdc++.h>
using namespace std;
int a[1000005], tot;
string s;

int main() {
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> s;
	bool f = 0;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] <= '9' && s[i] >= '0') {
			a[++tot] = s[i] - '0';
			if (a[tot] != 0) {
				f = 1;
			}
		}
	}
	if (f == 0) {
		cout << 0;
		return 0;
	}
	sort(a + 1, a + 1 + tot);
	for (int i = tot; i >= 1; i--) {
		cout << a[i];
	}
	return 0;
}
