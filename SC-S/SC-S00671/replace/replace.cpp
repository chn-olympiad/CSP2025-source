#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int n, q; 
struct node{
	string s1, s2;
}dic[N];
int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	cin >> n >> q;
	for (int i = 1; i <= n; i++) {
		cin >> dic[i].s1 >> dic[i].s2;
	}
	while (q--) {
		string a, b;
		cin >> a >> b;
		int cnt = 0;
		for (int i = 1; i <= n; i++) {
			for (int j = 0; j <= int(a.size()) - int(dic[i].s1.size()); j++) {
//				cout<< i << " " << j << " " << a.size() - dic[i].s1.size() << endl;
				if (a.substr(j, dic[i].s1.size())== dic[i].s1) {
					if (a.substr(0, j) + dic[i].s2 + a.substr(j + dic[i].s1.size(), a.size() - dic[i].s1.size() - j) == b) {
						cnt ++;
					}
				}
			}
		}
		cout << cnt << '\n';
	}
	return 0;
}