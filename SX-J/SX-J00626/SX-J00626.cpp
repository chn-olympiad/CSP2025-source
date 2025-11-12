#include <iostream>
#include <string>
using namespace std;

string s[1000010];
string a[1010];

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s[1000010];
	int len = s.size();
	for (int i = 0; i < len; ++i) {
		if (s[i] >= '0' && s[i] <= '9') {
			a[i] = a[i] + s[i];
		}
	}
	int len1 = a.size();
	for (int i = 0; i < len1; ++i) {
		for (int j = 0; j < len1 - 1; ++j) {
			if (a[j] < a[j + 1]) {
				string b = a[j];
				a[j] = a[j + 1];
				a[j + 1] = b;
			}
		}
	}
	for (int i = 0; i < len1; ++i) {
		cout << a[i];
	}
	return 0;
}