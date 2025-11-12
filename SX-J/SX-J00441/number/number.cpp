#include <bits/stdc++.h>
using namespace std;
string s;
const int N = 1e6+10;
int p[N];

int cmp(int a, int b) {
	return a > b;
}

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s;
	long long len, k = 0;
	len = s.size() - 1;
	for (int i = 0; i <= len; i++) {
		if (s[i] >= '0' && s[i] <= '9') {
			k++;
			p[k] = s[i] - '0';
		}
	}
	sort(p + 1, p + k + 1, cmp);
	if (p[1] == 0) {
		cout << 0;
	} else {
		for (int i = 1; i <= k; i++) {
			cout << p[i];
		}
	}
	return 0;
}
