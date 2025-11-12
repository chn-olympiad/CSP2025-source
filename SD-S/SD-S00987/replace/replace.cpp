/*
我要能拿1=。我直播吃我的用户名后六位。。。。。 
*/
#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
const ll N = 1e4 + 10;
const ll mod = 131;
string s[N][2];
ll H[N][2];
ll J[5000010];
ll t3[5000010], t4[5000010], ans;
int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	long long n, q;
	cin >> n >> q;
	for (int i = 1; i <= n; i++) cin >> s[i][0] >> s[i][1];
	string t1, t2;
	J[0] = 1; 
	for (int i = 1; i <= 5000000; i++) J[i] = J[i - 1] * mod;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < s[i][0].size(); j++) H[i][0] += s[i][0][j] * J[j];
		for (int j = 0; j < s[i][1].size(); j++) H[i][1] += s[i][1][j] * J[j];
	}
	while (q--) {
		cin >> t1 >> t2;
//		for (int i = 0; i < t1.size(); i++) {
//			t3[i] = 0;
//			t3[i] = t3[i - 1] + t1[i] * J[i];
//			t4[i] = 0;
//			t4[i] = t4[i - 1] + t2[i] * J[i];
//		}
		ans = 0;
//		for (int i = 1; i <= n; i++) {
//			if (t1.size() < s[i][0].size()) continue;
//			if (t3[s[i][0].size() - 1] == H[i][0]) if (t3[t1.size()] - t3[s[i][0].size() - 1] + H[i][1] == t4[t2.size()]) ans++;
//			for (int j = s[i][0].size(); j <= t1.size() - 1; j++) {
//				if (t3[j] - t3[j - s[i][0].size()] != H[i][0] * J[j - s[i][0].size() + 1]) continue;
//				if (t3[t1.size()] - (t3[j] - t3[j - s[i][0].size()]) + (H[i][1] * J[j - s[i][0].size() + 1]) == t4[t2.size()]) ans++;
//			}
//		} 
		cout << ans << endl;
	}
	fclose(stdin);
	fclose(stdout); 
	return 0;
} 
