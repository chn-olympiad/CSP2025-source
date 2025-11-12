#include<bits/stdc++.h>
using namespace std;
string s;
int cnt[20];
int main() {
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++) {
		if('0'<=s[i]&&s[i]<='9') {
			cnt[s[i]-'0']++;
		}
	}
	bool flag=false;
	for(int i=9;i>=0;i--) {
		if(cnt[i]>0) {
			if(!flag&&i==0) {
				cout<<0;
				return 0;
			}
			flag=true;
			for(int j=1;j<=cnt[i];j++) {
				cout<<i;
			}
		}
	}
	return 0;
}