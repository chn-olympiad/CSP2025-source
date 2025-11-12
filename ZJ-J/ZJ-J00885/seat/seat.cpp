#include<bits/stdc++.h>
using namespace std;
int n,m,a[105],buc[105],c,r,cnt=0;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n*m;i++)
	{
		scanf("%d",&a[i]);
		buc[a[i]]=1;
	}
	for(int i=100;i>=0;i--)
	{
		if(buc[i]) cnt++;
		if(i==a[1]) break;
	}
	c=cnt/n;
	if(cnt%n!=0) c++;
	if(c%2==1)
	{
		if(cnt%n==0) r=n;
		else r=cnt%n;
	}
	else
	{
		if(cnt%n==0) r=1;
		else r=n+1-cnt%n;	
	}
	printf("%d %d",c,r);
	return 0;
}