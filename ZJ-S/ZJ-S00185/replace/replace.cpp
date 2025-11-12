#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 5e6 + 11;
int n , q , s1[N] , s2[N];
map <string , string> mp;

int main () {
	freopen("replace.in" , "r" , stdin);
	freopen("replace.out" , "w" , stdout);
	scanf ("%d%d" , &n , &q);
	for (int i = 1;i <= n;i++) {
		string s , t;
		cin >> s >> t;
		mp[s] = t;
	}
	for (int i = 1;i <= q;i++) {
		string s , t;
		cin >> s >> t;
		s = "_" + s , t = "_" + t;
		int n = s.size() - 1 , m = t.size() - 1;
		s1[0] = s2[n + 1] = 1;
		for (int i = 1;i <= n;i++) s1[i] = (s1[i - 1] & (s[i] == t[i]));
		for (int i = n;i >= 1;i--) s2[i] = (s2[i + 1] & (s[i] == t[i]));
		int ans = 0;
		for (int i = 1;i <= n;i++) {
			if (!s1[i - 1]) break;
			for (int j = i;j <= n;j++) {
				string str = s.substr(i , j - i + 1);
				if (s1[i - 1]&&s2[j + 1]&&mp[str] == t.substr(i , j - i + 1)) {
					ans++;
				}
			}
		}
		printf ("%d\n" , ans);
	}
	return 0;
}