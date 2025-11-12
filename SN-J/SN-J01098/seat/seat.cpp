//SN-J01098  陈和骏  西安高新第一中学 
#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=110;
struct node
{
	int idx,val;
} w[N];
bool cmp(node x,node y)
{
	return x.val>y.val;
}
int rd()
{
	int x=0,f=1;
	char c=getchar();
	while(c<'0' || c>'9')
	{
		if(c=='-') f=-1;
		c=getchar();
	}
	while(c>='0' && c<='9')
	{
		x=(x<<1)+(x<<3)+c-'0';
		c=getchar();
	}
	return x*f;
}
void write(int x)
{
	if(x<0)
	{
		putchar('-');
		write(-x);
	}
	else if(x<10)
	{
		putchar(x+'0');
		return;
	}
	else
	{
		write(x/10);
		putchar(x%10+'0');
	}
}
signed main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n=rd(),m=rd();
	for(int i=1;i<=n*m;i++) w[i].val=rd(),w[i].idx=i;
	sort(w+1,w+1+n*m,cmp);
	for(int i=1;i<=n*m;i++)
	{
		if(w[i].idx==1)
		{
			if(i%n==0)
			{
				write(i/n);
				putchar(' ');
				if((i/n)%2==0) write(1);
				else write(n);
			}
			else
			{
				write(i/n+1);
				putchar(' ');
				if((i/n)%2==1) write(n-i%n+1);
				else write(i%n);
			}
		}
	}
	return 0;
}
/*
3 3
94 95 96 97 98 99 100 93 92
*/
