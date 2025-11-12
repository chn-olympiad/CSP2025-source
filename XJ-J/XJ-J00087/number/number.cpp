#include <iostream>
#include <string>
#include <cctype>
using namespace std;
int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	string s;
	cin >> s;
	int cnt[10] = {};
	for (char c : s) {
		if (isdigit(c)) {
			cnt[c - '0']++;
		}
	}
	for (int i = 9; i >= 0; i--) {
		int n = cnt[i];
		while (n--) {
			cout << i;
		}
	}
	return 0;
}
