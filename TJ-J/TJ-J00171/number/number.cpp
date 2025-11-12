#include <bits/stdc++.h>
using namespace std;
bool cmp(int a, int b) {
	return a > b;
}
int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	string s;
	cin >> s;
	int nums[s.size()] = {-1};
	int cnt = 0;
	for (int i = 0; i < s.size(); i++) {
		unsigned int nownum = s[i] - '0';
		if (nownum < 10) {
			nums[cnt] = nownum;
			cnt++;
		}
	}
	sort(nums, nums + s.size(), cmp);
	for (int i = 0; i < cnt; i++) {
		cout << nums[i];
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
