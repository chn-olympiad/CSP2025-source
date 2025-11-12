#include <bits/stdc++.h>
#define int long long
#define endl "\n"
#define pt pair <string, string>
using namespace std;
const int N = 5e6 + 10;
pt e[N];
signed main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int n, q;
	cin >> n >> q;
	for(int i = 1; i <= n; i++) {
		string s1, s2;
		cin >> s1 >> s2;
		e[i] = {s1, s2};
	}
//	for(int i = 1; i <= n; i++){
//		cout <<e[i].first << " " << e[i].second << endl;
//	}
	while(q--){
		int cnt = 0;
		string x1, x2;
		cin >> x1 >> x2;
		for(int i = 1; i <= n; i++){
//			cout << i << " ";
			int id = x1.find(e[i].first);
			if(id != -1){
				string temp = x1;
				for(int j = 0; j < e[i].first.size(); j++){
					temp[id + j] = e[i].second[j];
				}
				if(temp == x2){
					cnt++;
//					cout << "rp++" << endl;
				}
			}
//			cout << id << endl;
		}
		cout << cnt << endl;
	}
	return 0;
}

/**

4 2
xabcx xadex
ab cd
bc de
aa bb
xabcx xadex
aaaa bbbb



3 4
a b
b c
c d
aa bb
aa b
a c
b a

*/
