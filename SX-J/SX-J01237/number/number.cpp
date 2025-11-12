#include <bits/stdc++.h>
using namespace std;
int a[1000000], b;

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	string s;
	cin >> s;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] >= 'a' && s[i] <= 'z')
			continue;
		else if (s[i] >= '0' && s[i] <= '9') {
			if (s[i] - '0' == 0)
				b++;
			else
				a[i] = s[i] - '0';
		}
	}
	int n = s.size();
	sort(a, a + n);
	for (int i = s.size(); i >= 0; i--) {
		if (a[i] != 0)
			cout << a[i];
	}
	for (int i = 1; i <= b; i++) {
		cout << 0;
	}
	return 0;
}
