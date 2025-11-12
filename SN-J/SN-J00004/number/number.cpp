//丁煜辰 SN-J00004 西安市曲江第一学校 
#include<bits/stdc++.h>
using namespace std;
#define ll long long

string s;
int x9,x8,x7,x6,x5,x4,x3,x2,x1,xx0;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<=s.size();i++)
	{
		if(s[i]>='0' && s[i]<='9')
		{
			if(s[i]=='9')x9++;
			if(s[i]=='8')x8++;
			if(s[i]=='7')x7++;
			if(s[i]=='6')x6++;
			if(s[i]=='5')x5++;
			if(s[i]=='4')x4++;
			if(s[i]=='3')x3++;
			if(s[i]=='2')x2++;
			if(s[i]=='1')x1++;
			if(s[i]=='0')xx0++;
		}
	}
	for(int i=1;i<=x9;i++)cout<<9;
	for(int i=1;i<=x8;i++)cout<<8;
	for(int i=1;i<=x7;i++)cout<<7;
	for(int i=1;i<=x6;i++)cout<<6;
	for(int i=1;i<=x5;i++)cout<<5;
	for(int i=1;i<=x4;i++)cout<<4;
	for(int i=1;i<=x3;i++)cout<<3;
	for(int i=1;i<=x2;i++)cout<<2;
	for(int i=1;i<=x1;i++)cout<<1;
	for(int i=1;i<=xx0;i++)cout<<0;
}
