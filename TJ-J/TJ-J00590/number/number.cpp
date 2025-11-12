#include<bits/stdc++.h>
using namespace std;
bool cmp(char x,char y) {
	return x>y;
}
int main() {
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	char a[1000005];
	string s;
	cin>>s;
	int j=1;
	for(int i=0; i<s.size(); i++) {
		if(s[i]>='0'&&s[i]<='9') {
			a[j]=s[i];
			j++;
		}
	}
	sort(a+1,a+j,cmp);
	int kg=1;
	for(int i=1; i<j; i++) {
		if(a[i]!='0') {
			kg=0;
		}
		if(kg==0) {
			cout<<a[i];
		}
	}
	if(kg==1){
		cout<<0;
	}
	return 0;
}


