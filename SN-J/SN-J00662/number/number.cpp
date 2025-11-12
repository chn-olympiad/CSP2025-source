#include <bits/stdc++.h>
using namespace std;

long long t [15] = {0};
string s;

int main() {

freopen("number.in","r",stdin);
freopen("number.out","w",stdout);

ios::sync_with_stdio(0);
cin.tie(0); cout.tie(0);

	cin >> s;
	int len = s.size();
	for(int i = 0;i < len;i++) {
		if(s[i] >= '0' and s[i] <= '9') {
			int m = s[i] - 48;
			t[m]++;
		}
	}
	for(int i = 9;i >= 0;i--) {
		if(t[i] != 0) {
			for(int j = 1;j <= t[i];j++) {
				cout << i;
			}
		}
	}
	
	return 0;
}

