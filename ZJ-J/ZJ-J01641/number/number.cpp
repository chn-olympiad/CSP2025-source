#include <bits/stdc++.h>
using namespace std;
#define int long long
string s;
int a[100]; 
signed main() {
//	system("fc number.out number4.ans");
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	std::ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin >> s;
	for(int i = 0; i < s.size(); i ++) if(s[i] >= '0' && s[i] <= '9') a[s[i] - '0'] ++;
	int p = 0;
	for(int i = 9; i >= 0; i --) {
		if(i == 0 && a[i] && !p) {
			cout << 0;
			break;
		}
		for(int j = 1; j <= a[i]; j ++) p = 1, cout << i; 
	}
	return 0;
}
