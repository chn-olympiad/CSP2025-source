#include <bits/stdc++.h>
using namespace std;
char s[1000010];
int a[1000010];

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin.getline(s + 1, 1000010);
	int l = strlen(s + 1), o = 0; //48 57
	for (int i = 1; i <= l; i++) {
		if (int(s[i]) >= 48 && int(s[i]) <= 57) {
			o++;
			a[o] = int(s[i]) - 48;
		}
	}
	sort(a + 1, a + o + 1);
	for (int i = o; i >= 1; i--) {
		cout << a[i];
	}
	return 0;
}
