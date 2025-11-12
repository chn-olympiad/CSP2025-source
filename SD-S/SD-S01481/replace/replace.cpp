#include<bits/stdc++.h>
#define endl '\n'
//#define MSOD

using namespace std;
using ll = long long;

constexpr ll N = 2e5 + 5;

ll n, q;
ll len[N], pos1[N], pos2[N], dif[N];
string t1[N], t2[N];

inline void task1() {
	while(q --) {
		string s1, s2;
		cin>>s1>>s2;
		if(s1.size() != s2.size()) {
			cout<<0<<endl;
			continue;
		}
		ll m = s1.size(), ans = 0;
		for(int k = 1 ; k <= n ; k ++) {
			for(int i = 0 ; i + len[k] - 1 < m ; i ++) {//×ó¶Ëµã
				bool ok = true;
				for(int j = 0 ; j < len[k] ; j ++) {
					ok &= (s1[i + j] == t1[k][j]); 
				}
				if(!ok) {
					continue;
				}
				ok = true;
				for(int j = 0 ; j < m ; j ++) {
					if(j < i) {
						ok &= (s1[j] == s2[j]);
					} else if(j >= i && j <= i + len[k] - 1) {
						ok &= (t2[k][j - i] == s2[j]);
					} else {
						ok &= (s1[j] == s2[j]);
					}
				}
				ans += ok;
			}
		}
		cout<<ans<<endl;
	}
	return;
}
inline void task2() {
	for(int i = 1 ; i <= n ; i ++) {
		for(int j = 0 ; j < len[i] ; j ++) {
			if(t1[i][j] == 'b') {
				pos1[i] = j;
				break;
			}
		}
		for(int j = 0 ; j < len[i] ; j ++) {
			if(t2[i][j] == 'b') {
				pos2[i] = j;
				break;
			}
		}
		dif[i] = pos2[i] - pos1[i];
	}
	while(q --) {
		string s1, s2;
		cin>>s1>>s2;
		if(s1.size() != s2.size()) {
			cout<<0<<endl;
			continue;
		} else {
			ll p1 = 0, p2 = 0, m = s1.size(), ans = 0;
			for(int i = 0 ; i < m ; i ++) {
				if(s1[i] == 'b') {
					p1 = i;
					break;
				}
			}
			for(int i = 0 ; i < m ; i ++) {
				if(s2[i] == 'b') {
					p2 = i;
					break;
				}
			}
			for(int i = 1 ; i <= n ; i ++) {
				if(p2 - p1 == dif[i] && pos1[i] <= p1 && p1 - pos1[i] + len[i] - 1 < m) {
					ans ++;
				}
			}
			cout<<ans<<endl;
		}
	}
	return;
}
inline void solve() {
	cin>>n>>q;
	for(int i = 1 ; i <= n ; i ++) {
		cin>>t1[i]>>t2[i];
		len[i] = t1[i].size();
	}
	if(n <= 200 && q <= 200) {
		task1();
	} else {
		task2();
	}
	return;
}

signed main() {
	ios::sync_with_stdio(false), cout.tie(0), cin.tie(0);
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	int TC = 1;
#ifdef MSOD
	cin>>TC;
#endif
	while(TC --) {
		solve();
	}
	return 0;
}

