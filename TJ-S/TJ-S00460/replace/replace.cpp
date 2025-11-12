#include<iostream>
#include<string>
#include<vector>
using namespace std;
const int a[2] = {29, 31}, mod[2] = {1000000007, 1000000009};
const int maxlen = 5e6 + 10;
const int maxn = 2e5 + 10;
string s1[maxn], s2[maxn], t1, t2;
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
int main()
{
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	cin >> n >> q;
	for(int j = 0; j < 2; j++) {
		pw[0][j] = 1;
		for(int i = 1; i < maxn; i++) {
			pw[i][j] = pw[i-1][j] * a[j] % mod[j];
		}
	}
	for(int i = 1; i <= n; i++) {
		cin >> s1[i] >> s2[i];
		store_hash(s1[i], hs1[i]);
		store_hash(s2[i], hs2[i]);
	}
	while(q--) {
		cin >> t1 >> t2;
		if(t1.length() != t2.length()) {
			cout << 0 << endl;
			continue;
		}
		store_hash(t1, ht1);
		store_hash(t2, ht2);
		int len = t1.length();
		int l = 0, r = len - 1;
		long long ans = 0;
		while(t1[l] == t2[l]) l++;
		while(t1[r] == t2[r]) r--;
		l++;
		r++;
		pair<int, int> t1y = get_hash(ht1, l, r);
		pair<int, int> t2y = get_hash(ht2, l, r);
		//cerr << "lr: " << l << " " << r << endl;
		//output(t1y);
		//output(t2y);
		for(int i = 1; i <= n; i++) {
			int len = s1[i].length();
			for(int start = 1; start <= len - (r-l+1) + 1; start++) {
				int end = start + (r-l+1) - 1;
				pair<int, int> s1y = get_hash(hs1[i], start, end);
				pair<int, int> s2y = get_hash(hs2[i], start, end);
				//cout << "istart: " << i << " " << start << endl;
				//output(s1y);
				//output(s2y);
				if(s1y != t1y || s2y != t2y) continue;
				if(start > l) continue;
				pair<int, int> s1x = get_hash(hs1[i], 1, start - 1);
				pair<int, int> s2x = get_hash(hs2[i], 1, start - 1);
				pair<int, int> t1x = get_hash(ht1, l - start + 1, l - 1);
			        if(s1x != t1x || s2x != t1x) continue;
				int t1len = t1.length();
				if(t1len - r < len - end) continue;
				pair<int, int> s1z = get_hash(hs1[i], end + 1, len);
				pair<int, int> s2z = get_hash(hs2[i], end + 1, len);
				pair<int, int> t1z = get_hash(ht1, r + 1, r - end + len);
				if(s1z != t1z || s2z != t1z) continue;
				ans++;
			}
		}
		cout << ans << endl;		
	}	
	return 0;
}
