#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int a=0,b=0,c=0,d=0,e=0,f=0,g=0,h=0,o=0,j=0;
	for(int i=0;i<s.size();i++){
		if(s[i]=='9') a++;
		else if(s[i]=='8') b++;
		else if(s[i]=='7') c++;
		else if(s[i]=='6') d++;
		else if(s[i]=='5') e++;
		else if(s[i]=='4') f++;
		else if(s[i]=='3') g++;
		else if(s[i]=='2') h++;
		else if(s[i]=='1') o++;
		else if(s[i]=='0') j++;		 
	}
	for(int i=a;i>=1;i--) cout<<9;
	for(int i=b;i>=1;i--) cout<<8;
	for(int i=c;i>=1;i--) cout<<7;
	for(int i=d;i>=1;i--) cout<<6;
	for(int i=e;i>=1;i--) cout<<5;
	for(int i=f;i>=1;i--) cout<<4;
	for(int i=g;i>=1;i--) cout<<3;
	for(int i=h;i>=1;i--) cout<<2;
	for(int i=o;i>=1;i--) cout<<1;
	for(int i=j;i>=1;i--) cout<<0;
	return 0;
} 
