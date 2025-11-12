#include <bits/stdc++.h>
using namespace std;
string s;
long long n[1000005], m;

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] >= '0' && s[i] <= '9')
			n[m++] = s[i] - '0';
	}
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < m; j++) {
			if (n[j] < n[j + 1])
				swap(n[j], n[j + 1]);
		}
	}
	for (int i = 0; i < m; i++)
		cout << n[i];
	return 0;
}
//²»Òª0·Ö