#include <bits/stdc++.h>
using namespace std;
char s[1000005];
char b[1000005];
char ls;
int bl;


int main() {

	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	long long j = 0, jn = 1;
	cin >> s;

	while (s[j]) {
		if ((int)s[j] >= 48 && (int)s[j] <= 57) {
			b[jn] = s[j];
			jn++;


		}


		j++;
	}

	jn = jn + 1;
	for (int jj = 1; jj <= jn + jn; jj++) {
		if (b[jj] < b[jj + 1])
			swap(b[jj], b[jj + 1]);

		else {
			for (int i = 1; i <= jn + 1; i++ ) {
				if ((int)b[i] < (int)b[i + 1] ) {
					swap(b[i], b[i + 1]);

				}
			}
		}

	}
	for (int i = 1; i <= jn + 1; i++) {
		cout << b[i];
	}




	return 0;
}