#include <bits/stdc++.h>
using namespace std;

bool cmp(int x, int y) {
	return x > y;
}
string x;

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> x;
	for (int i = 1; i <= s.size(); i++) {
		if (s[i] <= 'a' && s[i] >= 'z') {
			break;
		} else {
			s[i] = sum;
			sum = a;
			a = b;
			b = sum;

		}
		sort(s + 1, s + n + 1, cmp);
		cout << max(s[i], s[i + 1]);
		return 0;
	}
