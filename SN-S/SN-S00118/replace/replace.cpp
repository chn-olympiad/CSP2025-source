//吴红燊 SN-S00118 西安湖滨中学
/*
luogu uid:743127
this is the way I still love something
bye,someone
CSP-S2025 RP++
*/
#include <bits/stdc++.h>
using namespace std;
//#define int long long
typedef long long ll;
typedef unsigned long long ull;
const int T = 2e6+10,inf = 1e18;
int n,q;
int cnt = 1;
int root = 1;
struct node {
	int nex[26];
	int val;
}s[T];
void insert(string s1,string s2) {
	int p = root;
	for(int i = 0;i < s1.size();i++) {
		if(s[p].nex[s1[i]-'a'] == 0) {
			s[p].nex[s1[i]-'a'] = ++cnt;
		}
		p = s[p].nex[s1[i]-'a'];
		if(s[p].nex[s2[i]-'a'] == 0) {
			s[p].nex[s2[i]-'a'] = ++cnt;
		}
		p = s[p].nex[s2[i]-'a'];
	}
	s[p].val++;
}
ll query(string s1,string s2,int l,int r) {
	if(s1.size() != s2.size()) return 0;
	ll zans = 0;
	ll lans = 0;
	for(int i = 0,p;i <= l;i++) {
		p = root;
		lans = 0;
		bool fl = true;
		for(int j = i;j < r;j++) {
			if(s[p].nex[s1[j]-'a'] == 0) {
				fl = false;
				break;
			}
			p = s[p].nex[s1[j]-'a'];
			if(s[p].nex[s2[j]-'a'] == 0) {
				fl = false;
				break;
			}
			p = s[p].nex[s2[j]-'a'];
		}
		if(fl == false) continue;
		lans = 0;
		for(int j = r;j < s1.size();j++) {
			if(s[p].nex[s1[j]-'a'] == 0) {
				fl = false;
				break;
			}
			p = s[p].nex[s1[j]-'a'];
			if(s[p].nex[s2[j]-'a'] == 0) {
				fl = false;
				break;
			}
			p = s[p].nex[s2[j]-'a'];
			
			lans += s[p].val;
		}
		zans += lans;
	}
	return zans;
}
void solve() {
	cin >> n >> q;
	string s[2],t[2];
	for(int i = 1;i <= n;i++) {
		cin >> s[0] >> s[1];
		insert(s[0],s[1]);
	}
	for(int i = 1;i <= q;i++) {
		cin >> t[0] >> t[1];
		if(t[0].size() != t[1].size()) {
			cout << 0 << '\n';
			continue;
		}
		int l = -1,r = t[0].size();
		while(t[0][l+1] == t[1][l+1]) l++;
		l++;
		while(t[0][r-1] == t[1][r-1]) r--;
		r--;
		cout << query(t[0],t[1],l,r) << '\n';
	}
}
signed main() {
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(0);
//	int t;cin >> t;while(t--)
	solve();
	return 0;
}
