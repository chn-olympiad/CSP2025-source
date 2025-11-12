#include <bits/stdc++.h>
using namespace std;
int cnt[10];
int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	string t;
	cin >> t;
	for(int i=0; i<t.size(); ++i) {
		if(t[i]>='0'&&t[i]<='9') ++ cnt[t[i]-'0'];
	}
	for(int i=9; i>=0; --i) {
		for(int j=1; j<=cnt[i]; ++j) cout << i;
	}
	return 0;
}
