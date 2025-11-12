//SN-J01215 齐睿渊  富平县怀德初级中学 
#include<bits/stdc++.h>
using namespace std;
int a[20];
int main() {
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	string s;
	cin>>s;
	long long sun=0;
	for(int i=0; i<s.size(); i++) {
		if(s[i]=='0') {
			sun=0;
			a[sun]++;
		} else if(s[i]=='1') {
			sun=1;
			a[sun]++;
		} else if(s[i]=='2') {
			sun=2;
			a[sun]++;
		} else if(s[i]=='3') {
			sun=3;
			a[sun]++;
		} else if(s[i]=='4') {
			sun=4;
			a[sun]++;
		} else if(s[i]=='5') {
			sun=5;
			a[sun]++;
		} else if(s[i]=='6') {
			sun=6;
			a[sun]++;
		} else if(s[i]=='7') {
			sun=7;
			a[sun]++;
		} else if(s[i]=='8') {
			sun=8;
			a[sun]++;
		} else if(s[i]=='9') {
			sun=9;
			a[sun]++;
		}
	}
	for(int i=1; i<=a[9]; i++) {
		cout<<9;
	}
	for(int i=1; i<=a[8]; i++) {
		cout<<8;
	}
	for(int i=1; i<=a[7]; i++) {
		cout<<7;
	}
	for(int i=1; i<=a[6]; i++) {
		cout<<6;
	}
	for(int i=1; i<=a[5]; i++) {
		cout<<5;
	}
	for(int i=1; i<=a[4]; i++) {
		cout<<4;
	}
	for(int i=1; i<=a[3]; i++) {
		cout<<3;
	}
	for(int i=1; i<=a[2]; i++) {
		cout<<2;
	}
	for(int i=1; i<=a[1]; i++) {
		cout<<1;
	}
	for(int i=1; i<=a[0]; i++) {
		cout<<0;
	}
	return 0;
}
