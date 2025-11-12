#include <bits/stdc++.h>
using namespace std;

string s;

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s;
	int c = s.size(), n = 0;
	for (int i = 0; i < c; i++) {
		for (int j = 0; j < c; j++) {
			if (s[j] >= 0 and s[j] <= 9) {
				m[j] = s[j];
				n++;
			}
		}
	}
	for (int i = 0; i < n; i++)
		cout << m[i];
	return 0;
}
