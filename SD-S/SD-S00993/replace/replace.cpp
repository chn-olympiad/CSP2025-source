#include <bits/stdc++.h>
using namespace std;

namespace myb {
	using ll = long long;
	using ull = unsigned long long;
	
	const int N = 5e6 + 6;
	const int P = 31;
	
	string s1[N], s2[N];
	int S[N];
	
	ull hsh[N][2];
	ull p[N];
	ull get(int l, int r, int x) {
		return hsh[r][x] - hsh[l - 1][x] * p[r - l + 1];
	}
	
	vector<ull> Hash[N][2];
	
	ull get_hsh(int l, int r, int x, int y) {
		return Hash[x][y][r] - Hash[x][y][l - 1] * p[r - l + 1];
	}
	
	void main() {
		int n, q;
		cin >> n >> q;
		for (int i = 1;i <= n;i++) {
			cin >> s1[i] >> s2[i];
			S[i] = s1[i].size();
			s1[i] = " " + s1[i];
			s2[i] = " " + s2[i];
			Hash[i][0].resize(S[i] + 1);
			Hash[i][1].resize(S[i] + 1);
			for (int j = 1;j <= S[i];j++) {
				Hash[i][0][j] = Hash[i][0][j - 1] * P + (ull)(s1[i][j] - 'a');
				Hash[i][1][j] = Hash[i][1][j - 1] * P + (ull)(s2[i][j] - 'a');
			}
		}
		
		
		p[0] = 1;
		for (int i = 1;i < N;i++) p[i] = p[i - 1] * P;
		
//		cout << get_hsh(1, 2, 1, 0) << " " << get_hsh(1, 2, 1, 1) << "\n";
		
		
		while (q--) {
			string t1, t2;
			cin >> t1 >> t2;
			if (t1.size() != t2.size()) {
				cout << 0 << "\n";
				continue;
			}
			int T = t1.size();
			t1 = " " + t1;
			t2 = " " + t2;
			
			for (int i = 1;i <= T;i++) {
				hsh[i][0] = hsh[i - 1][0] * P + t1[i] - 'a';
				hsh[i][1] = hsh[i - 1][1] * P + t2[i] - 'a';
			}
			
			int L, R;
			L = R = -1;
			for (int i = 1;i <= T;i++) {
				if (t1[i] == t2[i]) continue;
				int l, r, ans = 1;
				l = 1, r = i;
				while (l <= r) {
					int mid = l + r >> 1;
					if (get(1, mid, 0) != get(1, mid, 1)) {
						r = mid - 1;
						ans = mid;
					}
					else l = mid + 1;
				}
				L = ans;
				R = i;
			}
			if (L == -1 && R == -1) {
				cout << 0;
				continue;
			}
			
			
			int len = R - L + 1;
			int ans = 0;
//			cerr << q;
			for (int i = 1;i <= n;i++) {
				for (int j = 1;j <= S[i];j++) {
					if (j + len - 1 <= S[i] && 
						get(L, R, 0) == get_hsh(j, j + len - 1, i, 0) && 
						get(L, R, 1) == get_hsh(j, j + len - 1, i, 1)) 
					{
						if (L - j + 1 >= 1 && R + (S[i] - (j + len - 1)) <= T) {
							if (get(L - j + 1, R + S[i] - (j + len - 1), 0) == Hash[i][0][S[i]] && 
								get(L - j + 1, R + S[i] - (j + len - 1), 1) == Hash[i][1][S[i]])
							{
								ans++;	
							}
						}		
					}
				}
			}
			cout << ans << "\n";
		}
	}
}

int main() {
	ios :: sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	myb::main();
	return 0;
}


