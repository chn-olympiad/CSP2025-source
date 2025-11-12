#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

typedef pair<string, string> PSS;

const int N = 2e5 + 10;

int n, q;
PSS s[N];

int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n >> q;
	for (int i = 1; i <= n; i++)
		cin >> s[i].first >> s[i].second;
	while (q--) {
		string str1, str2, t;
		cin >> str1 >> str2;
		int ans = 0;
		for (int i = 1; i <= n; i++) {
			int len = s[i].first.size();
			for (int j = 0; j < str1.size(); j++) {
				if (s[i].first == str1.substr(j, len)) {
					t = str1;
					for (int x = 0; x < len; x++)
						t[j + x] = s[i].second[x];
//					cout << t << ' ' << str2 << endl;
					if (t == str2)
						ans++;
				}
			}

		}
		cout << ans << '\n';
	}
	return 0;
}