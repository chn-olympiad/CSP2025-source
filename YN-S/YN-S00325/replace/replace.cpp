#include <iostream>
#include <map>
#include <cstdio>
using namespace std;

inline int read() {
	int num = 0, sign = 1;
	char ch = getchar();
	while (ch < '0' || '9' < ch)
		sign = ch == '-' ? -1 : 1, ch = getchar();
	while ('0' <= ch && ch <= '9')
		num = (num << 1) + (num << 3) + ch - '0', ch = getchar();
	return sign < 0 ? -num : num;
}
int n, q;
map<string, string> mp;

int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	cin >> n >> q;
	for (int i = 1; i <= n; i++) {
		string s1, s2;
		cin >> s1 >> s2;
		mp[s1] = s2, mp[s2] = s1;
	}
	while (q--) {
		string t1, t2;
		cin >> t1 >> t2;
		int cnt = 0;
		for (int l = 0; l < t1.size(); l++)
			for (int r = l; r < t1.size(); r++) {
				string tt1 = t1.substr(l, r - l + 1), tt2 = t2.substr(l, r - l + 1),
				       lt1 = t1.substr(1, l - 1), lt2 = t2.substr(1, l - 1),
				       rt1 = t1.substr(r + 1, t1.size() - r), rt2 = t2.substr(r + 1, t2.size() - r);
				if (mp[tt1] == tt2) {
					if (lt1 == lt2 && rt1 == rt2)
						cnt++;
					else if (l == 0 && rt1 == rt2)
						cnt++;
					else if (r == t1.size() - 1 && lt1 == lt2)
						cnt++;
					else if (l == 0 && r == t1.size() - 1)
						cnt++;
				}
			}
		cout << cnt << "\n";
	}

	return 0;
}