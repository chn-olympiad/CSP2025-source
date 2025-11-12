#include <bits/stdc++.h>
using namespace std;

vector<int> v;

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	string s;
	getline(cin, s);
	int s_l = s.size();
	for (int i = 0; i < s_l; i++) {
		if (!(s[i] >= '0' && s[i] <= '9')) {
			continue;
		}
		v.push_back(s[i] - '0');
	}
	sort(v.begin(), v.end());
	int lc = v.size() - 1;
	while (v[lc] == 0 && lc >= 1)
		lc--;
	for (int i = lc; i >= 0; i--) {
		cout << v[i];
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}