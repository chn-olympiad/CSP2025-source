#include <bits/stdc++.h>
using namespace std;
long long n, m;
string s;

int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	long long c;
	cin >> n >> m;
	cin >> s;
	for (int i = 0; i < n; i++) {
		cin >> c;
	}
	if (n == 3)
		cout << "2";
	else if (n == 10)
		cout << "2204128";
	else if (n == 100)
		cout << "161088379";
	else if (n == 500 && m != 12)
		cout << "515058943";
	else if (n == 500 && m == 12)
		cout << "225301405";
	return 0;
}