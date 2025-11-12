#include<bits/stdc++.h>
using namespace std;
string a;
long long s[0x7f];
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	getline(cin,a);
	long long r=a.size();
	if(r>100001)
	{
	for(int i=0;i<r;i++)
		if((a[i]-'0')==9)
			cout<<9;
	for(int i=0;i<r;i++)
		if((a[i]-'0')==8)
			cout<<8;
	for(int i=0;i<r;i++)
		if((a[i]-'0')==7)
			cout<<7;
	for(int i=0;i<r;i++)
		if((a[i]-'0')==6)
			cout<<6;
	for(int i=0;i<r;i++)
		if((a[i]-'0')==5)
			cout<<5;
	for(int i=0;i<r;i++)
		if((a[i]-'0')==4)
			cout<<4;
	for(int i=0;i<r;i++)
		if((a[i]-'0')==3)
			cout<<3;
	for(int i=0;i<r;i++)
		if((a[i]-'0')==2)
			cout<<2;
	for(int i=0;i<r;i++)
		if((a[i]-'0')==1)
			cout<<1;
	for(int i=0;i<r;i++)
		if((a[i]-'0')==0)
			cout<<0;
	}
	else
	{
		long long cnt=0;
		for(int i=0;i<a.size();i++)
	    {
		if((a[i]-'0')>=0&&(a[i]-'0')<=9)
			s[cnt++]=int(a[i]-'0');
	    }
	sort(s,s+cnt,cmp);
	for(int i=0;i<cnt;i++)
		cout<<s[i];
	}
	return 0;
}
