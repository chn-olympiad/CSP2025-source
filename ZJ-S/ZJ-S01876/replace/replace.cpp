#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define upl(i, s, t, d) for(int i = (s); i <= (t); i += (d))
#define dol(i, s, t, d) for(int i = (s); i >= (t); i -= (d))
//#define int long long
void INIT() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
}

const int MAXN = 2e5 + 10, MAX = 5e6 + 10;
string s[MAXN][2];
int ls[MAXN];

signed main() {
	INIT();
	srand(time(0));
	int n, q;
	cin >> n >> q;
	if(n <= 1e2){
		upl(i, 1, n, 1)  {
			cin >> s[i][0] >> s[i][1];
			ls[i] = s[i][0].length();
		}
		upl(i, 1, q, 1) {
			string t1, t2;
			cin >> t1 >> t2;
			int lt = t1.length();
			
			if(lt != t2.length()) {
				cout << 0 << "\n";
				continue;
			}
			
			int ans = 0;
			upl(j, 0, lt - 1, 1) {
				upl(k, 1, n, 1) {
					if(j + ls[k] > lt)
						continue;
					string s1 = (j <= 0 ? "AAA" : t1.substr(0, j)), s2 = (j <= 0 ? "AAA" : t2.substr(0, j));
					string s3 = (j + ls[k] == lt ? "AAA" : t1.substr(j + ls[k], lt - j - ls[k])), s4 = (j + ls[k] == lt ? "AAA" : t2.substr(j + ls[k], lt - j - ls[k]));
					string s5 = t1.substr(j, ls[k]), s6 = t2.substr(j, ls[k]);
//					cout << s1 << " " << s2 << " " << s3 << " " << s4 << " " << s5 << " " << s6 << "\n";	
					if(s5 == s[k][0] && s6 == s[k][1] && s1 == s2 && s3 == s4)
						ans++;
				}
			}
			cout << ans << "\n";
		}
		return 0;
	}
	return 0;
}

