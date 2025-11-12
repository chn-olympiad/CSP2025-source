#include<bits/stdc++.h>
using namespace std;
int n, q;
const int m1 = 998244353, m2 = 1000000007;
const int b1 = 37, b2 = 1145141;
int pw[5000005], pww[5000005];
bool mew;
string s[200005], ss[200005];
bool chk(string s){
	int buk = 0, cb = 0;
	for (auto ch : s){
		buk |= (1 << ch - 'a');
		if (ch == 'b')
			++cb;
	}
	if (buk == 3 && cb == 1)
		return 1;
	return 0; 
}
vector<int> fnd(string s, string t){
//	cerr << "awa\n";
	vector<int> ans;
	ans.clear();
	if (s.size() < t.size())
		return ans;
	pair<int, int> ht, hs;
	ht.first = ht.second = hs.first = hs.second = 0;
	for (int i = 0; i < t.size(); i++){
		ht.first = (ht.first + 1ll * pw[i] * (t[i] - 96)) % m1;
		ht.second = (ht.second + 1ll * pww[i] * (t[i] - 96)) % m2;
		hs.first = (hs.first + 1ll * pw[i] * (s[i] - 96)) % m1;
		hs.second = (hs.second + 1ll * pww[i] * (s[i] - 96)) % m2;
	}
//	cerr << "qwq\n";
	if (hs == ht)
		ans.emplace_back(t.size() - 1);
	for (int i = t.size(); i < s.size(); i++){
		hs.first = (hs.first + 1ll * pw[i] * (s[i] - 96)) % m1;
		hs.second = (hs.second + 1ll * pww[i] * (s[i] - 96)) % m2;
		hs.first = (hs.first - 1ll * pw[i - t.size()] * (s[i - t.size()] - 96) % m1 + m1) % m1;
		hs.second = (hs.second - 1ll * pww[i - t.size()] * (s[i - t.size()] - 96) % m2 + m2) % m2;
		ht.first = 1ll * ht.first * b1 % m1;
		ht.second = 1ll * ht.second * b2 % m2;
		if (hs == ht)
			ans.emplace_back(i);
	}
//	cerr << "^_^\n";
	return ans;
}
void ini(){
	pw[0] = pww[0] = 1;
	for (int i = 1; i <= 5000000; i++){
		pw[i] = 1ll * pw[i - 1] * b1 % m1;
		pww[i] = 1ll * pww[i - 1] * b2 % m2;
	}
}
signed main(){
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin >> n >> q;
	for (int i = 1; i <= n; i++){
		cin >> s[i] >> ss[i];
		if (mew)
			if (!chk(s[i]))
				mew = 0;
		if (mew)
			if (!chk(ss[i]))
				mew = 0;
	}
	ini();
	while (q--){
		string qwq, awa;
		cin >> qwq >> awa;
		if (qwq.size() != awa.size()){
			cout << "0\n";
			continue;
		}
		int dl, dr;
		for (int i = 0; i < qwq.size(); i++){
			if (qwq[i] != awa[i]){
				dl = i;
				break;
			}
		}
		for (int i = qwq.size() - 1; ~i; i--){
			if (qwq[i] != awa[i]){
				dr = i;
				break;
			}
		}
		int ans = 0;
		for (int i = 1; i <= n; i++){
			vector<int> sf = fnd(qwq, s[i]);
			vector<int> st = fnd(awa, ss[i]);
			int pos = 0;
			if (!st.size())
				continue;
		//	cerr << sf.size() << " " << st.size() << "\n";
			for (auto u : sf){
				while (pos < st.size() - 1 && st[pos] < u)
					++pos;
			//	cerr << u << " " << st[pos] << "\n";
				if (st[pos] != u)
					continue;
				if (u >= dr && u - s[i].size() + 1 <= dl)
					++ans;
			}
		}
		cout << ans << "\n";
	}
	return 0;
}
