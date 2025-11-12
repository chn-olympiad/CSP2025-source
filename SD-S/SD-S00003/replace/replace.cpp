#include <bits/stdc++.h>

using namespace std;

const int Base = 233, mod = 1e9 + 7;

bool B1;

int n, q;
string s1, s2;
int Hash1[5000010], Hash2[5000010], powB[5000010];
map<pair<int, int>, vector<int>> ma, ma1;
string qs1[200010], qs2[200010];

int get(int l, int r, int Hash[]) {
	int ans = 1ll * Hash[r] - 1ll * (l ? Hash[l - 1] : 0ll) * powB[r - l + 1] % mod;
	if (ans < 0) ans += mod;
	
	return ans;
}

bool B2;

int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	powB[0] = 1;
	for (int i = 1; i <= 5000000; ++i) powB[i] = 1ll * powB[i - 1] * Base % mod; 

	cin >> n >> q;
	
	bool flag = true;
	for (int i = 1; i <= n; ++i) {
		cin >> s1 >> s2;
		
		int cntb = 0, cnta = 0;
		for (auto ch : s1) {
			if (ch == 'a') ++cnta;
			if (ch == 'b') ++cntb;
		}
		
		int id = -1, sz = s1.size();
		
		flag &= (cntb == 1) && (cnta + cntb == sz);
		
		cntb = 0, cnta = 0;
		for (auto ch : s2) {
			if (ch == 'a') ++cnta;
			if (ch == 'b') ++cntb;
		}

		flag &= (cntb == 1) && (cnta + cntb == sz);
		
		for (int j = sz - 1; j >= 0; --j) {
			if (s1[j] != s2[j]) {
				id = j;
				break;
			}
		}
		
		if (id == -1) continue;
		
		int Hash = 0;
		for (int j = 0; j <= id; ++j) {
			Hash = (1ll * Hash * Base % mod + s1[j]) % mod;
		}
		int Hash1 = 0;
		for (int j = 0; j <= id; ++j) {
			Hash1 = (1ll * Hash1 * Base % mod + s2[j]) % mod;
		}
		
		int Hash2 = 0;
		for (int j = id + 1; j < sz; ++j) {
			Hash2 = (1ll * Hash2 * Base % mod + s1[j]) % mod;
		}
		
		ma[{Hash, Hash1}].push_back(Hash2);
		ma1[{Hash, Hash1}].push_back(sz - id - 1);
//		cout << "----" << Hash << ' ' << Hash1 << endl;
	}
	
	for (int i = 1; i <= q; ++i) {
		cin >> qs1[i] >> qs2[i];

		int cntb = 0, cnta = 0;
		for (auto ch : qs1[i]) {
			if (ch == 'a') ++cnta;
			if (ch == 'b') ++cntb;
		}

		flag &= (cntb == 1) && (cnta + cntb == (qs1[i].size()));
		
		cntb = 0, cnta = 0;
		for (auto ch : qs2[i]) {
			if (ch == 'a') ++cnta;
			if (ch == 'b') ++cntb;
		}

		flag &= (cntb == 1) && (cnta + cntb == (qs2[i].size()));
	}
	
	if (flag) {
		for (auto &v : ma1) sort(v.second.begin(), v.second.end());

		for (int i = 1; i <= q; ++i) {
			s1 = qs1[i], s2 = qs2[i];
			
			if (s1.size() != s2.size()) {
				cout << "0\n";
				continue;
			}
			
			int sz = s2.size();
			Hash1[0] = s1[0];
			for (int j = 1; j < sz; ++j) {
				Hash1[j] = (1ll * Hash1[j - 1] * Base % mod + s1[j]) % mod;
			}
			Hash2[0] = s2[0];
			for (int j = 1; j < sz; ++j) {
				Hash2[j] = (1ll * Hash2[j - 1] * Base % mod + s2[j]) % mod;
			}
			
			int id = 0;
			for (int j = sz - 1; j >= 0; --j) if (s1[j] != s2[j]) {
				id = j;
				break;
			}
			
			int ans = 0;
			for (int j = 0; j < sz; ++j) {
				if (j && s1[j - 1] != s2[j - 1]) break;
				int hs1 = get(j, id, Hash1), hs2 = get(j, id, Hash2);
	//			cout << "____" << hs1 << ' ' << hs2 << endl;
				
				int Sz = ma1[{hs1, hs2}].size(), mx = sz - id - 1;
				
				if (!Sz) continue;
				
				vector<int> t = ma1[{hs1, hs2}];

				int l = 0, r = Sz - 1;
				while (l < r) {
					int mid = (l + r + 1) >> 1;
					if (t[mid] <= mx) l = mid;
					else r = mid - 1;
				}
				
				vector<int>().swap(t);
				
				if (ma1[{hs1, hs2}][l] > mx) continue;
//				if (i == 102) cerr << l << ' ' << ma1[{hs1, hs2}][0] << ' ' << hs1 << ' ' << hs2 << ' ' << j << ' ' << id << ' ' << s1[j] << ' ' << s2[j] << endl;
				ans += l + 1;
			}
			
			cout << ans << "\n";
		}
		
		cout.flush();
		return 0;
	}
	
	for (int i = 1; i <= q; ++i) {
		s1 = qs1[i], s2 = qs2[i];
		if (s1.size() != s2.size()) {
			cout << 0 << "\n";
			continue;
		}

		int sz = s2.size();
		Hash1[0] = s1[0];
		for (int j = 1; j < sz; ++j) {
			Hash1[j] = (1ll * Hash1[j - 1] * Base % mod + s1[j]) % mod;
		}
		Hash2[0] = s2[0];
		for (int j = 1; j < sz; ++j) {
			Hash2[j] = (1ll * Hash2[j - 1] * Base % mod + s2[j]) % mod;
		}
		
		int id = 0;
		for (int j = sz - 1; j >= 0; --j) if (s1[j] != s2[j]) {
			id = j;
			break;
		}
		
		map<int, int> mp;
		for (int j = 0; j < sz; ++j) {
			int hs1 = get(j, id, Hash1), hs2 = get(j, id, Hash2);
//			cout << "____" << hs1 << ' ' << hs2 << endl;

			for (auto t : ma[{hs1, hs2}]) {
				mp[t]++;
//				if (i == 101)
//					cout << "?" << ' ' << t << endl;
			}

			if (s1[j] != s2[j]) break;
		}
		
		int ans = 0;
		for (int j = id + 1; j < sz; ++j) {
			int Hs = get(id + 1, j, Hash1);
//			if (i == 101) cout << Hs << endl;
			
			ans += mp[Hs];
		}
		
		cout << ans + mp[0] << "\n";
	}
	
	cout.flush();

	return 0;
}

