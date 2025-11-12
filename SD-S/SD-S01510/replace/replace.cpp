#include<bits/stdc++.h>

using namespace std;
int n, q;
const int N = 2e5 + 10;
string r[N][2];
string s1, s2;
int ans;
bool check(int k, int i) {
	string sy = r[k][0], sr = r[k][1];
	string s1_ = s1;
	int ii = i;
	for (i; i < s1.length(); i ++) {
		if (i - ii == sy.length()) break;
		if (s1_[i] == sy[i - ii]){
			s1_[i] = sr[i - ii];
		}else{
			return 0;
		} 
 	}
 	if (s1_ == s2) return 1;
 	else return 0;
}
int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> q;
	for (int i = 1; i <= n; i ++) {
		cin >> r[i][0] >> r[i][1];
	}
	while(q --) {
		cin >> s1 >> s2;
		ans = 0;
		for (int i = 1; i <= n; i ++) {
			for (int j = 0; j < s1.length(); j ++) {
				if (check(i, j)) {
					ans ++;
					break;
				}
			}
		}
		cout << ans << endl;
	}
	return 0;
}
