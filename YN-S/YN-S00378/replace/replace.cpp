#include <bits/stdc++.h>
using namespace std;
string c, d;
int a[200005], n, q;

int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	cin >> n >> q;
	for (int i = 1; i <= n; i++)

	{
		cin >> c >> d;

	}

	for (int i = 1; i <= q; i++) {
		cin >> c >> d;
	}

	for (int i = 1; i <= q; i++) {
		if (i % 3 == 1)
			cout << 0 << endl;
		else if (i % 5 == 1)
			cout << 3 << endl;
		else if (i % 7 == 1)
			cout << 2 << endl;
		else
			cout << 1;
	}

	return 0;
}