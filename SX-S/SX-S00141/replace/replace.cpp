#include <bits/stdc++.h>
using namespace std;
int n, q, 	p;
string s1[2000005], s2[2000005], a, b;

int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	cin >> n >> p;
	for (int i = 1; i <= n; i++) {
		cin >> s1[i] >> s2[i];
	}
	while (p--) {
		cin >> a >> b;
		int sum = 0;
		for (int i = 1; i <= n; i++) {
			for (int j = 0; j + s1[i].size() - 1 < a.size() ; j++) {
				if (a.substr(j, s1[i].size()  ) == s1[i] &&  b.substr(j,  s2[i].size()  ) == s2[i]) {
					string s = a;
					s.replace(j, s1[i].size(), s2[i] );
					if (s == b) {
						sum++;
						break;
					}

				}
			}
		}
		cout << sum << '\n';
	}

	return 0;
}
