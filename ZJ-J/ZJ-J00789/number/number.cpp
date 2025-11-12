#include <bits/stdc++.h>
using namespace std;
string s1,s2="";
bool cmp(char a,char b) {
	return a>b;
}
int main() {
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s1;
	for(int i=0; i<s1.size(); i++) {
		if(isdigit(s1[i])) {
			s2+=s1[i];
		}
	}
	sort(s2.begin(),s2.end(),cmp);	
	cout<<s2;
	return 0;
}