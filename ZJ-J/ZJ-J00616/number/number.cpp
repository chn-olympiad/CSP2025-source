#include <bits/stdc++.h>
using namespace std;
string s;
vector<int> vec;
bool cmp(int x, int y) {
	return x > y;
}
int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s;
	int l = s.size();
	for (int i = 0; i < l; i ++) {
		if (s[i] >= '0' && s[i] <= '9') vec.push_back(s[i] - '0');
	}
	sort(vec.begin(), vec.end(), cmp);
	for (int i = 0; i < vec.size(); i ++) cout << vec[i];
	return 0;
}