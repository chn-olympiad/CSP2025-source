#include <bits/stdc++.h>
using namespace std;

int paixu(int a, int b, int c) {
	int s[3] = {a, b, c};
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2 - i; j++) {
			if (s[j] < s[j + 1])
				swap(s[j], s[j + 1]);
		}
	}
	return s[1];
}

int paixu2(int a, int b, int c) {
	int s[3] = {a, b, c};
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2 - i; j++) {
			if (s[j] < s[j + 1])
				swap(s[j], s[j + 1]);
		}
	}
	return s[2];
}

int paixu3(int a, int b, int c) {
	int s[3] = {a, b, c};
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2 - i; j++) {
			if (s[j] < s[j + 1])
				swap(s[j], s[j + 1]);
		}
	}
	return s[3];
}



int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int t, n, a1[2], a2[2], a3[3], x1 = 0, x2 = 0, x3 = 0, sum = 0;
	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> n;
		for (int j = 0; j < n; j++) {
			cin >> a1[1] >> a2[1] >> a3[1];
			if (paixu(a1[1], a2[1], a3[1]) == a1[1]) {
				a1[2]++;
				if (a1[2] <= n / 2)
					sum += paixu(a1[1], a2[1], a3[1]);
				else if (paixu(0, a2[1], a3[1]) == a2[1]) {
					a2[2]++;
					if (a2[2] <= n / 2)
						sum += paixu(0, a2[1], a3[1]);
				} else
					sum += paixu(0, 0, a3[1]);
			}



			if (paixu(a1[1], a2[1], a3[1]) == a2[1]) {
				a2[2]++;
				if (a2[2] <= n / 2)
					sum += paixu(a1[1], a2[1], a3[1]);

				else if (paixu(0, a1[1], a3[1]) == a1[1]) {
					a1[2]++;
					if (a1[2] <= n / 2)
						sum += paixu(0, a1[1], a3[1]);
				}

				else
					sum += paixu(0, 0, a3[1]);
			}





			if (paixu(a1[1], a2[1], a3[1]) == a3[1]) {
				a3[2]++;
				if (a3[2] <= n / 2)
					sum += paixu(a1[1], a2[1], a3[1]);
				else if (paixu(0, a2[1], a1[1]) == a1[1]) {
					a1[2]++;
					if (a1[2] <= n / 2)
						sum += paixu(0, a2[1], a1[1]);
				} else
					sum += paixu(0, 0, a2[1]);
			}




			cout << sum << endl;
		}

	}
	return 0;
}
//Ren5Jie4Di4Ling5%