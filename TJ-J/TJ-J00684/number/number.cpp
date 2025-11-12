#include <bits/stdc++.h>
using namespace std;
string s;
int a[11];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> s;
	int len = s.length();
	for (int i = 1;i <= len;i++){
		char c;
		c = s[i - 1];
		if ('0' <= c && c <= '9'){
			a[c - '0']++;
		}
	}
	for (int i = 9;i >= 0;i--){
		for (int j = 1;j <= a[i];j++){
			cout << i;
		}
	}
	return 0;
}
