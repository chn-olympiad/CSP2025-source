#include <iostream>
using namespace std;
int n, s;
int a[1000000100];

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		if (a[i] > a[i + 1]) {
			a[i] = a[i + 1];
		}
		if (a[i] + a[i + 1] > a[i] * 2) {
			s++;
		}

	}
	cout << s;
	return 0;
}
