#include <bits/stdc++.h>
using namespace std;
const int N = 1e6+10;
const int M = 998244353;
string s;
long long num, k, a[N];
bool A;

int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> num >> k;
	cin >> s;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] != '1') {
			A = 1;
		}
	}
	for (int i = 1; i <= num; i++) {
		cin >> a[i];
	}
	if (k == 1) {
		for (int i = 0; i < s.size(); i++) {
			if (s[i] == '1') {
				cout << num;
				return 0;
			}
		}
		cout << 0;
		return 0;
	}
	if (num == k) {
		if (A == 0) {
			cout << 1;
		} else {
			cout << 0;
		}
		return 0;
	}
	if (A == 0) {
		long long op = num;
		for (int i = num - 1; i >= num - k + 1; i--) {
			op *= i;
		}
		long long y = 1;
		for (int i = 1; i <= k; i++) {
			y *= i;
		}
		cout << (op / y) % M;
	}
	return 0;
}
