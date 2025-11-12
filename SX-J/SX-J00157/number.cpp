#include <bits/stdc++.h>
using namespace std;
string s[1000000];

int a[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
int f[1000000];
int main() {
	int len1 = strlen(s);
	for (int i = 1; i <= len1; i++) {
		cin >> s;
		if (s[i] == a[i]) {
			int f[i] = s[i];
			if (f[i] < f[i + 1])
				f[i] = f[i + 1];
		}
	}
	cout << f << endl;
	return 0;
}
