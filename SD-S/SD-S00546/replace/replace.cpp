#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
/*
#include<stack>
#include<queue>
#include<map>
#include<set>
#include<vector>
#include<string>
#include<unordered_map>
*/
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

#define bug cout<<"-------\n";
#define debug(x) cout<<#x<<'='<<x<<'\n';
#define file(FILENAME) freopen(FILENAME ".in","r",stdin),freopen(FILENAME ".out","w",stdout);
#define CLOSE ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
#define endl '\n'

const ll N = 200005;

ll n, q;
string s1[N];
string s2[N];

bool tebiede(string ss) {
	bool flag = 1;
	for(int i = 0; i < ss.size(); i++) {
		if(ss[i] != 'a' && ss[i] != 'b')return 0;
		if(ss[i] == 'b' && !flag)return 0;
		if(ss[i] == 'b')flag = 0;
	}
	return 1;
}
ll ffind(string x) {
	for(int i = 0; i < x.size(); i++) {
		if(x[i] == 'b')return i;
	}
}
ll ttt1[N], ttt2[N];
void ttt() {
	for(int i = 1; i <= n; i++) {
		ttt1[i] = ffind(s1[i]);
		ttt2[i] = ffind(s2[i]);
	}
}
void solve1(string t1, string t2) {
	ll ans = 0;
	if(t1.size() != t2.size()) {
		cout << ans << endl;
		return ;
	}
	ll id1 = ffind(t1), id2 = ffind(t2);
	for(int i = 1; i <= n; i++) {
		if(ttt1[i] <= id1 && (s1[i].size() - 1 - ttt1[i]) <= (t1.size() - 1 - id1)) {
			if(id1 - id2 == ttt1[i] - ttt2[i]) {
				ans++;
			}
		}
	}
	cout << ans << endl;
}
void solve(bool flag) {
	string t1, t2;
	cin >> t1 >> t2;
	if(flag) {
		if(tebiede(t1) && tebiede(t2)) {
			solve1(t1, t2);
			return ;
		}
	}
	t1 = " " + t1;
	t2 = " " + t2;
	ll ans = 0;
	if(t1.size() != t2.size()) {
		cout << ans << endl;
		return ;
	}
	for(int i = 1; i <= n; i++) {
		ll p = 0;
		for(int j = 1; j <= t1.size() - 1; j++) {
			bool flg = 1;
			for(int k = 0; k <= s1[i].size() - 1; k++) {
				if(t1[j + k] != s1[i][k]) {
					flg = 0;
					break;
				}
			}
			if(!flg)continue;
			else {
				string tt = t1;
				for(int k = 0; k <= s2[i].size() - 1; k++) {
					tt[j + k] = s2[i][k];
				}
				if(tt == t2)ans++;
			}
		}
	}
	cout << ans << endl;
}
int main() {
	file("replace")
	CLOSE
	cin >> n >> q;
	bool flag = 1;
	for(int i = 1; i <= n; i++) {
		cin >> s1[i] >> s2[i];
		if(flag)flag = flag && tebiede(s1[i]) && tebiede(s2[i]);
	}
	if(flag)ttt();
	while(q--) {
		solve(flag);
	}
	return 0;
}

