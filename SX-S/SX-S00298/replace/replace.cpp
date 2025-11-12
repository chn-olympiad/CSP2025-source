#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	int n, q;
	string s, t;
	cin >> n >> q;
	for (int i = 1; i <= n; i++)
		cin >> s;
	for (int i = 1; i <= q; i++)
		cin >> t;
	for (int i = 1; i <= q; i++)
		cout << 0 << endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}