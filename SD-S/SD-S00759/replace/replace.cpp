#include<bits/stdc++.h>
#define int long long
using namespace std;
string s1[200005], s2[200005];
signed main(){
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	int n, q;
	cin >> n >> q;
	
	for(int i = 1; i <= n; i++){
		cin >> s1[i] >> s2[i];
	}
	for(int i = 1; i <= q; i++){
		string t1, t2;
		cin >> t1 >> t2;
		if(t1.size() != t2.size()){
			cout << 0 << endl;
			continue;
		}
		int ans = 0, len = 0;
		string s = "";
		for(int j = 1; j <= n; j++){
			for(int k = 0; k < t1.size(); k++){
				s += t1[k];
				if(s.size() > s1[j].size()){
					len++;
				}
				int f = 0;
				for(int p = len; p <= s.size(); p++){
					if(s1[j][p] != t1[p - len]){
						f = 1;
					}
				}
				if (f == 0) ans++;
			}
		}
		cout << ans << endl;
	} 
	return 0;
}
