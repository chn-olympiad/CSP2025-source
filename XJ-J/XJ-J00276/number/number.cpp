#include <bits/stdc++.h>
using namespace std;
int main() {
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int tong[10]={0};
	for(int i=0;i<s.size();i++) {
		if(s[i]>='0'&&s[i]<='9') {
			tong[(int)(s[i]-'0')]++;
		}
	}
	for(int i=9;i>=0;i--) {
		while(tong[i]>0) {
			cout<<i;
			tong[i]--;
		}
	}
	return 0;
} 
