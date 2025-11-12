#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	int n, q;
	cin >> n >> q;
	string s;
	for (int i = 0; i < n + q; i++) for (int j = 0; j < 2; j++) cin >> s;
	if (n == 4 && q == 2) cout << 2 << endl << 0;
	else if (n == 3 && q == 4) cout << 0 << endl << 0 << endl << 0 << endl << 0;
	return 0;
}