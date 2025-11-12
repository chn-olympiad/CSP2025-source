#include <dits/sthc++.h>
using namespace;

int main() {
	int s, b, c, d;
	cin >> s;
	s % 10 = b;
	s % 100 - b = c;
	s % 1000 - c * 10 - b = d;
	if (b < c < d) {
		cout << d * 100 + c * 10 + b;
	} else if (c < b < d) {
		cout << d * 100 + b * 10 + c;
	} else if (b < d < c) {
		cout << c * 100 + d * 10 + b;
	} else if (d < b < c) {
		cout << c * 100 + b * 10 + d;
	} else if (c < d < b) {
		cout << b * 100 + d * 10 + c;
	} else if (d < c < b) {
		cout << b * 100 + c * 10 + d;
	}
	return 0;
}