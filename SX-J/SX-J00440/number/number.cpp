#include <bits/stdc++.h>
using namespace std;
string s;
char k[1000010];
char b = '0';
char g = '9';
string s1;

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s;
	int l = s.size();
	for (int i = 0; i < l; i++) {
		char h = s[i];
		if (h >= b && h <= g) {
			k[i + 1] = h;
		}
	}
	sort(k + 1, k + l + 1);
	for (int i = l; i >= 1; i--) {
		s1 = s1 + k[i];
	}
	cout << s1 << endl;
	return 0;
}
