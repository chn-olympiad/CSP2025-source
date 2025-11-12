#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	char s[2];
	for (int i = 0; i < 2; i++) cin >> s[i];
	sort(s, s + 2);
	for (int i = 1; i >= 0; i--) if (s[i] <= 57) cout << s[i];
	fclose(stdin);
	fclose(stdout);
}
