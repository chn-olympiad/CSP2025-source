#include <bits/stdc++.h>
using namespace std;
/*
about 2 minutes
100 pts
*/
string s;
vector<int> vec;
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s;
	for (auto i: s) {
		int num = i - '0';
		if (num >= 0 && num <= 9) vec.push_back(num);
	}
	sort(vec.rbegin(), vec.rend());
	if (vec[0] == 0) cout << 0;
	else 
		for (auto i: vec) cout << i;
	return 0;
}