#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int s[n*m+1];
	for(int i=1;i<=n*m;i++)
	{
		cin>>s[i];
	}
	int zuo=0;
	for(int j=1;j<=m*n;j++)
	{
		zuo++;
		int small=-1;
		int ss;
		for(int i=1;i<=n*m;i++)
		{
		    if(s[i]>small)
			{
				small=s[i];
				ss=i;
			 }
			  
		}
		if(ss==1)
		{
			break;
		}
		else
		{
			s[ss]=-10;
		}
	}
	int y=zuo%m;
	int a=zuo/m;
	if(y==0)
	{
		cout<<a<<" ";
	}
	else
	{
		cout<<a+1<<" ";
		a=a+1;
	}
	for(int j=1;j<=n*m;j++)
	{
		if(j%2==1)
		{
			int o;
			for(int i=1;i<=n;i++)
			{
				zuo--;
				o=i;
			}
			if(zuo<=0)
			{
				cout<<o;
				return 0;
			}
		}
		else
		{
			int o=0;
			for(int i=n;i>=1;i--)
			{
				zuo--;
			}
			if(zuo<=0)
			{
				cout<<n-o;
				return 0;
			}
			o++;
		}
	}
	
	return 0;
 } 
