#include <bits/stdc++.h>
using namespace std;
int s[105];

int main() {
	freopen("seat.in" "r" "stdin");
	freopen("seat.out" "w" "stdout");
	int a, b, c, d = 0, f;
	cin >> a >> b;
	for (int i = 1; i <= a * b ; i++) {
		cin >> s[i];
		if (s[i ] > s[1])
			d = d + 1;
	}
	if (d / a % 2 == 1)
		f = b - d % a;
	else
		f =  d % a + 1;
	cout << d / a + 1 << " " << f;

	fclose(stdin);
	fclose(stdout);
	return 0;
}
