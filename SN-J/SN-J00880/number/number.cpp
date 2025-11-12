#include<bits/stdc++.h>
using namespace std;
string s,ans;
long long a[1000010];
int main() {
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0; i<s.size(); i++) {
		if(s[i]=='1'||s[i]=='2'||s[i]=='3'||s[i]=='4'||s[i]=='5'||s[i]=='6'||s[i]=='7'||s[i]=='8'||s[i]=='9'||s[i]=='0') {
			a[s[i]-'0']++;
		}
	}
	for(int i=9; i>=0; i--) {
		if(a[i]!=0) {
			for(int j=0;j<a[i];j++){
				ans+=i+'0';
			}

		}
	}
	cout<<ans;
	return 0;
}



