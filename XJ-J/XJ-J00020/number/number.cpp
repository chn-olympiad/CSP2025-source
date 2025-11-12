#include<bits/stdc++.h> 
using namespace std;
int main () {
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	for(int i = 0;i < s.size();i++) {
		if(s[i] >= '0' && s[i] <= '9') {
			continue;
		}
		s[i] = ' ';
	}
	for(int i = 0;i < s.size();i++) {
		for(int j = 1+i;j < s.size();j++) {
			if(s[i] > s[j] && i < j) {
				swap(s[i],s[j]);
			}
		}
	}
	reverse(s.begin(),s.end());
	for(int i = 0;i < s.size();i++) {
		if(s[i] == ' ') break;
		cout<<s[i];
	}
	return 0;
} 
