#include<bits/stdc++.h>
using namespace std;

const int N=2e5+5;
string s1[N], s2[N];
string t1[N], t2[N];
int ans = 0;

int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	int n, q; cin >> n >> q;
	for(int i=1; i<=n; i++) cin >> s1[i] >> s2[i];
	
	for(int i=1; i<=q; i++) {
		cin >> t1[i] >> t2[i];
		int l1 = t1[i].size(), l2 = t2[i].size()+1;
		t1[i] = ' ' + t1[i] + ' ';
		ans = 0;
		string s_1 = "", s_2 = "";
		for(int o=0; o<=l1; o++) {
			if(o != 0) s_1 += t1[i][o];
			s_2 = "";
			for(int j=l2; j>o; j--) {
				if(j != l2) s_1 = t1[i][j] + s_2;
				string str = "";
				for(int p=o+1; p<j; p++) {
					str += t1[p];
				}
				for(int l=1; l<=n; l++) {
					string s;
					if(str == s1[l]) {
						if(s_1 + s2[l] + s_2 == t2[i]) ans++;
					}
				}
			}
		}
		cout << ans << "\n";
	}
	return 0;
}
