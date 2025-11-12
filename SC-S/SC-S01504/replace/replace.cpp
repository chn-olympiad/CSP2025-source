#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
typedef unsigned long long ull;
const int N = 2e5 + 5;
int n,q;
vector<int> len;
map<pair<ull,ull>,int> hs;
ull hs1[N],hs2[N];
ull base[N] = {1,656427};
string s1,s2;
ull calc(string s) {
	ull ans = 0;
	for(char c : s) {
		ans = ans * base[1] + c;
	}
	return ans;
}
void calc(ull *h,string &s) {
	s = " " + s;
	for(int i = 1;i < s.size();i ++) {
		h[i] = h[i - 1] * base[1] + s[i];
	}
}
ull query(ull *h,int l,int r) {
	if(l > r) return 0;
	return h[r] - h[l - 1] * base[r - l + 1];
}
ull same(int l,int r) {
	if(l > r) return true;
	return query(hs1,l,r) == query(hs2,l,r);
}
void solve() {
	cin >> n >> q;
	for(int i = 2;i <= n;i ++) {
		base[i] = base[i - 1]  * base[1];
	}
	len.reserve(n);
	for(int i = 1;i <= n;i ++) {
		cin >> s1 >> s2;
		len.push_back(s1.size());
		hs[{calc(s1),calc(s2)}] ++;
	}
	sort(len.begin(),len.end());
	len.erase(unique(len.begin(),len.end()),len.end());
	while(q --) {
		cin >> s1 >> s2;
		if(s1.size() != s2.size()) {
			cout << 0 << "\n";
			continue;
		}
		int m = s1.size(),ans = 0;
		calc(hs1,s1),calc(hs2,s2);
		int sr = m + 1;
		for(int r = m;r >= 1;r --) {
			if(s1[r] != s2[r]) break;
			sr = r;
		}
		for(int l = 1,f = len.size();l <= m;l ++) {
			while(f > 0 && l + len[f - 1] >= sr) f --;
			for(int t = f;t < len.size();t ++) {
				int r = l + len[t] - 1;
				if(r > m) break;
				pair<ull,ull> now = {query(hs1,l,r),query(hs2,l,r)};
				if(hs.count(now)) ans += hs[now];
			}
			if(s1[l] != s2[l]) break;
		}
		cout << ans << "\n";
	}
}
int main() {
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int t = 1;
//	cin >> t;
	while(t --) solve();
	return 0;
}
/*
4 2
xabcx xadex
ab cd
bc de
aa bb
xabcx xadex
aaaa bbbb
*/
/*
3 4
a b
b c
c d
aa bb
aa b
a c
b a
*/