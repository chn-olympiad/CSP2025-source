#include<iostream>
#include<string>
#include<vector>
#include<map>
using namespace std;
const int a[2] = {29, 31}, mod[2] = {1000000007, 1000000009};
const int maxlen = 5e6 + 10;
const int maxn = 2e5 + 10;
string s1, s2, t1, t2;
int n, q;
long long pw[maxn][2];
struct HASH {
	vector<long long> hash[2];
};
HASH hs1[maxn], hs2[maxn], ht1, ht2;
void store_hash(string &s, HASH &h) {
	for(int j = 0; j < 2; j++) {
		h.hash[j].clear();
		int len = s.length();
		h.hash[j].push_back(0);
		for(int k = 1; k <= len; k++) {
			int _hash = (h.hash[j][k-1] * a[j] + s[k-1] - 'a' + 1) % mod[j];
			h.hash[j].push_back(_hash);
                }
	}
}

pair<int, int> get_hash(HASH &h, int l, int r) {
	if(l > r) return {0, 0};
	pair<int, int> res;
	res.first = ((h.hash[0][r] - h.hash[0][l-1] * pw[r-l+1][0]) % mod[0] + mod[0]) % mod[0];
	res.second = ((h.hash[1][r] - h.hash[1][l-1] * pw[r-l+1][1]) % mod[1] + mod[1]) % mod[1];
	return res;
}
void output(pair<int, int> pr) {
	cerr << pr.first << " " << pr.second << endl;
}
struct T {
	int cnt, c[26];
};

struct TRIE {
	vector<T> nd;
	void Tinit(T &tmp) {
		tmp.cnt = 0;
		for(int i = 0; i < 26; i++) tmp.c[i] = -1;
	}
	void init() {
		T tmp;
		Tinit(tmp);
		nd.push_back(tmp);
	}
	void insert(string s) {
		int cur = 0;
		nd[cur].cnt++;
		for(int i = 0; i < s.length(); i++) {
			if(nd[cur].c[s[i] - 'a'] == -1) {
				T tmp;
				Tinit(tmp);
				nd.push_back(tmp);
				nd[cur].c[s[i] - 'a'] = nd.size() - 1;
			}
			cur = nd[cur].c[s[i] - 'a'];
			nd[cur].cnt++;
		}
	}
};
map<pair<pair<string, string>, string>, TRIE> mp;

int main()
{
	cin >> n >> q;
	for(int i = 1; i <= n; i++) {
		cin >> s1 >> s2;
		int len = s1.length();
		int l = 0, r = len - 1;
		while(s1[l] == s2[l]) l++;
		while(s1[r] == s2[r]) r--;
		string x = s1.substr(0, l);
		string z = s1.substr(r + 1, len - r);
		string s1y = s1.substr(l + 1, r - l + 1);
		string s2y = s2.substr(l + 1, r - l + 1);
		pair<stirng, string> pr = {s1y, s2y};
		pair<pair<string, string>, stirng> tri = {pr, x}; 
		mp[tri].inset(z);
	}
	while(q--) {
		cin >> t1 >> t2;
		if(t1.length() != t2.length()) {
			cout << 0 << endl;
			continue;
		}
		int len = t1.length();
		int l = 0, r = len - 1;
		long long ans = 0;
		while(t1[l] == t2[l]) l++;
		while(t1[r] == t2[r]) r--;
		string x = t1.substr(0, l);
                string z = t1.substr(r + 1, len - r);
                string t1y = t1.substr(l + 1, r - l + 1);
                string t2y = t2.substr(l + 1, r - l + 1);
                pair<stirng, string> pr = {t1y, t2y};
		string x;
		solve(x);
		for(int i = l - 1; i >= 0; i--) {
			x = 
