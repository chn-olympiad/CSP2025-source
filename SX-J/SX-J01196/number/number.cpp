#include <bits/stdc++.h>
using namespace std;
string s;
int m[1000005];
int n;

inline bool cmp(int a, int b) {
	return a > b;
}

int main() {

	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);

	cin >> s;
	for (int i = 0; i < s.length(); i++) {
		if (s[i] >= '0' && s[i] <= '9') {
			n++;
			m[n] = s[i] - '0';
		}
	}
	stable_sort(m + 1, m + n + 1, cmp);
	for (int i = 1; i <= n; i++) {
		cout << m[i];
	}

	return 0;
}
