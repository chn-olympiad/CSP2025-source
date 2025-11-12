#include<bits/stdc++.h>
using namespace std;
struct node
{
	long long int x,y,num;
}b[15];
long long int n,m,a[105],s,k;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	cin>>a[i];
	s=a[1];
	sort(a+1,a+1+n,greater<long long int>());
	b[1].x=1;b[1].y=1;b[1].num=a[1];
	for(int i=2;i<=n*m;i++)
	{
		b[i].num=a[i];
		if(b[i-1].y!=n)
		{
			b[i].x=b[i-1].x;
			b[i].y=b[i-1].y+1;
		}
		else
		if(b[i-1].y==n)
		{
			if(b[i-1].x!=m&&b[i-1].y-1==0)
			{
				b[i].x=b[i-1].x+1;
			    b[i].y=b[i-1].y;
			}
			else
			{
				b[i].x=b[i-1].x;
				b[i].y=b[i-1].y-1;
			}
		}
	} 
	for(int i=1;i<=n*m;i++)
	{
		if(b[i].num==s)
		cout<<b[i].x<<" "<<b[i].y;
	}
	return 0;
}
