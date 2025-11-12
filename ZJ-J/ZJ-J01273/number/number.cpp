#include<bits/stdc++.h>
using namespace std;
int cnt[10];
int main() {
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int len=s.size();
	for(int i=0; i<len; i++) {
		if(s[i]>='0'&&s[i]<='9') {
			for(int j=0; j<10; j++) {
				if(s[i]-'0'==j) {
					cnt[j+1]++;
					break;
				}
			}
		}
	}
	for(int i=10;i>=1;i--){
		for(int j=1;j<=cnt[i];j++){
			cout<<i-1;
		}
	}
	return 0;
}
