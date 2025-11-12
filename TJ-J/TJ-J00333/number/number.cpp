#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	char s[1000010] = {},num[1000010] = {},a[2];
	int j = 0;
	cin>>s;
	for(int i = 0;i<=1000010;i++)
	{
		if(48<=s[i] && s[i]<=58)
		{
			num[j] = s[i];
			j=j+1;
		}
	}
	for(int i = 1;i<=j;i++)
	{
		char maxn = num[i-1];
		for(int x = i;x<=j;x++)
		{
			if(num[x]>maxn)
			{
				maxn = num[x];
				a[0] = num[i-1];
				num[i-1] = num[x];
				num[x] = a[0];
			}
		}
	}
	for(int i = 0;i<=j;i++)
	{
		if(num[i]==48)
		{
			cout<<0;
		}
		if(num[i]==49)
		{
			cout<<1;
		}
		if(num[i]==50)
		{
			cout<<2;
		}
		if(num[i]==51)
		{
			cout<<3;
		}
		if(num[i]==52)
		{
			cout<<4;
		}
		if(num[i]==53)
		{
			cout<<5;
		}if(num[i]==54)
		{
			cout<<6;
		}if(num[i]==55)
		{
			cout<<7;
		}if(num[i]==56)
		{
			cout<<8;
		}if(num[i]==57)
		{
			cout<<9;
		}
	} 
	fclose("number.in");
	fclose("number.out");
	return 0;
} 

