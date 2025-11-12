#include <bits/stdc++.h>
using namespace std;
int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	int n,q;
	cin >> n >> q;	
	string m1[10001], m2[10001];
	for (int i = 0 ;i <n; i++) {
		string a, b;
		cin >> a >> b;
		m1[i] = a;
		m2[i] = b;
	}
	while(q--) {
		string a, b;
		cin >> a >> b;
		string jie = "", guo  = "";
		for (int i = 0; i < a.size(); i++) {
			if (a[i] != b[i]) {
				jie += a[i];
				guo += b[i];
			}
		}
		int ans = 0;
		for (int i = 0; i < n; i++) {
			if (m1[i].find(jie) != string::npos && m2[i].find(guo) != string::npos && a.find(m1[i]) != string ::npos && b.find(m2[i]) != string::npos) {
				ans++;
			}
		}
		cout << ans <<endl;
	}
	return 0;
} 