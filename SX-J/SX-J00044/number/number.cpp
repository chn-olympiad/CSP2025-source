#include <bits/stdc++.h>
using namespace std;
string a;
int s;
int w;
char q;
int main() {
	freopen("number.in", "r", stdin);
	freopen("numder.out", "w", stdout);
	cin >> a;
	s += a.size();
	for (int i = 1; i <= a.size(); i++) {
		if (s == 1) {
			cout << a;
		}
//		else {
//			if (a <= '1' && a <= '9') {
//				to_string (a[i]);
//				w+=a[i];
//			}
//		}
//	}
	return 0;
}
