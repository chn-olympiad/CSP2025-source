#include <bits/stdc++.h>
// #define DEBUG
using namespace std;
string s;
int cnt[10];
int main(){
#ifndef DEBUG
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
#endif
	cin >> s;
	for (int i = 0; i < s.size(); ++i)
		if (s[i] >= '0' and s[i] <= '9')
			++cnt[s[i] - '0'];
	for (int i = 9; i >= 0; --i) while (cnt[i]--)
			cout << i;
	return 0;
}