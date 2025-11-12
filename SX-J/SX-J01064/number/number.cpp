#include <bits/stdc++.h>
using namespace std;
string s;
int a[1000005];
int n, t = 1, sum = 0;

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s;
	int len = s.size();
	for (int i = 0; i <= len - 1; i++) {
		if (s[i] - '0' >= 0 && s[i] - '0' <= 9) {
			a[t] = s[i] - '0';
			t++;
		}
	}
	sort(a + 1, a + t + 1);
	for (int i = t; i >= 2; i--) {
		cout << a[i];
	}
	return 0;
}
