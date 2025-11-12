#include<bits/stdc++.h>
using namespace std;
long long int a[20];

int main() {
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	long long int len=s.size();
	for(int i=0; i<len; i++) {
		if(s[i]>='0'&&s[i]<='9') {
			a[s[i]-'0']++;
		}
	}
	for(long long int i=9; i>=0; i--) {
		for(long long int j=1; j<=a[i]; j++) {
			cout<<i;
		}
	}

	return 0;
}
