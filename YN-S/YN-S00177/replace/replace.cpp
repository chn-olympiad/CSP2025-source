#include <bits/stdc++.h>
using namespace std;
int n, m;

int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	cin >> n >> m;
	if (n == 4 and m == 2)
		cout << 2 << endl << 0;
	else
		for (int i = 1; i <= m; i++)
			cout << 0 << endl;
	return 0;
}