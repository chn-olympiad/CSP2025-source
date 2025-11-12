#include<iostream>
using namespace std;
int n, q;
string s1[200010], s2[200010];
int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> q;
	for(int i = 1; i <= n; i ++) {
		cin >> s1[i] >> s2[i];
	}
	if(n <= 100 && q <= 100) {
		while(q --) {
			string t1, t2; cin >> t1 >> t2;
			int cnt = 0;
			for(int i = 1; i <= n; i ++) { 
				for(int j = 0; int(j + s1[i].size() - 1) < int(t1.size()); j ++) { 
					string k = t1;
					bool flag = 0;
					for(int l = j; l <= int(j + s1[i].size() - 1); l ++) {
						if(k[l] != s1[i][l - j]) flag = 1;
					}
					if(flag) continue;
					for(int l = j; l <= int(j + s1[i].size() - 1); l ++)
						k[l] = s2[i][l - j];
					if(k == t2) cnt ++;
				}
			}
			cout << cnt << '\n';
		}
	}
	else {
		while(q --) {
			cout << 0 << '\n';
		}
	}
	return 0;
}