#include <bits/stdc++.h>
using namespace std;
int a[100005];

string jz(int x) {
	string s = "";
	while (x) {
		s = char(x % 2 + '0') + s;
		x /= 2;
	}
	return s;
}

int jz2(string s) {
	int sum = 0, t = 1;
	for (int i = s.size() - 1; i >= 0; i--) {
		sum += (s[i] - '0') * t;
		t *= 2;
	}
	return sum;
}

int yihuo(int x, int y) {
	string s1 = jz(x), s2 = jz(y), s3 = "";
	if (s1.size() > s2.size()) {
		while (s1.size() > s2.size()) {
			s2 = '0' + s2;
		}
	} else {
		while (s1.size() < s2.size()) {
			s1 = '0' + s1;
		}
	}
	for (int i = 0; i < s1.size(); i++) {
		if (s1[i] == s2[i]) {
			s3 += '0';
		} else {
			s3 += '1';
		}
	}
	return jz2(s3);
}



int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	int n, k, sum = 0;
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	if (n == 1) {
		if (a[1] == k) {
			cout << 1;
			return 0;
		} else {
			cout << 0;
			return 0;
		}
	}
	if (n == 2) {
		if (a[1] == k && a[2] == k) {
			cout << 2;
			return 0;
		} else {
			if (a[1] == k || a[2] == k) {
				cout << 1;
				return 0;
			} else {
				if (yihuo(a[1], a[2]) == k) {
					cout << 1;
					return 0;
				} else {
					cout << 0;
					return 0;
				}
			}
		}
	}
	if (n == 3) {
		if (a[1] == k && a[2] == k && a[3] == k) {
			cout << 3;
			return 0;
		} else {
			if ((a[1] == k && a[2] == k ) || (a[1] == k && a[3] == k ) || (a[2] == k && a[3] == k)) {
				cout << 2;
				return 0;
			} else {
				if (a[1] == k || a[2] == k || a[3] == k) {
					cout << 1;
					return 0;
				} else {
					if (yihuo(a[1], a[2]) == k || yihuo(a[2], a[3]) == k || yihuo(yihuo(a[1], a[2]), a[3]) == k) {
						cout << 1;
						return 0;
					} else {
						cout << 0;
						return 0;
					}
				}

			}
		}
	}
	if (k == 0) {
		for (int i = 1; i <= n; i++) {
			if (a[i] == k) {
				sum++;
			} else {
				if (yihuo(a[i], a[i + 1] == k)) {
					sum++;
					a[i] = -1;
					a[i + 1] = -1;
				} else {
					if (yihuo(yihuo(a[i], a[i + 1]), a[i + 2])) {
						sum++;
						a[i] = -1;
						a[i + 1] = -1;
						a[i + 2] = -1;
					}
				}
			}
		}
		cout << sum;
		return 0;
	}
	if (k == 1) {
		for (int i = 1; i <= n; i++) {
			if (a[i] == k) {
				sum++;
			} else {
				if (a[i] != a[i + 1]) {
					continue;
				} else {
					continue;
				}
			}
		}
		cout << sum;
		return 0;
	}
	for (int i = 1; i <= n; i++) {
		if (a[i] == k) {
			sum++;
			a[i] = -1;
		} else {
			int t = i, s = a[i];
			while (a[t + 1] != -1 && s + a[t + 1] < k && s + a[t + 1] != k) {
				s += yihuo(s, a[t + 1]);
				t++;
			}
			if (s + a[t + 1] == k) {
				sum++;
				i = t;
			}
		}
	}
	cout << sum;
	return 0;
}