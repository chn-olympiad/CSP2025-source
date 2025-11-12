#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 220000;
int n, q, l, r;
string s[N][2], t[N][2];
ll ans = 0;

int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n >> q;
	for(int i=1; i<=n; i++) {
		cin >> s[i][0] >> s[i][1];
	}
	for(int i=1; i<=q; i++) {
		ans = 0;
		cin >> t[i][0] >> t[i][1];
		for(int j=0; j<t[i][0].length(); j++) if(t[i][0][j] != t[i][1][j]) {
			l = j; break;
		}
		for(int j=t[i][0].length()-1; j>=0; j--) if(t[i][0][j] != t[i][1][j]) {
			r = j; break;
		}
		//cout << l << " " << r << "\n";
		
		int len = t[i][0].length();
		for(int j=1; j<=n; j++) {
			for(int k=0; k<=(int)len-(int)s[j][0].length(); k++) {
				if(k <= l && k+s[j][0].length()-1 >= r)
	                if(t[i][0].substr(k,s[j][0].length()) == s[j][0] && t[i][1].substr(k,s[j][1].length()) == s[j][1]) {
	                	//cout << t[i][0].substr(k,s[j][0].length()) << " " << t[i][1].substr(k,s[j][1].length()) << "\n"; 
	                    ans++;
	                    break;
	                }
			}
		}
		cout << ans << "\n";
	}

	return 0;
}



