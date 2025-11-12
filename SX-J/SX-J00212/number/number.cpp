#include <bits/stdc++.h>
using namespace std;
string s, b, w, jaw, zong;
int cnt;
int ww = -1e9;
int f;

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s;
	int a = s.size();
	for (int i = 0; i < a; i++) {
		if (s[i] >= '0' && s[i] <= '9') {
			b += s[i];
		}
	}

	int bb = b.size();
	for (int i = 0; i < bb; i++) {
		if ((b[i] + '0') - 96 > ww) {
			ww = (b[i] + '0') - 96 ;
		}
	}
	int fu = 0;
	for (int i = 0; i < bb; i++) {
		for (int j = 0; j < bb - 1; j++) {

			if (b[j] < b[j + 1]) {
				fu = b[j];
				b[j] = b[j + 1];
				b[j + 1] = fu;
			}
		}
	}
	cout << b;
	return 0;

}
