#include <bits/stdc++.h>
using namespace std;
int nums[10];

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	string s;
	cin >> s;
	for (int i = 0; i < s.length(); i++) {
		if (s[i] >= '0' && s[i] <= '9') {
			int n = s[i] - '0';
			nums[n]++;
		}
	}
	for (int i = 9; i >= 0; i--) {
		while (nums[i] != 0) {
			cout << i;
			nums[i]--;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
