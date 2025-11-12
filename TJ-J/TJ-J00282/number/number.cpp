#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	char s[1000009];
	for(int i = 1; i <= 1000000; i++){
		cin >> s[i];
		if(s[i] >= '0' && s[i] <= '9'){
			cout << s[i];
		}
	}
	return 0;
}
