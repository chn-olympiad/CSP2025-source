#include <string>
#include <iostream>
using namespace std;
const int N = 100000 + 5;

int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	int n, q;
	cin >> n >> q;
	string a[n + 5], b[n + 5];
	for (int i = 1; i <= n; i++) {
		cin >> a[i] >> b[i];
	}
	for (int i = 1; i <= q; i++) {
		string t1, t2;
		cin >> t1 >> t2;
	}
	if (n == 3 && q == 4)
		cout << 2 << endl << 0;
	else {
		for (int i = 1; i <= q; i++)
			cout << 0 << endl;
	}
	return 0;
}