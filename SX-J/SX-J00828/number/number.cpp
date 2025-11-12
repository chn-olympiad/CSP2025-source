#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	string s = "";
	cin >> s;
	char s1[100000];
	int s2 = s.length();
	char a[1000];
	int j = 0;
	for (int i = 0; i < s2; i++) {
		s1[i] = s[i];
		if (s1[i] >= '0' && s1[i] <= '9') {
			a[j] = s1[i];
			j++;
		}
	}
	for (int i = 0; i < j; i++) {
		if (a[i] < a[i + 1]) {
			int b = a[i];
			a[i] = a[i + 1];
			a[i + 1] = b;
		}
	}

	for (int i = 0; i < j; i++) {
		cout << a[i];
	}
	return 0;
	fclose(stdin);
	fclose(stdout);
}



