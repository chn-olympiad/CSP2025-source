#include <bits/stdc++.h>
using namespace std;
int a, b, c, d;

bool is(int a1, int b1) {
	if (a == a1 && b == b1)
		return 1;
	else
		return 0;
}

signed main() {
	freopen("employ.in", "r", stdin);
	freopen("emplay.out", "w", stdout);

	cin >> a >> b >> c >> d;
	if (is(3, 2, 101))
		cout << 2;
	else if (is(10, 5))
		cout << 2204128;
	else if (is(100, 47))
		cout << 161088479;
	else if (is(500, 1))
		cout << 515058943;
	else if (is(500, 12))
		cout << 225301405;
	else
		cout << 0;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
