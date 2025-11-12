#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n , q;
string s1[105] , s2[105];
string t1 , t2;
unordered_map < string , unordered_map < string , int > > vis;

signed main() {
	
	freopen("replace.in" , "r" , stdin);
	freopen("replace.out" , "w" , stdout);
	
	scanf("%d%d" , &n , &q);
	for (int i = 1 ; i <= n ; i++) {
		cin >> s1[i] >> s2[i];
		vis[s1[i]][s2[i]]++;
	}
	while(q--) {
		cin >> t1 >> t2;
		int s = -1;
		for (int i = 0 ; i < t1.size() ; i++)
			if (t1[i] != t2[i]) {
				s = i;
				break;
			}
		int e = t1.size();
		for (int i = t1.size() - 1 ; i >= 0 ; i--)
			if (t1[i] != t2[i]) {
				e = i;
				break;
			}
		if (s == -1) {
			
		}
		else {
			int ans = 0;
			for (int l = s ; l >= 0 ; l--) {
				for (int r = e ; r < t1.size() ; r++) {
					ans += vis[t1.substr(l , r - l + 1)][t2.substr(l , r - l + 1)];
				}
			}
			printf("%d\n" , ans);
		}
	}
	
	return 0;
}
