#include <bits/stdc++.h>
using namespace std;
string s;
string a;

bool cmp(int x, int y) {
	return x > y;
}

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s;
	sort(s.begin(), s.end(), cmp);

	for (int i = 0; i < s.size(); i++) {
		if (s[i] >= '0' && s[i] <= '9') {
			a = a + s[i];
		}
	}
	cout << a;
	return 0;
}
