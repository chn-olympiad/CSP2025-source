#include <bits/stdc++.h>
#define ll long long
#define Fcin; ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
map<int, int> mp;
int main () {
	Fcin;
	freopen ("number.in", "r", stdin);
	freopen ("number.out", "w", stdout); 
	string s; cin >> s;
	for (int i = 0; i < s.size (); i++) {
		if (s[i] >= '0' && s[i] <= '9')
		  mp[s[i] - '0']++;
	}
	for (int i = 9; i >= 0; i--) {
		for (int j = 1; j <= mp[i]; j++)
		  cout << i;
	}
	return 0;
}

