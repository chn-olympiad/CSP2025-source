#include <bits/stdc++.h>
using namespace std;
int n, k, a, t, ans, k1;
string s[500005], sum, sk;

int sp(string a, string b) {
	int T = 0;
	for (int i = 0; i < 20; i++) {
		if (a[i] == b[i])
			T = T;
		else {
			T += pow(2, 20 - 1 - i );
		}
	}
	return T;
}

string sy(string a, string b) {
	for (int i = 0; i < 20; i++) {
		if (a[i] == b[i])
			a[i] = '0';
		else {
			k += pow(2, 20 - 1 - i );
			a[i] = '1';
		}
	}
	return a;
}

int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;
	k1 = k;
	while (k1) {
		t = k1 % 2 + '0';
		sk = (char)t + sk;
		k1 /= 2;
	}
	while (sk.size() < 20) {
		sk = '0' + sk;
	}
	for (int i = 1; i <= n; i++) {
		cin >> a;
		while (a) {
			t = a % 2 + '0';
			s[i] = (char)t + s[i];
			a /= 2;
		}
		while (s[i].size() < 20) {
			s[i] = '0' + s[i];
		}
	}
	for (int i = 1; i <= n; i++) {
		string sum = s[i];
		if (sum == sk)
			ans++;
		else {
			for (int j = i + 1; j <= n; j++) {
				sum = sy(sum, s[i]);
				t = sp(sum, s[i]);
				if (t == k) {
					ans ++;
					i = j ;
					break;
				}
			}
		}

	}
	cout  << ans ;
	return 0;
}
