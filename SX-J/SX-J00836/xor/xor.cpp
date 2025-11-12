#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	long long a, b;
	cin >> a >> b;
	long long c[a];
	for (int i = 0; i < a; i++)
		cin >> c[i];
	long long sum = 0, ans[a][3];
	for (int i = 0; i < a; i++) {
		int sum1 = c[i];
		for (int j = i; j < a - 1; j++) {
			if (sum1 == b) {
				//cout << i << "  " << j << "\n";
				break;
			}

			else {
				sum1 = sum1 ^c[j + 1];
				//cout << sum1 << "    ";
			}
		}
		//cout << "\n";
		if (sum1 == b) {
			sum++;
		}

	}
	cout << sum;
	return 0;
}









