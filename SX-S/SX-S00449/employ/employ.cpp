#include <bits/stdc++.h>
using namespace std;
unsigned long long n;
unsigned long long sum = 1;
unsigned long long m;

int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "W", stdout);
	cin >> n >> m;
	string s;
	cin >> s;
	int o = n;
	int b = 0;
	for (int i = 1; i <= o; i++) {
		int a;
		cin >> a;
		if (a == 0) {
			//	cout << "?" << endl;


		}
	}
	if (n < m) {
		cout << 0;
		return 0;
	}
	for (unsigned long long i = n; i >= 1; i--) {
		sum *= i;
		sum %= 998244353;
	}

	cout << sum;
	return 0;
}
