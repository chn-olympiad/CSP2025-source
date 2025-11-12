#include <bits/stdc++.h>
using namespace std;
string s;
int a[1000000 + 10];

bool cmp (int x, int y) {
	return x > y;
}

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s;
	int str = s.size(), t = 0;
	for (int i = 0; i < str; i++) {
		if (s[i] <= '9' && s[i] >= '0') {
			a[i] = s[i] - '0';
			t++;
		}
	}
	sort(a, a + t, cmp);
	for (int i = 0; i < t; i++) {
		cout << a[i];
	}
	return 0;
}
