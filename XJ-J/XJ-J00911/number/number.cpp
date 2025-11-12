#include<bits/stdc++.h>
using namespace std;
int x1,x2,x3,x4,x5,x6,x7,x8,x9,x0;
string s;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	
	cin>>s;
	for(int a=0;a<=s.size();a++)
	{
		if(s[a]=='0')
			x0++;
		if(s[a]=='1')
			x1++;
		if(s[a]=='2')
			x2++;
		if(s[a]=='3')
			x3++;
		if(s[a]=='4')
			x4++;
		if(s[a]=='5')
			x5++;
		if(s[a]=='6')
			x6++;
		if(s[a]=='7')
			x7++;
		if(s[a]=='8')
			x8++;
		if(s[a]=='9')
			x9++;
	}
	for(int a=0;a<x9;a++)
		cout<<9;
	for(int a=0;a<x8;a++)
		cout<<8;
	for(int a=0;a<x7;a++)
		cout<<7;
	for(int a=0;a<x6;a++)
		cout<<6;
	for(int a=0;a<x5;a++)
		cout<<5;
	for(int a=0;a<x4;a++)
		cout<<4;
	for(int a=0;a<x3;a++)
		cout<<3;
	for(int a=0;a<x2;a++)
		cout<<2;
	for(int a=0;a<x1;a++)
		cout<<1;
	for(int a=0;a<x0;a++)
		cout<<0;

	
	
	
	
	
	
	return 0;
} 
