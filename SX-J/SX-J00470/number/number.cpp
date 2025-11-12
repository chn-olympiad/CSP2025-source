#include <bits/stdc++.h>
using namespace std;
string s;
int nums[1000100];

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s;
	int l = 0;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] >= '0' && s[i] <= '9') {
			nums[l] = int(s[i]) - 48;
			l++;
		}
	}
	sort(nums, nums + l);
	for (int i = l - 1; i >= 0; i--) {
		cout << nums[i];
	}
	cout << endl;
	return 0;
}
