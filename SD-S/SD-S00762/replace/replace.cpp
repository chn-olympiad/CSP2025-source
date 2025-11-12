#include <iostream>
#include <fstream>
#include <map>
#include <vector>
#include <random>
#include <ctime>
#include <algorithm>
using namespace std;
const int N = 2e5 + 10, V = 6e5 + 10;
string s1[N], s2[N], pre[N], suf[N];
map<string, vector<int>> mp;
using ull = unsigned long long;
vector<ull> hpre[N], hsuf[N];
ull val[V];
mt19937_64 rng(time(0));
inline vector<ull> get_hash(string s) {
	vector<ull> ans;
	ans.resize(s.size() + 1);
	for (int i = 0; i < s.size(); i++) ans[i + 1] = ans[i] + val[i] * s[i];
	return ans;
}
int main() {
	ifstream fin("replace.in");
	ofstream fout("replace.out");
	#define cin fin
	#define cout fout
	for (auto &x : val) x = rng();
	int n, q;
	cin >> n >> q;
	for (int i = 1; i <= n; i++) {
		auto &s1 = ::s1[i], &s2 = ::s2[i], &pre = ::pre[i], &suf = ::suf[i];
		cin >> s1 >> s2;
		if (s1 == s2) continue;
		int beg = 0, ed = s1.size() - 1;
		while (s1[beg] == s2[beg]) beg++;
		beg--;
		while (s1[ed] == s2[ed]) ed--;
		ed++;
		pre = "", suf = "";
		string s1only, s2only;
		if (beg >= 0) pre.assign(s1.begin(), s1.begin() + beg + 1);
		if (ed < s1.size()) suf.assign(s1.begin() + ed, s1.end());
//		if (i == 859) {
//			cout << s1 << " " << s2 << " " << beg << " " << ed << endl;
//		}
		s1only.assign(s1.begin() + beg + 1, s1.begin() + ed);
		s2only.assign(s2.begin() + beg + 1, s2.begin() + ed);
		mp[s1only + "+" + s2only].push_back(i);
		hpre[i] = get_hash(pre);
		reverse(suf.begin(), suf.end());
		hsuf[i] = get_hash(suf);
//		cout << i << endl;
	}
//	return 0;
	while (q--) {
		string t1, t2;
		cin >> t1 >> t2;
		int beg = 0, ed = t1.size() - 1;
		while (t1[beg] == t2[beg]) beg++;
		beg--;
		while (t1[ed] == t2[ed]) ed--;
		ed++;
		string pre_t = "", suf_t = "";
		string t1only, t2only;
		if (beg >= 0) pre_t.assign(t1.begin(), t1.begin() + beg + 1);
		if (ed < t1.size()) suf_t.assign(t1.begin() + ed, t1.end());
		t1only.assign(t1.begin() + beg + 1, t1.begin() + ed);
		t2only.assign(t2.begin() + beg + 1, t2.begin() + ed);
		auto &reg = mp[t1only + "+" + t2only];
		if (!reg.size()) {
			cout << 0 << endl;
			continue;
		}
		reverse(suf_t.begin(), suf_t.end());
		auto tpre = get_hash(pre_t), tsuf = get_hash(suf_t);
		int lpre = pre_t.size(), lsuf = suf_t.size();
		int tot = 0;
		for (auto x : reg) {
			if (pre[x].size() > lpre || suf[x].size() > lsuf) continue;
			tot += (hpre[x][pre[x].size()] == tpre[pre[x].size()] && hsuf[x][suf[x].size()] == tsuf[suf[x].size()]);
//			cout << tot << endl;
		}
		cout << tot << endl;
	}
}
