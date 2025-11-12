#include <bits/stdc++.h>
using namespace std;

string s;
int a[15]; // Ͱ 

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s;
	for (int i = 0; i < s.length(); i++) {
		if (s[i] >= '0' && s[i] <= '9') {
			a[(int)(s[i] - '0')]++;
		}
	}
	for (int i = 9; i >= 0; i--) {
		while (a[i]--)
			cout << i;
	}
	cout << "\n";
	return 0;
} 
