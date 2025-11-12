#include<bits/stdc++.h>
using namespace std;
int m,n,a[105],c,r,cnt=0;
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n*m;i++)
	{
		scanf("%d",&a[i]); 
	}
	for(int i=2;i<=n*m;i++)
	{
		if(a[1]<a[i])
		{
			cnt++;
		}
	}
	c=cnt/m+1;
	if(c%2)
	{
		r=cnt%m+1;
	}
	else
	{
		r=n-(cnt%m);
	}
	printf("%d %d",c,r);
	return 0;
}
