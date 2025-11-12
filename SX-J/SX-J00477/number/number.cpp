#include <bits/stdc++.h>
using namespace std;
const int N = 1e6+50;
int a[N], b;
string s;

bool cmp(int x, int y) {
	return x > y;
}

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] >= '0' && s[i] <= '9') {
			a[i] += s[i] - 48;
			b++;
		}
	}
	sort(a, a + s.size(), cmp);
	for (int i = 0; i < b; i++) {
		cout << a[i];
	}
	return 0;
}
