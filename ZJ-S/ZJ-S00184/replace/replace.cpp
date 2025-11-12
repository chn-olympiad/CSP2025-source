#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll B = 101, P = 1e9 + 7;
const int N = 2e5 + 5;
string s1, s2, t1, t2;
//string S1, S2, T1, T2;
int n, q, len[N];
//struct yrd {
//	int first, last;
//} a[N];
//unordered_map<int, int> mp;

ll qpow(ll a, ll b) {
	ll ans = 1;
	while(b) {
		if(b & 1) ans = ans * a % P;
		a = a * a % P;
		b >>= 1;
	}
	return ans;
}

ll get_hash(string s) {
	ll ans = 0;
	for(int i = 0; i < s.size(); i++) {
		ans = ans * B + (s[i] - 'a');
		ans %= P;
	}
	return ans;
}
ll hash1[N], hash2[N], Hash1, Hash2;

int main(){
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	int fst, lst;
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin >> n >> q;
	if(1) {//n * q <= 1e6
		int cnt;
		for(int i = 1; i <= n; i++) {
			cin >> s1 >> s2;
			len[i] = s1.size();
			hash1[i] = get_hash(s1);
			hash2[i] = get_hash(s2);
//			cout << hash1[i] << " " << hash2[i] << endl;
		}
		for(int j = 1; j <= q; j++) {
			cnt = 0;
			cin >> t1 >> t2;
			for(int i = 0; i < t1.size(); i++) {
				if(t1[i] != t2[i]) {
					fst = i;
					break;
				}
			}
			for(int i = t1.size() - 1; i >= 0; i--) {
				if(t1[i] != t2[i]) {
					lst = i;
					break;
				}
			}
			for(int i = 1; i <= n; i++) {
				if(len[i] > t1.size()) continue;
				Hash1 = get_hash(t1.substr(0, len[i]));
				Hash2 = get_hash(t2.substr(0, len[i]));
				if(len[i] - 1 >= lst && hash1[i] == Hash1 && hash2[i] == Hash2) cnt++;
//				cout << i << " " << Hash1 << " " << Hash2 << endl;
				for(int k = len[i]; k < t1.size(); k++) {
					Hash1 = Hash1 * B + (t1[k] - 'a');
					Hash1 %= P;
					Hash1 = (Hash1 - qpow(B, len[i]) * (t1[k - len[i]] - 'a') % P + P) % P;
					Hash2 = Hash2 * B + (t2[k] - 'a');
					Hash2 %= P;
					Hash2 = (Hash2 - qpow(B, len[i]) * (t2[k - len[i]] - 'a') % P + P) % P;
					if(k - len[i] + 1 <= fst && k >= lst && hash1[i] == Hash1 && hash2[i] == Hash2) cnt++;
//					cout << i << " " << k << " " << Hash1 << " " << Hash2 << endl;
				}
			}
			cout << cnt << endl;
		}
	}
//	else {
//		for(int j = 1; j <= n; j++) {
//			cin >> S1 >> S2;
//			lft = fst, rit = S1.size() - 1 - lst;
//			a[j].first = fst, a[j].last = lst, a[j].left = lft, a[j].right = rit;
//		}
//		for(int j = 1; j <= q; i++) {
//			cin >> T1 >> T2;
//			for(int i = 0; i < T1.size(); i++) {
//				if(T1[i] != T2[i]) {
//					fst = i;
//					break;
//				}
//			}
//			for(int i = T1.size() - 1; i >= 0; i--) {
//				if(T1[i] != T2[i]) {
//					lst = i;
//					break;
//				}
//			}
//			lft = fst, rit = T1.size() - 1;
//			for(int i = 1; i <= n; i++) {
//				for(int i = 1; i <= n; i++) {
//					
//				}
//			}
//		}
//	}
	return 0;
}

