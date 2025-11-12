#include <bits/stdc++.h>
using namespace std;
string s;

bool cmp(int a, int b) {
	return a > b;
}
long long a[100000], b = 0;

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] >= '0' && s[i] <= '9') {
			a[b] = s[i] - '0';
			b++;
		}
	}
	sort(a, a + s.size(), cmp);
	for (int i = 0; i < b; i++) {
		cout << a[i];
	}
	return 0;
}
