#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("number.in.txt", "r", stdin);
	freopen("number.out.txt", "w", stdout);
	string s;
	cin >> s;
	int p = s.size();
	int j = 0;
	int ax;
	int sum = -1;
	int m[100000], n[100000];
	for (int i = 0; i < p; i++) {
		if (s[i] >= '0' && s[i] <= '9') {
			if (s[i] == '0') {
				m[j] = 0;

			} else if (s[i] == '1') {
				m[j] = 1;

			} else if (s[i] == '2') {
				m[j] = 2;

			} else if (s[i] == '3') {
				m[j] = 3;

			} else if (s[i] == '4') {
				m[j] = 4;

			} else if (s[i] == '5') {
				m[j] = 5;

			} else if (s[i] == '6') {
				m[j] = 6;

			} else if (s[i] == '7') {
				m[j] = 7;

			} else if (s[i] == '8') {
				m[j] = 8;

			} else if (s[i] == '9') {
				m[j] = 9;

			}
			sum++;
			j++;
		} else {
			continue;
		}
	}
	for (int i = 0; i < sum; i++) {
		for (int q = 0; q < sum; q++) {
			if (m[q] > m[q + 1]) {
				ax = m[q + 1];
				m[q + 1] = m[q];
				m[q] = ax;
			}
		}
	}
	while (sum >= 0) {
		cout << m[sum];
		sum--;
	}
	return 0;
}
