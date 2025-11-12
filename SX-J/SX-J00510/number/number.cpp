#include <bits/stdc++.h>
using namespace std;
int num[1000000];

int main() {
	freopen("number,in", "r", stdin);
	freopen("number.out", "w", stdout);
	string s;
	cin >> s;
	int n = s.size();
	for (int i = 1; i <= n; i++) {
		num[i] = s[i];
	}
	for (int i = 1; i <= n; i++) {
		swap(num[i], num[i + 1]);
	}
	for (int i = 1; i <= n; i++) {
		cout << num[i];
	}
	return 0;
}
