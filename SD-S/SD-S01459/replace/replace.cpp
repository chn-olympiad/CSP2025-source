#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int MAXN = 1010;
ll n, q, cnt = 0, len;
string str[MAXN][2], t1, t2;
int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	cin >> n >> q;
	for(int i = 0; i < n; i++) cin >> str[i][0] >> str[i][1];
	while(q--) {
		cnt = 0;
		cin >> t1 >> t2;
		len = t1.size();
		for(int i = 0; i < n; i++) {
			for(int j = 0; j + str[i][0].size() - 1 < len; j++) {
				if(t1.substr(j, str[i][0].size()) == str[i][0]) {
					string tmp = t1.substr(0, j) + str[i][1] + t1.substr(j + str[i][1].size());
					if(tmp == t2) cnt++;
				}
			}
		}
		cout << cnt << "\n";
	}
	return 0;
}

