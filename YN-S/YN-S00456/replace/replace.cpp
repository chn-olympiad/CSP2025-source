#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
string s[N], s1[N];

int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	int n, q;
	cin >> n >> q;
	for (int i = 1; i <= n; i++) {
		cin >> s[i] >> s1[i];
		int lengs = s[i].size();
		int lengs1 = s1[i].size();
		int id = 0, length = 0;
		string tmp = "", tmp2 = "";
		bool flag = false;
		for (int j = 0; j < lengs; j++) {
			if (flag) {
				tmp += s[i][j];
				tmp2 += s1[i][j];
			}
			if (s[i][j] != s1[i][j] && flag == false) {
				tmp += s[i][j];
				tmp2 += s1[i][j];
				flag = true;
			}
			if (s[i][j] == s1[i][j] && flag) {
				break;
			}
		}
		s[i] = tmp, s1[i] = tmp2;
	}
//	for (int i = 1; i <= n; i++) {
//		cout << s[i] << " " << s1[i];
//	}
//	cout << endl;
	for (int i = 1; i <= q; i++) {
		string a, b;
		cin >> a >> b;
		int leng_a = a.size();
		int leng_b = b.size();
		int flag = 0;
		string tmp = "", tmp2 = "";
		for (int j = 0; j < leng_a; j++) {
			if (a[j] != b[j] && flag == 0) {
				flag = 1;
			}
			if (flag != 0) {
				tmp += a[j];
				tmp2 += b[j];
			}
			if (a[j] == b[j] && flag != 0) {
				break;
			}
		}
		cout << tmp << " " << tmp2;
		int cnt = 0;
		for (int j = 1; j <= n; j++) {
			if (s[j] == tmp && s1[j] == tmp2) {
				cnt++;
			}
		}
		cout << cnt << endl;
	}
	return 0;
}