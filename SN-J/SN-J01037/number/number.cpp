#include<bits/stdc++.h>
using namespace std;
vector <int> num;
string s;
int main () {
	freopen ("number.in", "r", stdin);
	freopen ("number.out", "w", stdout);
	cin >> s;
	for (int i = 0; i < s.size(); i++) if (s[i] >= '0' && s[i] <= '9') num.push_back(s[i] - '0');
	sort (num.begin(), num.end());
	for (int i = num.size(); i > 0; i--) cout << num[i - 1];
	return 0;
}
