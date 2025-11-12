#include <bits/stdc++.h>
using namespace std;
const int N = 5e5+10;
long long a[N], s[N];

string sh1(int x) {
	string s1;
	while (x > 0) {
		s1 = s1 + char(x % 2 + '0');
		x = x / 2;
	}
	return s1;
}

long long sh2(string s5) {
	long long len5 = s5.size(), sum = 0;
	for (int i = 0; i < len5; i++) {
		if (s5[i] == '1')
			sum = sum + pow(2, i);
	}
	return sum;
}

long long yh(int x, int y) {
	string s1 = sh1(x), s2 = sh1(y), s3, s4, s5 = "";
	int len1 = s1.size(), len2 = s2.size(), len3, len4;
	if (len1 > len2)
		s3 = s2, s4 = s1, len3 = len2, len4 = len1;
	else
		s3 = s1, s4 = s2, len3 = len1, len4 = len2;
	for (int i = 1; i <= len4 - len3; i++)
		s3 = s3 + '0';
	for (int i = 0; i < len4; i++) {
		if (s3[i] == s4[i])
			s5 += '0';
		else
			s5 += '1';
	}
	return sh2(s5);
}

int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	long long n, k, maxv1 = 0, m, maxv = 0;
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		if (a[i] == k)
			maxv1++;
	}
	for (int l = 1; l <= n; l++) {
		for (int r = l + 1; r <= n; r++) {
			m = 0;
			for (int i = l; i <= r; i++) {
				if (i == l)
					m = a[i];
				else
					m = yh(m, a[i]);
			}
			if (m == k) {
				maxv++;
			}
		}
	}
	maxv1 += ceil(maxv / 2);
	cout << maxv1;
	return 0;
}

