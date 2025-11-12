#include<bits/stdc++.h>
using namespace std;

string ans;

int main() {
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	
	string s;
	cin >> s;
	for(int i = 9; i >= 0; i--) {
		for(int j = 0; j < s.size(); j++) {
			if(s[j]=='0'+i) {
				ans += ('0'+i);
			}
		}
	}
	cout << ans;
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}