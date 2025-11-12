#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	string n;
	long long int ans[10] = {0};
	cin >> n;
	n += '/';
	for (int i = 0; n[i] != '/'; i++) {
		if (n[i] == '9') {
			ans[9]++;
		} else if (n[i] == '8') {
			ans[8]++;
		} else if (n[i] == '7') {
			ans[7]++;
		} else if (n[i] == '6') {
			ans[6]++;
		} else if (n[i] == '5') {
			ans[5]++;
		} else if (n[i] == '4') {
			ans[4]++;
		} else if (n[i] == '3') {
			ans[3]++;
		} else if (n[i] == '2') {
			ans[2]++;
		} else if (n[i] == '1') {
			ans[1]++;
		} else if (n[i] == '0') {
			ans[0]++;
		}
	}
	for (int i = 9; i >= 0; i--) {
		for (int j = 0; j < ans[i]; j++) {
			cout << i ;
		}
	}
	return 0;
}
