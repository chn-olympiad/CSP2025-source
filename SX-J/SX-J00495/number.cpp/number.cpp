#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	string s;
	int num = 0, max = 0;
	cin >> s;
	int len = s.size();


	for (int  i = 0; i < len; i++) {
		if (s[i] >= '0' && s[i] <= '9') {
			cout << s[i];

		}


	}
	

	return 0;
}
