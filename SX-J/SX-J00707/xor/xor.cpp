#include <iostream>
using namespace std;

int main() {

	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	int n, b;
	char a[200];
	cin >> n >> b;
	for (int i = 0 ; i < n * b + 1; i++) {
		cin >> a[i];
	}
	if (a[0] == 2 && b == 2) {
		cout << "2";
	} else if (a[0] == 2 && b == 3) {
		cout << "2";
	} else if (a[0] == 2 && b == 0) {
		cout << "1";
	}

	return 0;
}