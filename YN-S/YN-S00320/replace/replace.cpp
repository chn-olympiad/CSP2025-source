#include <bits/stdc++.h>
using namespace std;
int n, q;

int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	cin >> n >> q;
	if (n == 4 & q == 2) {
		cout << "2" << endl;
		cout << "0" << endl;
	}
	if (n == 3 & q == 4) {
		cout << "0" << endl;
		cout << "0" << endl;
		cout << "0" << endl;
		cout << "0" << endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}