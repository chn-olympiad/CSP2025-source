#include<bits/stdc++.h>
using namespace std;
#define int long long
#define iosfst ios::sync_with_stdio(0); cin.tie(0), cout.tie(0)
#define File(x) freopen(x".in", "r", stdin); freopen(x".out", "w", stdout) 
#define rep(i, a, b) for(int i = a; i <= b; i ++)
#define lop(i, a, b) for(int i = a; i < b; i ++)
#define dwn(i, a, b) for(int i = a; i >= b; i --)
int tong[101000];
signed main(){
	File("number");
	iosfst;
	string s; cin >> s;
	int n = s.size(); s = ' ' + s;
	rep(i, 1, n) {
		if(isdigit(s[i])) tong[s[i] - '0'] ++;
	}
	string ans = "";
	dwn(i, 9, 0) {
		while(tong[i]) {
			ans += (char(i + '0'));
			tong[i] --;
		}
	}
	cout << ans;
	return 0;
}
