#include <bits/stdc++.h>
using namespace std;
string s;
int cnt = 0, a[1000005], sum;

bool abc(int x, int y) {
	return x > y;
}

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s;
	for (int i = 0; i <= s.size(); i++) {
		if (s[i] >= '0' && s[i] <= '9') {
			if (s[i] == '0') {
				sum++;
			}
			a[i] = int(s[i]) - 48;
		}
	}
	sort(a, a + s.size(), abc);
	for (int i = 0; i <= s.size(); i++) {
		if (a[i] != 0) {
			cnt *= 10;
			cnt += a[i];
		}
	}
	for (int i = 0; i <= s.size() - 1; i++) {
		if (a[i] != 0)
			cout << a[i];
	}
	while (sum) {
		sum--;
		cout << 0;
	}
	return 0;
}