//西安高新二中  杨嘉乐  SN-J00609
#include<bits/stdc++.h>
using namespace std;
long long a0,a1,a2,a3,a4,a5,a6,a7,a8,a9;
int i=1;
string s1,s2;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s2;;
	for(i=0;i<=1000001;i++)
	{
		if(s2[i]=='0'){a0++;}
		else if(s2[i]=='1'){a1++;}
		else if(s2[i]=='2'){a2++;}
		else if(s2[i]=='3'){a3++;}
		else if(s2[i]=='4'){a4++;}
		else if(s2[i]=='5'){a5++;}
		else if(s2[i]=='6'){a6++;}
		else if(s2[i]=='7'){a7++;}
		else if(s2[i]=='8'){a8++;}
		else if(s2[i]=='9'){a9++;}
		else if(s2[i]==' '){break;}
		else;
	}
	while(a9>0) {cout<<9;  a9--;}
	while(a8>0) {cout<<8;  a8--;}
	while(a7>0) {cout<<7;  a7--;}
	while(a6>0) {cout<<6;  a6--;}
	while(a5>0) {cout<<5;  a5--;}
	while(a4>0) {cout<<4;  a4--;}
	while(a3>0) {cout<<3;  a3--;}
	while(a2>0) {cout<<2;  a2--;}
	while(a1>0) {cout<<1;  a1--;}
	while(a0>0) {cout<<0;  a0--;}
	return 0;
}
