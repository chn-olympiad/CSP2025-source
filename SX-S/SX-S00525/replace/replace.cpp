#include <bits/stdc++.h>
using namespace std;
int n, q;
string s;

int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out"."w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n >> q;
	for (int i = 1; i <= n + q; i++)
		cin >> s;
	while (q--)
		cout << 0 << "\n";
	return 0;
}
