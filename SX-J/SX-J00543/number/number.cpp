#include <bits/stdc++.h>
using namespace std;
int a[1000050];

int number(int cnt) {
	for (int i = 1; i <= cnt; i++) {
		if (cnt > i)
			return cnt;
	}
}

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	string s;
	cin >> s;
	int len = s.size();
	int cnt = 0;
	for (int i = 1; i <= len; i++) {
		if (s[i] > '0' && s[i] <= '9') {
			cnt = s[i];
		}
		if (number(cnt)) {
			break;
		}
	}
	cout << cnt;
	return 0;
}