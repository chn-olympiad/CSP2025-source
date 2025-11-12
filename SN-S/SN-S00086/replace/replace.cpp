#include <iostream>
using namespace std;

const int Mod = 2 * 1e5 + 5;

int n, q, ans;
string s[Mod][2], t1, t2;

int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	cin >> n >> q;
	for (int i = 1;i <= n;i++) {
		cin >> s[i][0] >> s[i][1];
	}
	for (int i = 1;i <= q;i++) {
		cin >> t1 >> t2;
		ans = 0;
		
		if (n <= 1e4) {
		
			for (int kind = 1;kind <= n;kind++) {
				if (s[kind][0].size() > t1.size()) continue;
				bool haschange = false;
				bool big_flag = true;
				for (int i = 0;i <= t1.size() - s[kind][0].size();i++) {
					if (!haschange) {
						bool flag = true;
						for (int j = 0;j < s[kind][0].size();j++) {
							if (t1[i+j] != s[kind][0][j] || t2[i+j] != s[kind][1][j]) {
								flag = false;
								break;
							}
						}
						if (flag) {
							i += s[kind][0].size() - 1;
							haschange = true;
						}
					} else {
						if (t1[i] != t2[i]) {
							big_flag = false;
						}
					}
				}
				if (big_flag && haschange) {
					ans++;
				}
			}
			
			cout << ans << endl;
			
		} else {
			cout << 0 << endl;
		}
	}
	return 0;
}
