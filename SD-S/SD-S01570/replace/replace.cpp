#include<bits/stdc++.h>
using namespace std;
int n, q;
const int N = 1e6 + 5;
string a[N], b[N];
int main(){
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	cin >> n >> q;
	for(int i = 1; i <= n; i++) {
		cin >> a[i] >> b[i];
	}
	while(q--) {
		string s1, s2;
		cin >> s1 >> s2;
		int cnt = 0;
		for(int i = 1; i <= n; i++) {
			for(int j = 0; j + a[i].size() <= s1.size(); j++) {
				string s = s1;
				if(s1.substr(j, a[i].size()) == a[i]) {
					s.replace(j, a[i].size(), b[i]);
				}
				if(s == s2) {
					cnt++;
				}
			}
		}
		cout << cnt << '\n';
	}
	return 0;
}
