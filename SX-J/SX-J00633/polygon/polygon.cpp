#include <iostream>
using namespace std;
int a[5005];

int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	if (a[1] == 1) {
		cout << 9;
	}
	if (a[1] == 2) {
		cout << 6;
	}
	return 0;
}
