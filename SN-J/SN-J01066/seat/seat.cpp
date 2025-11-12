//SN-J01066 郭宸铭 韩城市桢州初级中学
#include<bits/stdc++.h>
using namespace std;
int s[101010];
int s1[101010];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	int a;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n*m;i++)
	{
		scanf("%d",&s[i]);
	}
	a=s[1];
	int ret;
	for(int i=1;i<=n*m;i++)
	{
		for(int j=1;j<=i;j++)
		{
			if(s[j]>s[i])
			{
				ret=s[i];
				s[i]=s[j];
				s[j]=ret;
			}
		}
	}
	int sum;
	int x=1,y=n*m;
	for(int i=1;i<=n*m;i++)
	{
		s1[x]=s[y];
		x++;
		y--;
	}
	for(int i=1;i<=n*m;i++)
	{
		if(s1[i]==a)
		{
			sum=i;
			break;
		}
	}
	int ret1=sum/n;
	if(sum%n!=0)
	{
		ret1++;
	}
	int ret2;
	if(sum%n==0)
	{
		ret2=n;
	}
	else
	{
		ret2=sum%n;
	}
	int ret3=0;
	if(ret1%2==0)
	{
		for(int i=n;i>=1;i--)
		{
			ret3++;
			if(i==ret2)
			{
				break;
			}
		}
		printf("%d %d",ret1,ret3);
		return 0;
	}
	printf("%d %d",ret1,ret2);
	return 0;
} 
