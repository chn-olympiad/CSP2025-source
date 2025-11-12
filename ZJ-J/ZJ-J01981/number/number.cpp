#include <bits/stdc++.h>
using namespace std;
int l, t[10];
string s;
int main()
{
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s;
	l = s.size();
	for(int i = 0; i < l; i ++)
		if(s[i] >= '0' && s[i] <= '9')
			t[s[i]-'0']++;
	for(int i = 9; i >= 0; i --)
		for(int j = 1; j <= t[i]; j ++)
			printf("%d", i);
	return 0;
}