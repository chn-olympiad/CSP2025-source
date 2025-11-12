#include <bits/stdc++.h>
using namespace std;
const int N = 2e5+5;

string s1[N];
string s2[N];

map<string, string> mp;

int solve(string t1, string t2) {
	int l=0;
	int r=t1.len()-1;
	while(t1[l]==t2[l]) l++;
	while (t1[r]==t2[r]) r--;
	string sub1 = t1.substr(l, r-l+1);
	string sub2 = t2.substr(l, r-l+1);
	if (mp[sub1]==sub2) return 1;
	return 0;
}

int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	int n, q;
	cin >> n >> q;
	cin >> s1 >> s2;
	for (int i=1;i<=n;i++) {
		cin >> s1[i] >> s2[i];
		mp[s1[i]] = s2[i];
	}
	string t1, t2;
	for (int i=1;i<=q;i++) {
		cin >> t1 >> t2;
		cout << solve(t1, t2);
	}
	
	
	
	return 0;
}