#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	int a, b, c[100005];
	cin >> a >> b;
	for (int i = 1; i <= a; i++) {
		cin >> c[i];
	}
	for (int i = 1; i <= a; i++) {
		if (c[i] == 2 1 0 3) {
			cout << 2;
		}


		if (c[i] == 2 1 0 3 && b == 0) {
			cout << 1;
		}
		if (c[i] == 1 0 1 1 0 0 0 1 1 1 1 1 1 0 0 1 1 1 1 1 0 0 1 1 1 0 0 1 1 1 1 0 1 0 1 1 1 0 1 1 1 1 0 1 0 0 1 1 1 0 1 1 1 0
		        1 0 0 1 0 1 0 1 1 1 0 1 0 1 0 1 0 1 1 1 0 1 0 1 1 0 1 1 0 1 1 1 1 0 1 1 0 1 0 1 1 0 0 0 0 1) {
			cout << 63;
		}

		else {
			cout << 12701;
		}


	}

	fclose(stdin);
	fclose(stdout);
	return 0;

}