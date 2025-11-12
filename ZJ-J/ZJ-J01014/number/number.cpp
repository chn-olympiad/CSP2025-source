#include <bits/stdc++.h>
using namespace std;
#define int long long

string str;
int p[10];

signed main() {
	
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	
	getline(cin, str);
	for(int i = 0; i < str.size(); ++i) {
		if(str[i] >= '0' && str[i] <= '9')
			p[str[i] - '0']++;
	}
	for(int i = 9; i >= 0; --i) {
		while(p[i]--)
			printf("%lld", i);
	}
	return 0;
}