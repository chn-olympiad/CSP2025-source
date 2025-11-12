#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1000010;
char s[MAXN];
int a[MAXN];

bool cmp(int x, int y) {
	return x > y;
}

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s;
	int r = 0;
	int len = strlen(s);
	for (int i = 0; i < len; i++) {
		if (s[i] - '0' >= 0 && s[i] - '0' <= 9) {
			r++;
			a[r] = s[i] - '0';
		}
	}
	sort(a + 1, a + 1 + r, cmp);
	for (int i = 1; i <= r; i++) {
		cout << a[i];
	}
	return 0;
}
