#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	char s[1000005] = {' '};
	int a[15];
	cin >> s;
	for (int i = 0; i <= 1000005; i++) {
		if (int(s[i]) <= int('9') && int(s[i]) >= int('0')) {
			a[int(s[i]) - int('0')]++;
			//cout << a[int(s[i]) - int('0')];
		}
	}

	for (int i = 9; i >= 0; i--) {
		for (int j = 1; j <= a[i]; j++)
			cout << i;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
