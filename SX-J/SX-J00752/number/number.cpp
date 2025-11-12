#include <bits/stdc++.h>
using namespace std;
string s;
short num[1000005];
int mum[15];

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s;
	int len = s.size();
	int sum = 1;
	for (int i = 0; i <= len; i++) {
		if ((int)s[i] >= 48 && (int)s[i] <= 57) {
			++mum[(int)s[i] - 48];
			sum++;
		}
	}
	for (int i = 9; i >= 0; i--) {
		for (int j = mum[i]; j >= 1; j--) {
			cout << i;
		}
	}

	return 0;
}
