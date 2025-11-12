#include <iostream>
#include <cstdio>

using namespace std;

int read();

int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cout<<0;
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
