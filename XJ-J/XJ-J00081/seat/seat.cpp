#include<bits/stdc++.h>
using namespace std;
int n,m,qmrs;
int arr[110];

int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int a=1;a<=n*m;a++)
	{
		scanf("%d",&arr[a]);
		if(arr[a]>arr[1])
		{
			qmrs++;
		}
	}
	int r=qmrs/n+1,c=0;
	if(qmrs%2==1)
	{
		c=qmrs%n+1;
	}
	else
	{
		c=qmrs%(2*n);
	}
	if(c==0)
	{
		c=1;
	}
	printf("%d %d",r,c);
	
	return 0;
} 
