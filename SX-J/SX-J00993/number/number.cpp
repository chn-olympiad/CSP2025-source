#include <bits/stdc++.h>
using namespace std;
string s;
const int N = 1e6+10;
int a[N];

int cmp(int a, int b) {
	return a > b;
}

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	long long ai = 0;
	cin >> s;
	for (int i = 0; i < s.size(); i++) {
		if ((s[i] - '0') >= 0 && (s[i] - '0') <= 9) {
			ai++;
			a[ai] = (s[i] - '0');
		}
	}
	sort(a + 1, a + ai + 1, cmp);
	if (a[1] == 0) {
		cout << 0;
		return 0;
	}
	for (int i = 1; i <= ai; i++) {
		cout << a[i];
	}
	return 0;
}
