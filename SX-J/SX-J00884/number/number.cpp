#include <bits/stdc++.h>
using namespace std;
int s[1000005];

bool cnt(int x, int y) {
	if (x >= y)
		return 1;
	else {
		return 0;
	}
}

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	string a;
	cin >> a;
	int n = 0;
	for (int i = 0; i <= sizeof(a) ; i++) {
		if (a[i] - '0' >= 0 && a[i] - '0' <= 9) {
			n++;
			s[n] = a[i] - '0';
		}
	}
//	int sum = 0;
	sort(s + 1, s + n + 1, cnt);
	for (int i = 1; i <= n; i++) {
		//sum = sum * 10 + s[i];
		cout << s[i];
	}
	//cout << sum;
	return 0;
}

