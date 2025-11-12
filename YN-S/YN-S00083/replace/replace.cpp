#include <bits/stdc++.h>
using namespace std;
const int N = 5e6 + 10;
int n, q;

struct s {
	string st1;
	string st2;
} s[N];

int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	cin >> n >> q;
	for (int i = 1; i <= n; i++) {
		cin >> s[i].st1 >> s[i].st2;
	}
	while (q) {
		string s1, s2, s3, s4;
		cin >> s3 >> s4;
		int cnt = 0;
		for (int i = 1; i <= n; i++) {
			s1 = s3;
			s2 = s4;
			string sx, sy, sz;
			int t = 1, t1 = s[i].st1.size();
			bool f = 0;
			for (int j = 0; j < s1.size(); j++) {
				if (s1[i] == s[i].st1[t]) {
					sy[t] = s1[j];
					t1--;
					t++;
					if (t1 == 0) {
						f = 1;
					}
				} else if (!f) {
					sx[j] = s1[j];
					t = 1;
					t1 = s[i].st1.size();
					sy = ' ';
				} else if (f) {
					sz[j] = s1[j];
					t = 1;
					t1 = s[i].st1.size();
					sy = ' ';
				}
			}
			if (s1 == s2) {
				cnt++;
			}
		}
		cout << cnt << endl;
	}
	return 0;
}