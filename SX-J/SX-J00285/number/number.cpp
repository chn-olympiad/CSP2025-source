#include <bits/stdc++.h>
using namespace std;
string s;
int len ;
int sum0 = 0, sum1 = 0, sum2 = 0, sum3 = 0, sum4 = 0, sum5 = 0, sum6 = 0, sum7 = 0, sum8 = 0, sum9 = 0;

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s;
	len = s.size();
	for (int i = 0; i <= len; i++) {
		if (s[i] == '0') {
			sum0++;
		}
		if (s[i] == '1') {
			sum1++;
		}
		if (s[i] == '2') {
			sum2++;
		}
		if (s[i] == '3') {
			sum3++;
		}
		if (s[i] == '4') {
			sum4++;
		}
		if (s[i] == '5') {
			sum5++;
		}
		if (s[i] == '6') {
			sum6++;
		}
		if (s[i] == '7') {
			sum7++;
		}
		if (s[i] == '8') {
			sum8++;
		}
		if (s[i] == '9') {
			sum9++;
		}
	}
	for (int i = 0; i <= len; i++) {
		if (sum9 != 0) {
			cout << 9;
			sum9--;
		}
	}
	for (int i = 0; i <= len; i++) {
		if (sum8 != 0) {
			cout << 8;
			sum8--;
		}
	}
	for (int i = 0; i <= len; i++) {
		if (sum7 != 0) {
			cout << 7;
			sum7--;
		}
	}
	for (int i = 0; i <= len; i++) {
		if (sum6 != 0) {
			cout << 6;
			sum6--;
		}
	}
	for (int i = 0; i <= len; i++) {
		if (sum5 != 0) {
			cout << 5;
			sum5--;
		}
	}
	for (int i = 0; i <= len; i++) {
		if (sum4 != 0) {
			cout << 4;
			sum4--;
		}
	}
	for (int i = 0; i <= len; i++) {
		if (sum3 != 0) {
			cout << 3;
			sum3--;
		}
	}
	for (int i = 0; i <= len; i++) {
		if (sum2 != 0) {
			cout << 2;
			sum2--;
		}
	}
	for (int i = 0; i <= len; i++) {
		if (sum1 != 0) {
			cout << 1;
			sum1--;
		}
	}
	for (int i = 0; i <= len; i++) {
		if (sum0 != 0) {
			cout << 0;
			sum0--;
		}
	}
	return 0;
}
