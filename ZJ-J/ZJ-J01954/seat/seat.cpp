#include<bits/stdc++.h>
using namespace std;
int a[110],n,m,k;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	int tmp=n*m;
	for(int i=1;i<=tmp;i++)
		scanf("%d",a+i);
	k=a[1];
	stable_sort(a+1,a+1+n*m,greater<int>());
	int x=1,y=1,now=1,pos=1;
	while(a[pos]!=k)
	{
		if(now==-1)
		{
			if(x==1)
			{
				y++;
				now=1;
			}
			else
				x--;
		}
		else
		{
			if(x==n)
			{
				y++;
				now=-1;
			}
			else
				x++;
		}
		pos++;
	}
	printf("%d %d",y,x);
	return 0;
}
