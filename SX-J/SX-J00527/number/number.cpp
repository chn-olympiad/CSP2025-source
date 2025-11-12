#include <bits/stdc++.h>
using namespace std;
string s;
int a[1000010], k;

bool cmp(int a, int b) {
	return a > b;
}

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s;
	int len = s.size() - 1;
	for (int i = 0; i <= len; i++) {
		if (isdigit(s[i])) {
			a[++k] = s[i] - '0';
		}
	}
	sort(a + 1, a + k, cmp);
	for (int i = 1; i <= k; i++) {
		cout << a[i];
	}
	return 0;
}