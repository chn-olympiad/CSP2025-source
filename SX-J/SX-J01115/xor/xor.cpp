#include <bits/stdc++.h>
using namespace std;

int txor(int a, int b) {
	if (a == b) {
		return 0;
	} else {
		return 1;
	}


}

int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	int n, k, i, o, j, bol = 1, sum = 0;
	cin >> n >> k;
	int num[n];
	for (i = 0; i < n; i++) {
		cin >> num[i];
	}
	i = 0, j = 1;
	while (i < n) {
		if (bol == 1)
			o = num[i];
		o = txor(o, num[j]);

		if (o == k) {
			sum++;
			if (j + 2 < n) {
				i = j + 1;
				j += 2;
			} else
				break;
		} else if (j + 1 < n) {
			j++;
		} else
			break;



	}
	cout << sum << endl;
	return 0;
}
