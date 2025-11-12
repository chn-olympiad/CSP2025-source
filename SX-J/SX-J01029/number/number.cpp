#include <bits/stdc++.h>
using namespace std;
string s;
const int N = 1e6+5;
int a[N], cnt;

bool cmp(int x, int y) {
	return x > y;
}

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s;
	int len = s.size();
	for (int i = 0; i < len; i++) {
		if (s[i] - '0' >= 0 && s[i] - '0' < 10) {
			a[i] = s[i] - '0';
		} else {
			cnt++;
		}
	}
	sort(a, a + len, cmp);
	for (int i = 0; i < len - cnt; i++) {
		cout << a[i];
	}
	return 0;
}
