#include <bits/stdc++.h>
using namespace std;

int main() {
	//freopen("number.in", "r", in);
	//freopen("number.out", "w", out);
	int  i;
	char s;
	cin >> s;

	for (i = 0; i < s.size(); i++) {
		if (s >= '0' && s <= 9) {
			cout << s;
		}
	}
	return 0;
}
