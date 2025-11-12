#include <bits/stdc++.h>
using namespace std;
long long a[100005];

bool cmp(int x, int y) {
	return	x > y;
}

int main() {
	freopen("number.in", "r", "stdin");
	freopen("number.out", "w", "stdout");
	string s;
	cin >> s;
	long long ans = 0;
	int n = s.size();
	for (int i = 0; i < s.size(); i++) {
		if (s[i] - '0' >= 0 && s[i] - '0' <= 9) {
			a[i] = s[i] - '0';
			ans++;
		}
	}
	sort(a, a + n, cmp);
	for (int i = 0; i < ans; i++) {
		cout << a[i];
	}
	return 0;
}