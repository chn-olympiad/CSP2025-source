#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	string s;
	int p, n = 0;
	char m[10] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
	string q;
	cin >> s;
	n = s.size();
	char s1[1001];
	for (int i = 0; i < n; i++) {
		if (s[i] >= '0' && s[i] <= '9') {
			s1[p] = s[i];
			p++;
		}
	}
	for (int j = 10; j >= 0; j--) {
		for (int i = 0; i < p; i++) {
			if (s1[i] == m[j])
				cout << s1[i];
		}
	}
	return 0;
}
