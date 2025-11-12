#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

#define N 100005

void _sRuint(unsigned int&x)
{
	x=0;
	char c=getchar();
	while(!isdigit(c))c=getchar();
	while(isdigit(c))
	{
		x=(x<<3)+(x<<1)+(c^48);
		c=getchar();
	}
}

void _sRint(int&x)
{
	bool f=false;
	x=0;
	char c=getchar();
	while(!isdigit(c))
	{
		if(c=='-')
		{
			f=true;
			break;
		}
		c=getchar();
	}
	while(isdigit(c))
	{
		x=(x<<3)+(x<<1)+(c^48);
		c=getchar();
	}
	if(f)x=-x;
}

void _sWuint(unsigned int x)
{
	if(x>9)
	{
		_sWuint(x/10);
	}
	putchar(((x%10)^48));
}

void _sWint(int x)
{
	if(x<0)
	{
		x=-x;
		putchar('-');
	}
	_sWuint(x);
}

void _sRuint(unsigned long long&x)
{
	x=0;
	char c=getchar();
	while(!isdigit(c))c=getchar();
	while(isdigit(c))
	{
		x=(x<<3)+(x<<1)+(c^48);
		c=getchar();
	}
}

void _sRll(long long&x)
{
	bool f=false;
	x=0;
	char c=getchar();
	while(!isdigit(c))
	{
		if(c=='-')
		{
			f=true;
			break;
		}
		c=getchar();
	}
	while(isdigit(c))
	{
		x=(x<<3)+(x<<1)+(c^48);
		c=getchar();
	}
	if(f)x=-x;
}

void _sWull(unsigned long long x)
{
	if(x>9)
	{
		_sWull(x/10);
	}
	putchar(((x%10)^48));
}

void _sWll(long long x)
{
	if(x<0)
	{
		x=-x;
		putchar('-');
	}
	_sWull(x);
}

int n,q;

signed main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	return 0;
}

