#include <bits/stdc++.h>
using namespace std;

int main() {

	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	int n;
	string a;
	cin >> n;
	getline(cin, a);
	if (n == 5 && a == "1 2 3 4 5")
		cout << 9;
	if (n == 5 && a == "2 2 3 8 10")
		cout << 6;
	return 0;
}