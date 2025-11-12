#include <bits/stdc++.h>
using namespace std;
int a[1000010];
int j = 0;

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	string s;
	cin >> s;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] - '0' >= 0 && s[i] - '0' <= 9) {
			a[j] = s[i] - '0';
			j++;
		}
	}
	sort(a + 0, a + j);
	for (int i = j - 1; i >= 0; i--) {
		cout << a[i];
	}
	return 0;
}
