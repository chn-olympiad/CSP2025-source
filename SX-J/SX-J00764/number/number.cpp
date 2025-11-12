#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("number.in", "r", "stdin");
	freopen("number.out", "w", "stdout");
	string s, num;
	string cut;
	cin >> s;
	for (int i = 0; i <= s.size(); i++) {
		if (s[i] >= '0' && s[i] <= '9') {
			num =  num + s[i];
		}
	}
	cout << num ;
	return 0;
}
