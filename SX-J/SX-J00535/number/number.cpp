#include <bits/stdc++.h>
using namespace std;
int a[1000000];
string s;

bool cmp(int p, int q) {
	return p > q;
}

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	getline(cin, s);
	int c = s.size(), sum = 0;
	if (c == 1 and s[0] >= '0' and s[0] <= '9') {
		cout << s;
		return 0;
	}
	for (int i = 0; i < c; i++) {
		if (s[i] >= '0' and s[i] <= '9') {
			a[sum] = s[i] - '0';
			sum++;
		}
	}
	sort(a, a + c, cmp);
	for (int i = 0; i < sum; i++)
		cout << a[i];
	return 0;
}