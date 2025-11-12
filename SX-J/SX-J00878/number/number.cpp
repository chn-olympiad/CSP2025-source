#include <bits/stdc++.h>
using namespace std;

bool cmp(int a, int b) {
	return a > b;
}
string s;
long long  a[100000010], sum = 0;


int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s;
	int len = s.length();
	for (int i = 0; i < len; i++) {
		if (s[i] >= '0' && s[i] <= '9') {
			a[sum++] = s[i] - '0';
		}
	}
	sort(a, a + sum, cmp);
	bool flag = 1;
	for (int i = 0; i < sum; i++) {
		if (!(a[i] == 0 && flag)) {
			flag = 0;
			cout << a[i];
		}
	}
	if (flag && sum) {
		cout << 0;
	}
	return 0;
}
