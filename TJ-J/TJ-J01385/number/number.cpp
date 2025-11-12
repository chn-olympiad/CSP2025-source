#include<bits/stdc++.h>
using namespace std;
int main() {
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int a[s.size()+5];
	int a0=0;
	for(int i=0; i<s.size(); i++) {
		if(s[i]>'0'&&s[i]<='9') {
			a[i]=s[i]-'0';
		}
		if(s[i]=='0') {
			a0++;
		}
	}
	sort(a,a+s.size());
	for(int i=s.size(); i>=0; i--) {
		if(a[i]!=0) {
			cout<<a[i];
		}
	}
	for(int i=1; i<=a0; i++) {
		cout<<'0';
	}
	return 0;
}
