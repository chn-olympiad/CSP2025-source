#include <iostream>
#include <cstdlib>
#include <string>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

typedef pair<string, string> rep_pair;

int main() {
//	string a = "abcdef";
//	string b = "gh";
//	string c = "dc";
//	int idx = a.find(b);
//	cout << idx << endl;
//	a.replace(idx, b.size(), c);
//	cout << a << endl;
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);

	int n, q;
	cin >> n >> q;
	vector<rep_pair> pairs;

	for (int i = 0; i < n; i++) {
		string a, b;
		cin >> a >> b;
		pairs.emplace_back(a, b);
	}

	while (q-- > 0) {
		string t1, t2;
		cin >> t1 >> t2;
		int count = 0;
		for (rep_pair& str_pair : pairs) {
			int idx = t1.find(str_pair.first);
			string& r1 = str_pair.first;
			string& r2 = str_pair.second;
			if (idx > -1) {
				if (memcmp(t1.c_str(), t2.c_str(), idx) == 0 && memcmp(t2.c_str()+idx, r2.c_str(), r2.length()) == 0 && memcmp(t1.c_str()+idx+r2.size(), t2.c_str()+idx+r2.size(), t1.size()-idx-str_pair.first.size()) == 0) {
					count++;
				}
			}
		}
		cout << count << endl;
	}
}
