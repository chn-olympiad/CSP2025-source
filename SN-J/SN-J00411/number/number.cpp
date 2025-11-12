#include<bits/stdc++.h>
#define ll long long
using namespace std;
string s;
ll a[100005],b0,b1,b2,b3,b4,b5,b6,b7,b8,b9;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(ll i=0;i<s.size();++i)
	{
		if(int(s[i])>=48&&int(s[i])<=57)
		{
			a[i]=int(s[i])-48;
			if(a[i]==0)
			{
				b0++;
			}
			if(a[i]==1)
			{
				b1++;
			}	
			if(a[i]==2)
			{
				b2++;
			}	
			if(a[i]==3)
			{
				b3++;
			}	
			if(a[i]==4)
			{
				b4++;
			}	
			if(a[i]==5)
			{
				b5++;
			}	
			if(a[i]==6)
			{
				b6++;
			}	
			if(a[i]==7)
			{
				b7++;
			}	
			if(a[i]==8)
			{
				b8++;
			}	
			if(a[i]==9)
			{
				b9++;
			}		
		}
	}
	for(int j=0;j<b9;++j)
	{
		cout<<9;
	}
	for(int j=0;j<b8;++j)
	{
		cout<<8;
	}
	for(int j=0;j<b7;++j)
	{
		cout<<7;
	}
	for(int j=0;j<b6;++j)
	{
		cout<<6;
	}
	for(int j=0;j<b5;++j)
	{
		cout<<5;
	}
	for(int j=0;j<b4;++j)
	{
		cout<<4;
	}
	for(int j=0;j<b3;++j)
	{
		cout<<3;
	}
	for(int j=0;j<b2;++j)
	{
		cout<<2;
	}
	for(int j=0;j<b1;++j)
	{
		cout<<1;
	}
	for(int j=0;j<b0;++j)
	{
		cout<<0;
	}
	return 0;
}
