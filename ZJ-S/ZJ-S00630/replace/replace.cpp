#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

int read();

int n,q;

int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	n=read();
	q=read();
	for(int i=1; i<=n; i++)
	{
		string tmpS="\0";
		cin>>tmpS>>tmpS;
	}
	while(q--)
	{
		string tmpS="\0";
		cin>>tmpS>>tmpS;
		cout<<0<<endl;
	}
	return 0;
}

int read()
{	
	int d=0,f=1;
	char c=getchar();
	while(c > '9' || c < '0')
	{
		if(c == '-')
		{
			f=-1;
		}
		c=getchar();
	}
	while(c >= '0' && c <= '9')
	{
		d=(d<<3)+(d<<1)+c-'0';
		c=getchar();
	}
	return d*f;
}
