#include <bits/stdc++.h>
using namespace std;
string s;
int c;
int a[1000005];

int main() {
	freopen("number.in", "r", "stdin");
	freopen("number.out", "w", "stdout");
	getline(cin, s);
	int n = s.size();
	for (int i = 0; i < n; i++) {
		if (s[i] >= '0' && s[i] <= '9') {
			c++;
			a[i] = int(s[i]) - 48;
		}
	}
	sort(a, a + c + 1);
	for (int i = c; i > 0; i--) {
		cout << a[i];
	}
	return 0;
}
