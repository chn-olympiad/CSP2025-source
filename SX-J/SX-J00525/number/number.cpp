#include <bits/stdc++.h>
using namespace std;
string s;
int main(){
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin>>s;
	sort(s.begin(),s.end());
	int len = s.size();
	for (int i = len - 1;i >= 0;i--)
		if ('0' <= s[i] && s[i] <= '9')
			printf("%c", s[i]);
	printf("\n");
	return 0;
}
