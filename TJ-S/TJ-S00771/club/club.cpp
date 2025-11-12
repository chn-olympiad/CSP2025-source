#include<bits/stdc++.h> 
using namespace std;
int max(int a,int b,int c)
{
	int num;
	if(a>b&&a>c)
	{
		return a;
	}
	if(b>a&&b>c)
	{
		return b;
	}
	if(c>a&&c>b)
	{
		return c;
	}
	
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int n,x,m[1000000],num[1000];
	cin>>n>>x;
	for(int j=1;j<=x;j++)
	{
		for(int i=1;i<=n;i++)
		{
			cin>>m[i];
		}
		for(int i=1;i<=3;i++)
		{
			max(m[1],m[2],m[3]);
		}
		num[j]=num[j-1]+max(m[j],m[j+1],m[j+2]);
	}
	for(int i=1;i<=n;i++)
	{
		cout<<num[i];
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
