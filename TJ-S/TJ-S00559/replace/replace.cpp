#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10;

string s1[N], s2[N];

int main() {
	
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	
	int n, q;
	cin >> n >> q;
	for(int i = 1; i <= n; i++) {
		cin >> s1[i] >> s2[i];
	}
	while(q--) {
		string t1, t2;
		cin >> t1 >> t2;
		int l = t1.size();
		int cnt = 0;
		for(int i = 1; i <= n; i++) {
			if(t1 == s1[i] && t2 == s2[i]) {
				cnt++;
			} 
			else if(t1.find(s1[i]) && t2.find(s2[i])) {
				int len = s1[i].size();
				for(int j = 0; j <= l - len; j++) {
					if(t1.substr(j, len) == s1[i] && t2.substr(j, len) == s2[i]) {
						cnt++;
						break;
					}
				} 
			}
		}
		cout << cnt << endl;
	}
	return 0;
} 
