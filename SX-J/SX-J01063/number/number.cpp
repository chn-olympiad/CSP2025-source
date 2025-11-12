#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	string s, o;
	cin >> s;
	int p = 0;
	int n = s.length();
	for (int i = 0; i < n; i++) {
		if (s[i] >= 'a' && s[i] <= 'z') {
			s[i] = 'a';
		} else
			p++;
	}

	for (int i = 0 ; i < p; i++) {
		char m = 0;
		int u = 0;
		for (int j = 0 ; j < n; j++) {
			if (s[j] != 'a') {
				if (s[j] >= m) {
					m = s[j];
					u = j;
				}
			}
		}
		o[i] = m;
		s[u] = 'a';
	}


	for (int i = 0 ; i < p; i++) {
		cout << o[i];
	}
	return 0;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
