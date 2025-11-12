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

int t,n,s[3],k[3],n1;

struct cl
{
	int id,x;
	void wr()
	{
		_sWint(id);
		putchar(' ');
		_sWint(x);
		putchar(' ');
		putchar(' ');
	}
};

struct node
{
	cl _1,_2,_3;
	int p;
	void read()
	{
		_1.id=0;
		_sRint(_1.x);
		_sRint(_2.x);
		_2.id=1;
		_sRint(_3.x);
		_3.id=2;
		if(_1.x<_2.x)
		{
			cl _4=_1;
			_1=_2;
			_2=_4;
		}
		if(_2.x<_3.x)
		{
			cl _4=_2;
			_2=_3;
			_3=_4;
		}
		if(_1.x<_2.x)
		{
			cl _4=_1;
			_1=_2;
			_2=_4;
		}
		p=_1.x-_2.x;
//		_sWint(p);
//		putchar(' ');
	}
	friend bool operator < (const node x,const node y)
	{
		return x.p!=y.p?x.p>y.p:(x._1.x!=y._1.x?x._1.x>y._1.x:(x._2.x!=y._2.x?x._2.x>y._2.x:x._3.x>y._3.x));
	}
}a[N];

void solve()
{
	_sRint(n);
	n1=n>>1;
	s[0]=s[1]=s[2]=k[0]=k[1]=k[2]=0;
	for(int i=1;i<=n;i++)
	{
		a[i].read();
	}
	stable_sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
	{
		if(k[a[i]._1.id]>=n1)
		{
			k[a[i]._2.id]++;
			s[a[i]._2.id]+=a[i]._2.x;
			continue;
		}
		k[a[i]._1.id]++;
		s[a[i]._1.id]+=a[i]._1.x;
	}
	_sWint(s[0]+s[1]+s[2]);
	putchar('\n');
}

signed main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	_sRint(t);
	while(t--)solve();
	return 0;
}
