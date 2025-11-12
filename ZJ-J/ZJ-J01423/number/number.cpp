#include <bits/stdc++.h>

#define debug(x) cerr << #x << ": " << x << '\n'

using namespace std;

typedef long long LL;

inline LL read() { LL x = 0, f = 1; char ch; while(!isdigit(ch = getchar())) if (ch == '-') f = -1; do x = (x << 3) + (x << 1) + (ch ^ 48); while(isdigit(ch = getchar())); return x * f; }

int mp[10];
int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	
	string s, ans = ""; cin >> s;
	
	for (char it : s) {
		if ('0' <= it && it <= '9') {
			if (it == '0') mp[0] ++;
			else if (it == '1') mp[1] ++;
			else if (it == '2') mp[2] ++;
			else if (it == '3') mp[3] ++;
			else if (it == '4') mp[4] ++;
			else if (it == '5') mp[5] ++;
			else if (it == '6') mp[6] ++;
			else if (it == '7') mp[7] ++;
			else if (it == '8') mp[8] ++;
			else if (it == '9') mp[9] ++;
		}
	}
	
	for (int i = 9; i >= 0; i--) {
		for (int j = 0; j < mp[i]; j++) {
			ans += char(i + 48);
		}
	}
	
	cout << ans << '\n';
	
	return 0;
}
