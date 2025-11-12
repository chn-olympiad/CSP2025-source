#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdio>
#include <unordered_map>
using namespace std;
typedef unsigned long long ULL;
const int N = 5000010, M = 10010;
const ULL bas = 133;
int a[N];
string s[N][2], t[N][2];
int n, m, cks, ckt;
unordered_map<ULL, int> mp;
ULL rk[M];
void solve1() {
	for (int i = 0; i < 26; i ++ ) rk[i] = rand() % 133; 
	for (int i = 1; i <= n; i ++ ) {
		ULL res = 0;
		for (int j = 0; j < 2; j ++ ) {
			ULL v = 0;
			for (int k = 0; k < s[i][j].size(); k ++ )
				v = v * bas + rk[t[i][j][k] - 'a'];
			res = (res * 3) ^ v;
			//cout << v << endl;
		}  
		//15284702289
		
		mp[res] ++ ;
		//if ()
	}
//	for (int i = 1; i <= n; i ++ ) {
//		ULL res = 0;
//		for (int j = 0; j < 2; j ++ ) {
//			LL v = 0;
//			for (int k = 0; k < t[i][j].size(); j ++ ) {
//				v = v * bas + rk[s[i][j][k] - 'a'];
//				hsh[i][j][k] = 
//			}
//		}  
//	}
	for (int i = 1; i <= m; i ++ ) {
		if (t[i][0].size() != t[i][1].size()) {
			cout << 0 << endl; continue;
		}
		int res = 0;
		for (int l = 0; l < t[i][0].size() && t[i][0] == t[i][1]; l ++ ) {
			ULL hsh1 = 0, hsh2 = 0;
			for (int r = l; r < t[i][0].size(); r ++ ) {
				hsh1 = hsh1 * bas + rk[t[i][0][r] - 'a'];
				hsh2 = hsh2 * bas + rk[t[i][1][r] - 'a'];
				ULL v = (hsh1 * 3) ^ hsh2;
				//if (l == 2 && r == 2) cout << hsh1 << ' ' << hsh2 << ' ' endl;
				res += mp[v];
			}
		}
		cout << res << endl;
	} 
}

int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i ++ )
		for (int j = 0; j < 2; j ++ ) cin >> s[i][j], cks += s[i][j].size();
	for (int i = 1; i <= m; i ++ )
		for (int j = 0; j < 2; j ++ ) cin >> t[i][j], ckt += t[i][j].size();
	if (cks <= 2000 && ckt <= 2000) solve1();
	//else solve2();
	return 0;
}
