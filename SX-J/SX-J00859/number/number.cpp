#include <bits/stdc++.h>
using namespace std;

bool cmp(int a, int b) {
	return a > b;
}

bool is_num(char c) {
	if (c - '0' <= 9 && c - '0' >= 0) {
		return true;
	}
	return false;
}
int a[1000005];

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	string s;
	cin >> s;
	int len = s.size();
	int count = 0;
	for (int i = 0; i < len; i++) {
		if (is_num(s[i])) {
			count++;
			a[count] = s[i] - '0';
		}
	}
	sort(a + 1, a + count + 1, cmp);
	if (a[1] == 0) {
		count = 1;
	}
	for (int i = 1; i <= count; i++) {
		cout << a[i];
	}
	return 0;
}