#include <bits/stdc++.h>
using namespace std;
string a;
char s[1001];

bool cmp(int c, int b) {
	return c > b;
}

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> a;
	int len = a.size(), sun = 0;
	for (int i = 0; i < len; i++) {
		if (a[i] <= '9' && a[i] >= '0') {
			sun++;
			s[sun] = a[i];

		}
	}
	sort(s + 1, s + sun + 1, cmp);
	for (int i = 1; i <= sun; i++)
		cout << s[i];
	return 0;
}