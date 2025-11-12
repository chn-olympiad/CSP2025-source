#include <bits/stdc++.h>
using namespace std;
int n, q,  ans;

int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	cin >> n >> q;
	string s[n][3];
	for (int i = 0; i < n; i++) {
		cin >> s[i][0] >> s[i][1];
	}
	//int qq = q;
	while (q--) {

		ans = 0;
		string sq, sa;
		cin >> sq >> sa;


		for (int c = 0; c < n; c++) {
			int sql = s[c][0].size(), sal = s[c][1].size();
			if (sql != sal)
				continue;
			for (int t = 0; t <= sql ; t++) {
				for (int w = 1; w <= sql - t ; w++) {


					string s1 = s[c][0], s2 = s[c][1];
					s2 = s1.replace(t, w, s2.substr(t, w ));
					//cout << s1 << ' ' << s2 << ' ' << t << " " << w << " " << s2 << endl;
					if (s2 == sa && s[c][0][t + w - 1] == s[c][1][t + w - 1])
						ans++;
				}

			}
		}
		cout << ans << endl;
	}


	return 0;
}
