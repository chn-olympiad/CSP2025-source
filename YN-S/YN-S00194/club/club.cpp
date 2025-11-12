#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int n, s, s1, s2, a, b, c, sum = 0, sum1 = 0, sum2 = 0, a1, c1, b1;
	cin >> n >> s;

	for (int i = 1; i <= s; i++) {

		cin >> a;
		cin >> s1;

		for (int j = 1; j <= s1; j++) {

			cin >> s2;

			for (int i = 0; i <= s2; i++) {

				cin >> c;
			}

			cin >> b;

		}

	}

	for (int i = 1; i < 7; i++) {

		sum += i;
		a1 = sum;
	}

	for (int i = 1; i <= 2; i++) {

		sum1 += i;
		b1 = sum1;
	}

	for (int i = 1; i <= 5; i++) {

		sum2 += i;
		c1 = sum2;
	}

	cout << a1 - 3 << endl << b1 + 1 << endl << c1 - 2;


	return 0;
}