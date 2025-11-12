#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
string s;
long long cnt0,cnt1,cnt2,cnt3,cnt4,cnt5,cnt6,cnt7,cnt8,cnt9;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin.sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>s;
	for(long long i=0;i<s.size();i++)
	{
		if(s[i]-'0'==0)
		{
			cnt0++;
		}
		if(s[i]-'0'==1)
		{
			cnt1++;
		}
		if(s[i]-'0'==2)
		{
			cnt2++;
		}
		if(s[i]-'0'==3)
		{
			cnt3++;
		}
		if(s[i]-'0'==4)
		{
			cnt4++;
		}
		if(s[i]-'0'==5)
		{
			cnt5++;
		}
		if(s[i]-'0'==6)
		{
			cnt6++;
		}
		if(s[i]-'0'==7)
		{
			cnt7++;
		}
		if(s[i]-'0'==8)
		{
			cnt8++;
		}
		if(s[i]-'0'==9)
		{
			cnt9++;
		}
	}
	for(int i=1;i<=cnt9;i++)
	{
		cout<<9;
	}
	for(int i=1;i<=cnt8;i++)
	{
		cout<<8;
	}
	for(int i=1;i<=cnt7;i++)
	{
		cout<<7;
	}
	for(int i=1;i<=cnt6;i++)
	{
		cout<<6;
	}
	for(int i=1;i<=cnt5;i++)
	{
		cout<<5;
	}
	for(int i=1;i<=cnt4;i++)
	{
		cout<<4;
	}
	for(int i=1;i<=cnt3;i++)
	{
		cout<<3;
	}
	for(int i=1;i<=cnt2;i++)
	{
		cout<<2;
	}
	for(int i=1;i<=cnt1;i++)
	{
		cout<<1;
	}
	for(int i=1;i<=cnt0;i++)
	{
		cout<<0;
	}
	return 0;
}
/*
kaishiyuedu 8:33
kaishixie 8:37
jieshushijian 8:56
11:22 wo hui lai jian cha le!
kan qi lai mei shen me wen ti
na jiu jing shou wo de yang li de kao yan ba!
ying gai mei sha wen ti
11:25 zou ren T2 jian
*/