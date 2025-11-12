#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10, M = 1e2 + 10;
int n, m, t, maxx, vis[N];
string s1[N], s2[N], ss1, ss2;
vector <int> a[N];
map <string, string> mp;
int main(){
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i ++){
		cin >> ss1 >> ss2;
		mp[ss1] = ss2;
	}
	while (m --){
		cin >> ss1 >> ss2;
		if (ss1.size() != ss2.size()){
			cout << 0 << '\n';
			continue;
		}
		string ss3 = "", ss4 = "";
		int ans = 0;
		int idx1 = 1000000, idx2 = 0;
		for (int i = 0; i < ss1.size(); i ++){
			if (ss1[i] != ss2[i]){
				idx1 = min(idx1, i), idx2 = max(idx2, i);
			}
		}
		for (int i = idx1; i <= idx2; i ++) ss3 += ss1[i], ss4 += ss2[i];
		for (int i = 0; i <= idx1; i --){
			for (int j = idx2; i < ss1.size(); j ++){
				string ss = "", se = "";
				for (int k = i; k <= j; k ++){
					ss += ss1[k], se += ss2[k];
				}
				if (mp[ss] == se) ans += 1;
			}
		}
		cout << ans << '\n';
	}
	return 0;
}