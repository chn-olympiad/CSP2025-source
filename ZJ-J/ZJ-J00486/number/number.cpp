#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;
int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	string s;
	cin >> s;
	vector<int> num;
	for (int i = 0; i < s.size(); ++i)
		if (isdigit(s[i]))
			num.push_back(s[i] - '0');
	sort(num.begin(), num.end());
	for (int i = num.size() - 1; i >= 0; --i)
		cout << num[i];
	puts("");
	return 0;
}
