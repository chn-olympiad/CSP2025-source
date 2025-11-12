#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 1e6 + 100;;

int n, m;
map<string, string> mp; 

void work1(string s1, string s2) {
	ll ans = 0;
	for (int len = 1; len < s1.size(); len++) {
		for (int i = 1; i < s1.size() && i + len - 1 < s1.size(); i++) {
			int j = i + len - 1;
			string tmp;
			for (int k = i; k <= j; k++) tmp = tmp + s1[k];
			if (mp.count(tmp)) {
				tmp = mp[tmp];
				
				string s1t = s1;
				int index = 0; 
				bool flag = true;
				
				for (int k = i; k <= j; k++) {
					s1t[k] = tmp[index++];
				}
				for (int k = 1; k < s1.size(); k++) {
					if (s1t[k] != s2[k]) {
						flag = false;
						break;
					}
				}
				if (flag) ans++;
			}
		}
	}
	
	cout << ans << endl;
}
void solve() {
	string s1, s2;
	cin >> s1 >> s2;
	s1 = ' ' + s1;
	s2 = ' ' + s2;
	
	work1(s1, s2);
}

int main() {
	
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		string s1, s2;
		cin >> s1 >> s2;
		mp[s1] = s2;
		mp[s2] = s1;
	}
	
	for (int i = 1; i <= m; i++) solve();
	
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
