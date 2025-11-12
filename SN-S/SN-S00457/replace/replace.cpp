#include <bits/stdc++.h>
#define int long long
using ull = unsigned int;
using namespace std;
const int N = 2e5 + 10, B = 31, M = 5e6 + 10;
int n, Q, L;
string s[N][3], t[N][3];


namespace Subtask1 {
	ull h[N][3], p1[N], p2[N], pwb[M];
	
	ull has(const string& str) {
		ull res = 0;
		for (char ch : str) {
			res = res * B + ch - 'a' + 1;
		}
		return res;
	}
	
	
	inline ull get1(int l, int r) {
		return p1[r] - p1[l - 1] * pwb[r - l + 1];
	}
	
	inline ull get2(int l, int r) {
		return p2[r] - p2[l - 1] * pwb[r - l + 1];
	}
	
	void solve() {
		pwb[0] = 1;
		for (int i = 1; i <= L; i++) {
			pwb[i] = pwb[i - 1] * B;
		}
		
		for (int i = 1; i <= n; i++) {
			h[i][1] = has(s[i][1]);
			h[i][2] = has(s[i][2]);
		}
		
		for (int q = 1; q <= Q; q++) {
			int ans = 0;
			int siz = t[q][1].size() - 1;
			for (int i = 1; i <= siz; i++) {
				p1[i] = p1[i - 1] * B + t[q][1][i] - 'a' + 1;
				p2[i] = p2[i - 1] * B + t[q][2][i] - 'a' + 1;
			}
			
			for (int i = 1; i <= n; i++) {
				int len = s[i][1].size();
				for (int j = 1; j + len - 1 <= siz; j++) {
					if (get1(j, j + len - 1) == h[i][1] && 
						get2(j, j + len - 1) == h[i][2] &&
						get1(1, j - 1) == get2(1, j - 1) &&
						get1(j + len, siz) == get2(j + len, siz)
						) 
						ans++;
				}
			}
			cout << ans << '\n';
		}
	}
}

signed main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> Q;
	for (int i = 1; i <= n; i++) {
		cin >> s[i][1] >> s[i][2];
		L += s[i][1].size() + s[i][2].size();
	}
	for (int i = 1; i <= Q; i++) {
		cin >> t[i][1] >> t[i][2];
		t[i][1] = '0' + t[i][1];
		t[i][2] = '0' + t[i][2];
	}
	Subtask1::solve();
	
	return 0;
}

