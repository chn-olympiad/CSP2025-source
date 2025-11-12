// YN-S00215 T3 100PTS
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
int n, q;

map<pair<int, int>, vector<pair<int, int>>> mp;
// For every valid hash i,j, mp[i,j] points to a vector of hashes
// of prefixes and suffixes
vector<int> rd (256, 0);

int cusHash(string &s) {
	int val = 0;
	for (int i = 0; i < s.size(); i++) {
		val += (rd[s[i]] ^ i) + s[i];
	}
	return val;
}

vector<int> cusHash(string &s, bool trash) {
	vector<int> val;
	val.push_back(0);
	// val.push_back((rd[s[0]] ^ 0) + s[0]);
	// cout << "val" << " " << val[0] << endl;
	for (int i = 0; i < s.size(); i++) {
		int res = val.back();
		val.push_back(res + (rd[s[i]] ^ i) + s[i]);
	}
	return val;
}

// Note to myself: pref is hashed in reverse order
signed main() {
	srand(time(0));
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	for (int i = 'a'; i <= 'z'; i++) {
		rd[i] = ((rand() % 32767) << 16) + (rand() % 32767);
		// random 32bit int
	}
//	string test = "a";
//	cout << rd['a'] + 'a' << endl;
//	cout << cusHash(test) << " " << cusHash(test, 0).back();
//	cout << "-" << endl;
	cin >> n >> q;
	for (int i = 0; i < n; i++) {
		string s, t;
		cin >> s >> t;
		int st = -1;
		int la = -1;
		for (int j = 0; j < s.size(); j++) {
			if (s[j] != t[j]) {
				la = j;
				if (st == -1) {
					st = j;
				}
			}
		}
		string pref;
		for (int i = 0; i < st; i++) {
			pref.push_back(s[i]);
		}
		reverse(pref.begin(), pref.end());

		string s1, t1;
		for (int i = st; i <= la; i++) {
			s1.push_back(s[i]);
			t1.push_back(t[i]);
		}

		string suff;
		for (int i = la + 1; i < s.size(); i++) {
			suff.push_back(s[i]);
		}
		// reverse(suff.begin(), suff.end());
		mp[ {cusHash(s1), cusHash(t1)}].emplace_back
		(cusHash(pref), cusHash(suff));
	}
//	for (auto nums : mp) {
//		cout << nums.first.first << " " << nums.first.second <<
//		     " " << nums.second.size() << endl;
//		for (auto num : nums.second) {
//			cout << num.first << " " << num.second << "    ";
//		}
//		cout << endl << endl;
//	}
//	cout << endl << "---" << endl;
	while (q--) {
		string s, t;
		cin >> s >> t;
		int st = -1;
		int la = -1;
		for (int j = 0; j < s.size(); j++) {
			if (s[j] != t[j]) {
				la = j;
				if (st == -1) {
					st = j;
				}
			}
		}
		string pref;
		for (int i = 0; i < st; i++) {
			pref.push_back(s[i]);
		}
		reverse(pref.begin(), pref.end());

		string s1, t1;
		for (int i = st; i <= la; i++) {
			s1.push_back(s[i]);
			t1.push_back(t[i]);
		}

		string suff;
		for (int i = la + 1; i < s.size(); i++) {
			suff.push_back(s[i]);
		}
		// reverse(suff.begin(), suff.end());

		vector<int> prefHash = cusHash(pref, 0);
		vector<int> suffHash = cusHash(suff, 0);
		// prefHash.insert(prefHash.begin(), 0);
		// suffHash.insert(suffHash.begin(), 0);

//		cout << pref << " " << suff << endl;
//		for (auto nums : prefHash) {
//			cout << nums << " ";
//		}
//		cout << endl;
//		for (auto nums : suffHash) {
//			cout << nums << " ";
//		}
//		cout << endl;

		int sHash = cusHash(s1);
		int tHash = cusHash(t1);

		int cnt = 0;
		for (auto nums : mp[ {sHash, tHash}]) {
			int prefCand = nums.first;
			int suffCand = nums.second;
			if (prefHash[
			            lower_bound(prefHash.begin(), prefHash.end(), prefCand) - prefHash.begin()]
			        == prefCand &&
			        suffHash[
			            lower_bound(suffHash.begin(), suffHash.end(), suffCand) - suffHash.begin()]
			        == suffCand)
				cnt++;
		}
		cout << cnt << endl;
	}
	return 0;
}