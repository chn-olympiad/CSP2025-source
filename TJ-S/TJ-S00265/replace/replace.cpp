#include <bits/stdc++.h>
using namespace std;
#define int long long

int n , q , len , ans;
string s1 , s2 , t1 , t2 , x , y , z , tmp1 , tmp2;
unordered_map <string , string> mp;
bool pre[100003] , lst[100003];

signed main() {
	freopen("replace.in" , "r" , stdin); freopen("replace.out" , "w" , stdout);
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> q;
	for (int i = 1 ; i <= n ; i++) cin >> s1 >> s2 , mp[s1] = s2;
	while (q--) {
		cin >> t1 >> t2;
		if (t1.size() != t2.size()) {
			cout << "0\n";
			continue;
		}
		len = t1.size() , t1 = " " + t1 , t2 = " " + t2 , pre[0] = lst[len + 1] = 1 , ans = 0;
		for (int i = 1 ; i <= len ; i++) pre[i] = ((t1[i] == t2[i]) && pre[i - 1]);
		for (int i = len ; i >= 1 ; i--) lst[i] = ((t1[i] == t2[i]) && lst[i + 1]);
		for (int i = 1 ; i <= len ; i++) {
			tmp1 = tmp2 = "";
			for (int j = i ; j <= len ; j++) {
				tmp1 += t1[j] , tmp2 += t2[j];
				if (!pre[i - 1] || !lst[j + 1]) continue;
				if (mp[tmp1] == tmp2) ans++;
			}
		}
		cout << ans << "\n";
	}
	return 0;
}
