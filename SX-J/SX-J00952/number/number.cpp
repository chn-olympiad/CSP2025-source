#include <bits/stdc++.h>
using namespace std;
char s[1000006];
int a[1000006];

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);

	long long c;
	cin >> s;
	c = strlen(s);
	int z = 1;
	for (int i = 0; i < c; i++) {
		if (s[i] >= '0' && s[i] <= '9') {
			a[z] = s[i] - '0';
			z++;
		}

	}

	sort( a, a + z);
	for (int i = z - 1  ; i >= 1; i--) {
		cout << a[i];
	}

	fclose(stdin);
	fclose(stdout);
	return 0;
}
