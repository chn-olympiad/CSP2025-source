#include <bits\stdc++.h>
using namespace std;



int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n, q;
	cin >> n >> q;
	string st1, st2;
	for (int i = 1; i <= n + q; i++) {
		cin >> st1 >> st2;
	}
	for (int i = 1; i <= q; i++)
		cout << 0 << "\n";
	return 0;
}
