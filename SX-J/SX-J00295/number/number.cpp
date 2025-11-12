#include <bits/stdc++.h>
using namespace std;
const int maxN = 1e6+5;
string s;
int a[maxN], cnt;

bool cmp(int a, int b) {
	return a > b;
}

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s;
	for (int i = 0; i < (int)s.size(); i++) {
		if (s[i] >= '0' && s[i] <= '9') {
			a[++cnt] = s[i] - '0';
		}
	}
	sort(a + 1, a + cnt + 1, cmp);
	for (int i = 1; i <= cnt; i++) {
		printf("%d", a[i]);
	}
	return 0;
}
