#include <bits/stdc++.h>
using namespace std;

int main() {

	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);

	string s;
	int a = 0;
	cin >> s;
	s += "/";
	for (int i = 0; s[i] != 47 ; i++) {
		a++;
	}
	int b[a], c = 0;
	for (int i = 0; s[i] != 47 ; i++) {
		if (s[i] >= 48 && s[i] <= 57) {
			b[c] = s[i];
			c++;
		}
	}
	sort(b, b + c + 1);
	for (int i = 0; i < c; i++) {
		cout << b[i];
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
