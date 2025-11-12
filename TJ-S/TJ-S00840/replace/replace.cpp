#include <string>
#include <iostream>
#include <cstdio>
#include <map>
#include <vector> 
using namespace std;
int n, q, ans;
vector<pair<string, string> > mp;
string t1, t2;
bool issame(int idx, string u) {
	int lu = u.size();
	for (int i = idx, j = 0; i < t1.size() && j < lu; i++, j++) {
		if (t1[i] != u[j]) {
			return false;
		} 
	}
	return true;
}
int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	cin >> n >> q;
	for (int i = 1; i <= n; i++) {
		string s1, s2;
		cin >> s1 >> s2;
		mp.push_back({s1, s2});
	}
	while (q--) {
		cin >> t1 >> t2;
		int lt1 = t1.size(), ans = 0;
		for (int i = 0; i < lt1; i++) {
			for (auto now : mp) {
				string u = now.first, v = now.second;
				if (issame(i, u)) {
					string tmp;
					for (int j = 0; j < i; j++) {
						tmp += t1[j];
					} 
					tmp += v;
					for (int j = i + v.size(); j < lt1; j++) {
						tmp += t1[j];
					}					
					if (tmp == t2) {
						ans++;
					}
				}
			}
		}
		cout << ans << "\n";
	}
	return 0;
}
