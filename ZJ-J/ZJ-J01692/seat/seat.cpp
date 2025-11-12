#include<bits/stdc++.h>
using namespace std;
int n,m,i,j,cnt,rp;
struct node{
	int id,data;
}a[114];
bool operator <(node x,node y)
{return x.data>y.data;}
inline int read()
{
	int x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9')
	{
		if(c=='-')f=-1;
		c=getchar();
	}while(c<='9'&&c>='0')
	{
		x=(x<<1)+(x<<3)+(c^48);
		c=getchar();
	}
	return f*x;
}
int main()
{
	rp++;
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	n=read();m=read();
	for(i=1;i<=n*m;i++)a[i]=(node){i,read()};
	sort(a+1,a+1+n*m);
	for(i=1;i<=n*m;i++)
		if(a[i].id==1)
		{
			int l=ceil(i*1.0/n),r=0;
			cout<<l<<' ';
			if(l%2==1)r=(i-1)%n+1;
			else r=n-((i-1)%n+1)+1;
			cout<<r;
			return 0;
		}
	return 0;
}
