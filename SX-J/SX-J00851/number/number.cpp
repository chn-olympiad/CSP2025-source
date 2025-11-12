#include <bits/stdc++.h>
using namespace std;

/*int pai(string &a) {
	for (int i = 0; i < a.size(); i++) {
		for (int j = a.size() - 1; j > i; j--) {
			if (a[j] > a[i]) {
				int c = a[j];
				a[j] = a[i];
				a[i] = c;

			}
		}

	}
	cout << a;
	return 0;
}
*/
int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	string s;
	string a;
	int j = 0;
	cin >> s;
	if (s.size() == 1) {
		cout << s;
		return 0;
	}
	for (int i = 0; i < s.size(); i++) {
		if (s[i] <= '9') {
			cout << s[i];
		}
	}
	/*	pai(a);
		for (int i = 0; i < a.size(); i++) {
			cout << a[i];
		}

	*/
	return 0;
}
//Shang4Shan3Ruo6Shui4
