#include<bits/stdc++.h>
using namespace std;
int v[110];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	for(int i=0;i<=s.size()-1;i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			v[s[i]-'0']++;
		}
	}
	for(int i=1;i<=v[9];i++)
	{
		cout<<9;
	}
	for(int i=1;i<=v[8];i++)
	{
		cout<<8;
	}
	for(int i=1;i<=v[7];i++)
	{
		cout<<7;
	}
	for(int i=1;i<=v[6];i++)
	{
		cout<<6;
	}
	for(int i=1;i<=v[5];i++)
	{
		cout<<5;
	}
	for(int i=1;i<=v[4];i++)
	{
		cout<<4;
	}
	for(int i=1;i<=v[3];i++)
	{
		cout<<3;
	}
	for(int i=1;i<=v[2];i++)
	{
		cout<<2;
	}
	for(int i=1;i<=v[1];i++)
	{
		cout<<1;
	}
	for(int i=1;i<=v[0];i++)
	{
		cout<<0;
	}



	return 0;
}