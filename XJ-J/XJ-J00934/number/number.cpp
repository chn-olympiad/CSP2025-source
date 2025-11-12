#include<bits/stdc++.h>
using namespace std;
string s;
int a[2000005];
int main()
{
	long long int i,j=1; 
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	if(s.size()==1)
	{
	if(s[0]=='1')	
	cout<<1;
	if(s[0]=='2')	
	cout<<2;	
	if(s[0]=='3')	
	cout<<3;	
	if(s[0]=='4')	
	cout<<4;	
	if(s[0]=='5')	
	cout<<5;	
	if(s[0]=='6')	
	cout<<6;	
	if(s[0]=='7')	
	cout<<7;	
	if(s[0]=='8')	
	cout<<8;	
	if(s[0]=='9')	
	cout<<9;	
	return 0;	
	}
	for(i=0;i<s.size();i++)
	if(s[i]>='0'&&s[i]<='9')
	{
	if(s[i]=='0')	
	a[j++]=0;	
	if(s[i]=='1')	
	a[j++]=1;	
	if(s[i]=='2')	
	a[j++]=2;	
	if(s[i]=='3')	
	a[j++]=3;	
	if(s[i]=='4')	
	a[j++]=4;	
	if(s[i]=='5')	
	a[j++]=5;	
	if(s[i]=='6')	
	a[j++]=6;	
	if(s[i]=='7')	
	a[j++]=7;	
	if(s[i]=='8')	
	a[j++]=8;	
	if(s[i]=='9')	
	a[j++]=9;		
	}
	sort(a+1,a+j);
	for(i=j-1;i>=1;i--)
	{
	cout<<a[i];		
	}
	return 0;
}
