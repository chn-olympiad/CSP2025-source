#include <bits/stdc++.h>
using namespace std;
string s;
vector<int> nums;
int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s;
	int len = s.size();
	for (int i = 0; i < len; i++)
		if (s[i] >= '0' && s[i] <= '9')
			nums.push_back(s[i] - '0');
	sort(nums.begin(), nums.end(), [&](int g, int h) {
		return g > h;
	});
	for (int i = 0; i < nums.size(); i++)
		printf("%d", nums[i]);
	return 0;
}