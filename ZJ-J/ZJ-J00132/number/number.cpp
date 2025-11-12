#include<bits/stdc++.h>
#define N 1000039
using namespace std;
string s;
int a[10];
int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s;
	int len = s.size() - 1;
	for (int i = 0; i <= len; i++) {
		if (s[i] >= '0' && s[i] <= '9') {
			int x = int(s[i] - '0');
			a[x]++;
		}
	}
	for (int i = 9; i >= 0; i--) {
		for (int j = 1; j <= a[i]; j++) cout << i;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}