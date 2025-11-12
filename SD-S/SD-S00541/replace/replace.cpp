#include<bits/stdc++.h>
#define int long long
#define endl '\n'
#define fst; ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

const int maxn = 1e6 + 5;

const int INF = 0x3f3f3f3f3f3f3f3f;
const int P = 998244353;

int n, m;
int flag[maxn];
map<pair<string, string>, int> mp;

signed main() {
//	system("fc replace3.ans aa.out");
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	fst;
	
	cin >> n >> m;
	for (int i = 1; i <= n; ++ i ) {
		string s1, s2; cin >> s1 >> s2;
		mp[{s1, s2}] ++;
	}
	while (m -- ) {
		string s1, s2; cin >> s1 >> s2; int ans = 0;
		for (int j = 0; j < s1.size(); ++ j ) {
			string ss1 = "", ss2 = "";
			if (s1.substr(0, j) != s2.substr(0, j)) continue;
			string sa = "", sb = "";
			for (int k = s1.size() - 1; k >= j; -- k ) {
				ss1 += s1[k], ss2 += s2[k];
				ans += mp[{s1.substr(j, k - j + 1), s2.substr(j, k - j + 1)}] * (sa == sb);
				sa = s1[k] + sa, sb = s2[k] + sb;
			}
		}
		cout << ans << endl;
	}
	
	
	return 0;
}

