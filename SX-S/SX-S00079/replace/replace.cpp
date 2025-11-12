#include <bits/stdc++.h>
using namespace std;
int n, m;

struct zm {
	int zm[27] = {};
} z;

struct Trie {
	int idx = 0, cnt = 0;
	map<int, set<int>>val, vl;
	vector<zm>son, sn;
	void insert(string s, string t, int id) {
		int now = 0;
		for (int i = 0; i < s.length(); i++) {
//			cerr << now << ' ' << son.size() << '\n';
			if (son.size() <= now) {
				son.push_back(z);
				son[now].zm[s[i] - 'a'] = ++idx;
				now = idx;
			} else if (!son[now].zm[s[i] - 'a']) {
//				cout << son[now].zm[s[i] - 'a'] << "---\n";
				son[now].zm[s[i] - 'a'] = ++idx;
				now = idx;
			} else
				now = son[now].zm[s[i] - 'a'];
			if (son.size() <= now)
				son.push_back(z);
		}
		val[now].insert(id);
		now = 0;
//		cerr << "pass\n";
		for (int i = t.length() - 1; i >= 0; i--) {
//			cerr << now << ' ' << sn.size() << '\n';
			if (sn.size() <= now) {
				sn.push_back(z);
				sn[now].zm[t[i] - 'a'] = ++cnt;
				now = cnt;
			} else if (!sn[now].zm[t[i] - 'a']) {
				sn[now].zm[t[i] - 'a'] = ++cnt;
				now = cnt;
			} else
				now = sn[now].zm[t[i] - 'a'];
			if (sn.size() <= now)
				sn.push_back(z);
		}
		vl[now].insert(id);
	}
	int qry(string s, string t) {
		int now = 0;
		set<int>res = val[0];
		for (int i = 0; i < s.length(); i++) {
			if (son.size() <= now) {
				break;
			} else if (!son[now].zm[s[i] - 'a']) {
				break;
			} else
				now = son[now].zm[s[i] - 'a'];
			if (res.size() >= val[now].size()) {
				for (int v : val[now])
					res.insert(v);
			} else {
				set<int>rs = val[now];
				for (int v : res)
					rs.insert(v);
				res = rs;
			}
		}
		now = 0;
		int ans = 0;
		if (res.size() >= vl[now].size()) {
			for (int v : vl[now]) {
				if (res.find(v) != res.end())
					ans++;
			}
		} else {
			for (int v : res) {
				if (vl[now].find(v) != vl[now].end())
					ans++;
			}
		}
		for (int i = t.length() - 1; i >= 0; i--) {
			if (sn.size() <= now) {
				break;
			} else if (!sn[now].zm[t[i] - 'a']) {
				break;
			} else
				now = sn[now].zm[t[i] - 'a'];
			if (res.size() >= vl[now].size()) {
				for (int v : vl[now]) {
					if (res.find(v) != res.end())
						ans++;
				}
			} else {
				for (int v : res) {
					if (vl[now].find(v) != vl[now].end())
						ans++;
				}
			}
		}
		return ans;
	}
};
map<pair<string, string>, Trie>mp;

signed main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
//		cerr << i << '\n';
		string s, t;
		cin >> s >> t;
		int l = 0, r = s.length() - 1;
		while (l <= r and s[l] == t[l])
			l++;
		while (l <= r and s[r] == t[r])
			r--;
		if (l > r)
			continue;
//		cerr << l << ' ' << r << '\n';
		string pre = "", nxt = "", ss = "", tt = "";
		for (int j = 0; j < l; j++)
			pre += s[j];
		for (int j = r + 1; j < s.length(); j++)
			nxt += s[j];
		for (int j = l; j <= r; j++)
			ss += s[j], tt += t[j];
//		cout << ss << " " << tt << '\n';
		mp[ {ss, tt}].insert(nxt, pre, i);
	}
	for (int i = 1; i <= m; i++) {
//		cerr << i << '\n';
		string s, t;
		cin >> s >> t;
		int l = 0, r = s.length() - 1;
		while (l <= r and s[l] == t[l])
			l++;
		while (l <= r and s[r] == t[r])
			r--;
		if (l > r) {
			cout << "0\n";
			continue;
		}

		string pre = "", nxt = "", ss = "", tt = "";
		for (int j = 0; j < l; j++)
			pre += s[j];
		for (int j = r + 1; j < s.length(); j++)
			nxt += s[j];
		for (int j = l; j <= r; j++)
			ss += s[j], tt += t[j];
		cout << mp[ {ss, tt}].qry(nxt, pre) << '\n';
	}
	return 0;
}