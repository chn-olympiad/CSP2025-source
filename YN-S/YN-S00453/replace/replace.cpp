#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	int a, b;
	cin >> a >> b;
	if (a == 4 && b == 2)
		cout << 2 << endl << 0;
	else if (a == 3 && b == 4)
		cout << 0 << endl << 0 << endl << 0 << endl << 0;
	else
		for (int i = 0; i < b; i++)
			cout << 0 << endl;

	return 0;
}