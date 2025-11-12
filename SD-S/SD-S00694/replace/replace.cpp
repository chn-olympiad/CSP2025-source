#include <bits/stdc++.h>
using namespace std;
int n, q;
string s[100005][2], s1, s2;
typedef long long li;
unsigned li pp666(string w) {
	unsigned li res=0;
	for(int i=0; i<w.size(); i++) {
		res=(res*131)+w[i];
	}
	return res;
}
int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> q;
	for(int i=1; i<=n; i++) {
		cin >> s[i][0] >> s[i][1];
	}
	for(int i=1; i<=q; i++) {
		cin >> s1 >> s2;
		if(s1.size()!=s2.size()) {
			cout << -1 << "\n";
			continue; 
		}
		int m=s1.size();
		bitset <m+5> b1b2;
		int ppd=0;
		for(int i=0; i<m; i++) {
			b1b2.add(s1[i]==s2[i]);
			if((s1[i]==s2[i])^(s1[max(i-1, 0)]==s2[min(i-1, 0)])) ppd++;
		}
		cout << ppd << "\n";
	}
}
