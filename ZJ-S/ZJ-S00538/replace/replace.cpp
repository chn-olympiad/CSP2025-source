#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
#define N 200005
int n, q;
string s1[N], s2[N];
int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	cin >> n >> q;
	for (int i = 1; i <= n; ++i)
		cin >> s1[i] >> s2[i];
	while (q--) {
		string t1, t2;
		cin >> t1 >> t2;
		int f, b;
		for (f = 0; f < t1.size() && t1[f] == t2[f]; ++f);
		for (b = t1.size() - 1; b >= 0 && t1[b] == t2[b]; --b);
		string t = t1;
		int ans = 0;
		for (int i = 1; i <= n; ++i) {
			int id;
			while ((id = t.find(s1[i])) != string::npos) {
				if (id > f) break;
				if (id + s1[i].size() > b && s2[i] == t2.substr(id, s1[i].size()))
					++ans;
				t[id] = '0';
			}
		}
		cout << ans << endl;
	}
	return 0;
}
