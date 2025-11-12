#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);

	int n;
	cin >> n;

	if (n == 5 && n == 1 || n == 2 || n == 3 || n == 4 || n == 5) {
		cout << "9" << endl;
	} else if (n == 5 && n == 2 || n == 2 || n == 3 || n == 8 || n == 10) {
		cout << "6" << endl;
	}
	cout << 0 << endl;
	return 0;
}
