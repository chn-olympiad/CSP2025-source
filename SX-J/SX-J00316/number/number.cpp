#include <bits/stdc++.h>
using namespace std;
string s;
char c[1000006];

bool cmp(char x, char y) {
	return x > y;
}

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s;
	int j = 1;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] >= '0' && s[i] <= '9') {
			c[j] = s[i];
			j++;
		}
	}
	sort(c + 1, c + 1 + j, cmp);
	if (c[1] == '0') {
		cout << 0;
		return 0;
	}
	for (int i = 1; i <= j; i++) {
		cout << c[i];
	}
	return 0;
}
