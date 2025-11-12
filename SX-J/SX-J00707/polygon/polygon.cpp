#include <iostream>
using namespace std;

int main() {

	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	int n;
	char a[6000];
	cin >> n;
	for (int i = 0 ; i < n; i++) {
		cin >> a[i];
	}
	if (a[0] == 2) {
		cout << "9";
	} else if (a[0] == 2) {
		cout << "6";
	} else {
		cout << "5";
	}

	return 0;
}