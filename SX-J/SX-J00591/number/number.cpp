#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);

	char s[10];



	for (int i = 1; i <= 10; i++) {
		cin >> s[i];

		if (s[i] >= '0' && s[i] <= '9') {


			cout << s[i];


		}
	}


	return 0;
}