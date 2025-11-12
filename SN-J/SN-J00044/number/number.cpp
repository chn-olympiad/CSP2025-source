#include<bits/stdc++.h>
using namespace std;
string s;
int s0,s1,s2,s3,s4,s5,s6,s7,s8,s9;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]=='1'){
			s1++;
		}else if(s[i]=='2'){
			s2++;
		}else if(s[i]=='3'){
			s3++;
		}else if(s[i]=='4'){
			s4++;
		}else if(s[i]=='5'){
			s5++;
		}else if(s[i]=='6'){
			s6++;
		}else if(s[i]=='7'){
			s7++;
		}else if(s[i]=='8'){
			s8++;
		}else if(s[i]=='9'){
			s9++;
		}else if(s[i]=='0'){
			s0++;
		}
	}
	for(int i=0;i<s9;i++){
		cout<<9;
	}
	for(int i=0;i<s8;i++){
		cout<<8;
	}
	for(int i=0;i<s7;i++){
		cout<<7;
	}
	for(int i=0;i<s6;i++){
		cout<<6;
	}
	for(int i=0;i<s5;i++){
		cout<<5;
	}
	for(int i=0;i<s4;i++){
		cout<<4;
	}
	for(int i=0;i<s3;i++){
		cout<<3;
	}
	for(int i=0;i<s2;i++){
		cout<<2;
	}
	for(int i=0;i<s1;i++){
		cout<<1;
	}
	for(int i=0;i<s0;i++){
		cout<<0;
	}
}
