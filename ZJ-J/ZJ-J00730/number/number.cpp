#include<bits/stdc++.h>
using namespace std;
string s,ans_s;
int main() {
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int ii=9; ii>=0; ii--) {
		for(int i=0; i<s.size(); i++) {
			if(s[i]==ii+48) {
				ans_s+=s[i];
				s[i]='a';
			}
		}
	}
	cout<<ans_s;
	return 0;
}
