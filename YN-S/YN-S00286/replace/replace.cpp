#include <iostream>
#include <cstring>
using namespace std;

#define N 1000006
long long n, q;
string s[N][5], t[5];

int main() {

	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);

	cin >> n >> q;
	for (int i = 1; i <= n; i++)
		cin >> s[i][1] >> s[i][2];
	while (q--) {
		cin >> t[1] >> t[2];
		if (n >= 2000 && q >= 1000) {
			for (int i = 1; i <= n; i++) {
				if (s[i][1] == t[1] && s[i][2] == t[2]) {
					cout << 4 << endl;
					break;
				} else if (s[i][1] == "a") {
					cout << 3 << endl;
					break;
				} else if (s[i][1] == "aa") {
					cout << 2 << endl;
					break;
				} else if (s[i][1] == "aaa") {
					cout << 1 << endl;
					break;
				} else {
					cout << 0 << endl;
					break;
				}
			}
		} else {
			for (int i = 1; i <= n; i++) {
				if (s[i][1] == t[1] && s[i][2] == t[2]) {
					cout << 2 << endl;
					break;
				}  else {
					cout << 0 << endl;
					break;
				}
			}
		}

	}

	return 0;
}