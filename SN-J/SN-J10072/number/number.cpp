#include <bits/stdc++.h>
using namespace std;
const int XN=1e5+10;
string s;
vector<int> v;
bool cmp(int a, int b) {
	return a>b;
}
int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> s;
	for (int i = 0; i < s.size(); i++)
		if (s[i]>='0' && s[i]<='9')
			v.push_back(s[i]-'0');
	sort(v.begin(), v.end(), cmp);
	for (int i : v) {
		cout << i;
	}
	return 0;
}
