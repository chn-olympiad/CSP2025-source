#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

long long num[10], i, j, len;
string s;

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);

	cin >> s;
	len = s.length();

	for (i = 0; i < len; i++) {
		if (s[i] >= 48 && s[i] <= 57) {
			num[(int)(s[i] - 48)]++;
		}
	}

	for (i = 9; i >= 0; i--) {
		for (j = 0; j < num[i]; j++) {
			cout << i;
		}
	}

	fclose(stdin);
	fclose(stdout);

	return 0;
}

