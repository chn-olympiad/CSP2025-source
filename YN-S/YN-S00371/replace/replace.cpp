#include <bits/stdc++.h>
using namespace std;

struct Rule {
	string first;
	string second;
};

int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	int n, q;
	cin >> n >> q;
	vector<Rule>rules(n);
	for (int i = 0; i < n; i++) {
		cin >> rules[i].first >> rules[i].second;
	}
	while (q--) {
		string t1, t2;
		cin >> t1 >> t2;
		int count = 0;
		for (int i = 0; i < n; i++) {
			string s = rules[i].first;
			string t = rules[i].second;
			if (s.length() != t.length())
				continue;
			for (size_t pos = t1.find(s); pos != string::npos; pos = t1.find(s, pos + 1)) {
				string new_str = t1.substr(0, pos) + t + t1.substr(pos + s.length());
				if (new_str == t2) {
					count++;
				}
			}
		}
		cout << count << endl;
	}
	return 0;
}
