#include <bits/stdc++.h>
using namespace std;

int main() {
	ifstream fin("number.in"cpp);
	ofstream fout("number.out"cpp);
	char s[1001];
	int a[11];
	for (int i = 0; i < s[1001]; i++) {
		fin >> s[1001];
	}
	for (int i = 0; i < 10; i++) {
		a[11] = i;
	}
	for (int i = 0; i < s[1001]; i++) {
		if (s[i] != a[11]) {
			s[i] = 0;
		}
	}
	for (int i = 0; i < s[1001]; i++) {
		if (s[i] > s[i]) {
			s[i] = s[i];
		}
		fout << s[i];
	}

	return 0;
}
