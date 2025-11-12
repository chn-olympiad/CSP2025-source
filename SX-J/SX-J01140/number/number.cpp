#include <bits/stdc++.h>
using namespace std;
long long l1, v[20];
string s;

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s;
	l1 = s.size();
	for (int i = 0; i < l1; i++) {
		if (s[i] - '0' >= 0 && s[i] - '0' <= 9)
			v[s[i] - '0']++;
	}
	for (int i = 9; i >= 0; i--) {
		for (int j = 1; j <= v[i]; j++)
			cout << i;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}