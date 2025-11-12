#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e6+5;
int a[MAXN];
int n = 0;

bool cmp(int x, int y) {
	return x > y;
}

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	string s;
	cin >> s;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] >= '0' && s[i] <= '9') {
			a[n] = s[i] - '0';
			n++;
		}
	}
	sort(a, a + n, cmp);
	for (int i = 0; i < n; i++) {
		cout << a[i];
	}
	return 0;
}
