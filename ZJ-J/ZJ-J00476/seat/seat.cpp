#include<bits/stdc++.h>
using namespace std;
int n,m,a[105],z;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n*m;i++)
	{
		scanf("%d",a+i);
	}
	z=a[1];
	sort(a+1,a+n*m+1);
	int k;
	for(int i=1;i<=n*m;i++)
	{
		if(a[i]==z)
		{
			k=n*m-i;
			break;
		}
	}
	int i=1,j=1;
	while(k--)
	{
		if(i==1&&j%2==0)j++;
		else if(i==n&&j%2==1)j++;
		else if(j&1)i++;
		else i--;
	}
	printf("%d %d",j,i);
	return 0;
}
