#include <bits/stdc++.h>
using namespace std;
vector<int> num(0);
string str;
int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> str;
	for (auto i : str) {
		if (isdigit(i)) {
			num.push_back(i - 48);
		}
	}
	sort(num.begin(), num.end());
	if (num[num.size() - 1] == 0) {
		cout << 0;
		return 0;
	}
	for (int i = num.size() - 1; i >= 0; i--) {
		cout << num[i];
	}
	return 0;
}
