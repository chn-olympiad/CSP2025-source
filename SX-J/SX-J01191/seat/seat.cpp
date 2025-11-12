#include <iostream>
using namespace std;

int main() {
	freopen("", "w", stdin);
	freopen("", "r", stdout);
	int p, l, xd = 0, a[105] = {0}, jl = 0;
	cin >> p >> l;
	for (int i = 1; i <= p * l; i++) {
		cin >> a[i];
	}
	xd = a[1];
	for (int i = 1; i <= p * l; i++) {
		for (int i = 1; i <= p * l; i++) {
			if (a[i] < a[i + 1] && i + 1 <= p * l) {
				jl = a[i];
				a[i] = a[i + 1];
				a[i + 1] = jl;
			}
		}
	}
	for (int i = 1; i <= p * l; i++) {
		if (xd == a[i]) {
			if (p == 1) {
				cout << i << " 1";
			} else {
				cout << "1 " << i;
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}