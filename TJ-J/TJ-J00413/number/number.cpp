#include<bits/stdc++.h>
using namespace std;
int num[100];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;cin>>s;
	for(char c:s)
	{
		if('0'<=c&&c<='9')
		{
			++num[c-'0'];
		}
	}
	for(int i=9;i>=0;i--)
	{
		for(int j=1;j<=num[i];j++)
		{
			putchar(i+'0');
		}
	}
	return 0;
}
/*
Å¶£¡Ò®£¡£¡£¡
1=ÎÈÀ²£¡£¡£¡£¡£¡£¡£¡£¡£¡ 
*/ 
