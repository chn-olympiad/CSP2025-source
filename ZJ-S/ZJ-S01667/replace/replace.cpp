#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5, M = 5e6 + 5;
int n, q;
string s[N][2], t[N][2];
bool check(int x, int y){
	int l1 = s[x][0].size() - 1, l2 = t[y][0].size() - 1;
	for(int i = 1; i + l1 - 1 <= l2; i++){
		bool f = true;
		for(int j = 1; j <= l1; j++){
			if(t[y][0][i + j - 1] != s[x][0][j]){
				f = false;
				break;
			}
		}
		if(f){
			string now = t[y][0].substr(0, i) + s[x][1].substr(1) + t[y][0].substr(i + l1);
			if(now == t[y][1])	return true;
		}
	}
	return false;
}
int main(){
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	bool flag = true;
	cin >> n >> q;
	for(int i = 1; i <= n; i++){
		cin >> s[i][0] >> s[i][1];
		s[i][0] = ' ' + s[i][0];
		s[i][1] = ' ' + s[i][1];
//		int len = s[i][0].size(), cnt1 = 0, cnt2 = 0;
//		for(int j = 1; j < len; j++){
//			if(s[i][0][j] != 'a' && s[i][0][j] != 'b'){
//				flag = false;
//				break;
//			}
//			if(s[i][0][j] == 'b')	cnt1++;
//			if(s[i][1][j] != 'a' && s[i][1][j] != 'b'){
//				flag = false;
//				break;
//			}
//			if(s[i][0][j] == 'b')	cnt2++;
//		}
//		if(cnt1 != 1 || cnt2 != 1)	flag = false;
	}
	for(int i = 1; i <= q; i++){
		cin >> t[i][0] >> t[i][1];
		t[i][0] = ' ' + t[i][0];
		t[i][1] = ' ' + t[i][1];
//		int len = t[i][0].size(), cnt1 = 0, cnt2 = 0;
//		for(int j = 1; j < len; j++){
//			if(t[i][0][j] != 'a' && t[i][0][j] != 'b'){
//				flag = false;
//				break;
//			}
//			if(t[i][0][j] == 'b')	cnt1++;
//			if(t[i][1][j] != 'a' && t[i][1][j] != 'b'){
//				flag = false;
//				break;
//			}
//			if(t[i][0][j] == 'b')	cnt2++;
//		}
//		if(cnt1 != 1 || cnt2 != 1)	flag = false;
	}
//	if(flag){
//		solve();
//		return 0;
//	}
	for(int i = 1; i <= q; i++){
		int ans = 0;
		for(int j = 1; j <= n; j++){
			if(check(j, i))	ans++;
		}
		cout << ans << '\n';
	}
	return 0;
}
