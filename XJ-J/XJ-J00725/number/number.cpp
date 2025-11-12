#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	string s;
	cin >> s;
	if(s[0] < s[1]) cout << s[1] << s[0];
	else if(s[1] < s[0]) cout << s[0] << s[1];
    else if(s[0] = s[1]) cout << s[0] <<s[1];
	else cout << s[0];
	fclose(stdin);
	fclose(stdout);
	return 0;
}


