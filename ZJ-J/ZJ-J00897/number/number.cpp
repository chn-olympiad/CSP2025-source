#include<bits/stdc++.h>
using namespace std;
const int N=1e6+100;
string s;
int cnt,a[15];
int main() {
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++) {
		if(s[i]<='9'&&s[i]>='0') a[s[i]-'0']++;
	}
	for(int i=9;i>=0;i--) {
		for(int j=1;j<=a[i];j++) {
			cout<<i;
		}
	}
	return 0;
}
