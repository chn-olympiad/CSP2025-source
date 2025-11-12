//SN-J00432Ðì¿¡²©ºº±õÇøºº±õ³õ¼¶ÖÐÑ§
#include <bits/stdc++.h>
using namespace std;

int n,m,a[105];

int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n*m;i++)
	{
		scanf("%d",&a[i]);	
	}
	int j=a[1];
	sort(a+1,a+n*m+1,greater<int>());
	int cnt;
	for(int i=1;i<=n*m;i++)
	{
		if(a[i]==j)
		{
			cnt=i;
		}
	}
	int c=(cnt-1)/n+1;
	int r=n+1;
	if(c%2==0)	
	{
		if(cnt%n==0)	r=1;
		else
		{
			for(int i=1;i<=cnt%n;i++)	r--;	
		}	
	}
	else
	{
		if(cnt%n==0)	r=n;
		else	r=cnt%n;
	}
	printf("%d %d",c,r);
	return 0;
}
