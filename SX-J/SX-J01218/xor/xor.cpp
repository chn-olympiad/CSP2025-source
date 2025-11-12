#include <bits/stdc++.h>
using namespace std;
const int N = 5 * 1e5+5;
int n, k, a[N], sum;

string myBIN(int x) {
	string s = "", ans = "";
	int y = x;
	while (y > 0) {
		s += (y % 2 + '0');
		y /= 2;
	}
	for (int i = s.size() - 1; i >= 0; i--)
		ans += s[i];
	return ans;
}

string myXOR(int x, int y) {
	string binx = myBIN(x), biny = myBIN(y), myxor = "";
	int cz = max(binx.size(), biny.size()) - min(binx.size(), biny.size());
	if (binx.size() > biny.size()) {
		for (int i = 0; i < cz; i++) {
			if (binx[i] == '1')
				myxor += '1';
			else
				myxor += '0';
		}
		for (int i = cz; i <= max(binx.size(), biny.size()) - 1; i++) {
			if (binx[i] != biny[i - cz])
				myxor += '1';
			else
				myxor += '0';
		}
	} else {
		for (int i = 0; i < cz; i++) {
			if (biny[i] == '1')
				myxor += '1';
			else
				myxor += '0';
		}
		for (int i = cz; i <= max(binx.size(), biny.size()) - 1; i++) {
			if (binx[i - cz] != biny[i])
				myxor += '1';
			else
				myxor += '0';
		}
	}
	return myxor;
}

string myXOR(string x, string y) {
	string binx = x, biny = y, myxor = "";
	int cz = max(binx.size(), biny.size()) - min(binx.size(), biny.size());
	if (binx.size() > biny.size()) {
		for (int i = 0; i < cz; i++) {
			if (binx[i] == '1')
				myxor += '1';
			else
				myxor += '0';
		}
		for (int i = cz; i <= max(binx.size(), biny.size()) - 1; i++) {
			if (binx[i] != biny[i - cz])
				myxor += '1';
			else
				myxor += '0';
		}
	} else {
		for (int i = 0; i < cz; i++) {
			if (biny[i] == '1')
				myxor += '1';
			else
				myxor += '0';
		}
		for (int i = cz; i <= max(binx.size(), biny.size()) - 1; i++) {
			if (binx[i - cz] != biny[i])
				myxor += '1';
			else
				myxor += '0';
		}
	}
	return myxor;
}

string lrXOR(int l, int r) {
	string s = "", s2 = "";
	bool bl = 1;
	for (int i = l; i <= r; i++) {
		if (i == l)
			s = myBIN(a[l]);
		else
			s = myXOR(s, myBIN(a[i]));
	}
	for (int i = 0; i <= s.size() - 1; i++) {
		if (s[i] == 0 && bl == 1)
			continue;
		else if (s[i] == 1 && bl == 1) {
			bl == 0;
			s2 += s[i];
		} else
			s2 += s[i];
	}
	return s2;
}

int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	string target = myBIN(k);
	for (int i = 1; i <= n; i++) {
		for (int j = i; j <= n; j++) {
			if (myXOR(i, j) == target)
				sum++;
		}
	}
	cout << sum + 1;
	return 0;

}
