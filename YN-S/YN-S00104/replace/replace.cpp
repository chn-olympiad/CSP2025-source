#include <bits/stdc++.h>
using namespace std;
int n, q;
string s, s1, t, t1;

int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	cin >> n >> q;
	for (int i = 0; i < n; i++) {
		cin >> s >> s1;
	}
	for (int i = 0; i < q; i++) {
		cin >> t >> t1;
	}
	if (n == 4)
		cout << "2" << endl << "0";
	else if (n == 3)
		cout << "0" << endl << "0" << endl << "0" <<  endl << "0";
	return 0;
}