#include <bits/stdc++.h>
using namespace std;

int f(char c) {
	if (c >= '0' && c <= '9')
		return 1;
	else
		return 0;
}
int n[1000010];

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	string s;
	cin >> s;
	int a = 0;
	for (int i = 0; i < s.length(); i++) {
		if (f(s[i])) {
			n[a] = (int) (s[i] - '0');
			a++;
		}
	}
	sort(n, n + a);
	for (int i = a - 1; i >= 0; i--) {
		cout << n[i];
	}
	return 0;
}
