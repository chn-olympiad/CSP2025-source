#include <bits/stdc++.h>
using namespace std;
string s;
vector<int>q;

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s;
	int l = s.size();
	for (int i = 0; i < l; i++) {
		if (s[i] >= '0' && s[i] <= '9') {
			int x = s[i] - '0';
			q.push_back(x);
		}
	}
	sort(q.begin(), q.end());
	for (int i = q.size() - 1; i >= 0; i--) {
		cout << q[i];
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
