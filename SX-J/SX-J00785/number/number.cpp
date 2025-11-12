#include <bits/stdc++.h>
using namespace std;
string s;

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s;
	int n = s.size();
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= n; j++) {
			if (s[j] < s[j + 1])
				swap(s[j], s[j + 1]);
		}
	}

	for (int i = 0; i < n; i++) {
		if (s[i] >= '0' && s[i] <= '9')
			cout << s[i];
	}
	return 0;
}
