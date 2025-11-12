#include<bits/stdc++.h>
using namespace std;
int yi,er,sa,si,wu,lv,qi,ba,ju,ln;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	
	for(int i=0;i<=s.length();i++){
		if(s[i]=='0'){
			ln++;
		}
		if(s[i]=='1'){
			yi++;
		}
		if(s[i]=='2'){
			er++;
		}
		if(s[i]=='3'){
			sa++;
		}
		if(s[i]=='4'){
			si++;
		}
		if(s[i]=='5'){
			wu++;
		}
		if(s[i]=='6'){
			lv++;
		}
		if(s[i]=='7'){
			qi++;
		}
		if(s[i]=='8'){
			ba++;
		}
		if(s[i]=='9'){
			ju++;
		}
	}
//	cout<<ln<<yi<<er<<sa<<si<<wu<<lv<<qi<<ba<<ju;
	for(int i=0;i<ju;i++){
		cout<<9;
	}
	for(int i=0;i<ba;i++){
		cout<<8;
	}
	for(int i=0;i<qi;i++){
		cout<<7;
	}
	for(int i=0;i<lv;i++){
		cout<<6;
	}
	for(int i=0;i<wu;i++){
		cout<<5;
	}
	for(int i=0;i<si;i++){
		cout<<4;
	}
	for(int i=0;i<sa;i++){
		cout<<3;
	}
	for(int i=0;i<er;i++){
		cout<<2;
	}
	for(int i=0;i<yi;i++){
		cout<<1;
	}
	for(int i=0;i<ln;i++){
		cout<<0;
	}
	
	
	return 0;
}
