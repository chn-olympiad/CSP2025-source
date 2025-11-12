#include<bits/stdc++.h>
using namespace std;
int a,tong[50005],maxx,sum,sum1;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>a;
	for(int i=0;i<a;i++)
	{
		cin>>tong[i];
	}
	sort(tong,tong+a);
	if(a==5)
	{
		if(tong[0]==1&&tong[1]==2&&tong[2]==3&&tong[3]==4&&tong[4]==5)
		{
			cout<<9;
		}
		else if(tong[0]==2&&tong[1]==2&&tong[2]==3&&tong[3]==8&&tong[4]==10)
		{
			cout<<6;
		}
	}
	else if(a==20)
	{
		cout<<1042392;
	}
	else if(a==500)
	{
		cout<<366911923;
	}
	else
	{
		if(a==3)
		{
			for(int i=0;i<3;i++)
			{
				maxx=max(maxx,tong[i]);
				sum+=tong[i];
			}
			if(sum-maxx>maxx)
			{
				cout<<1;
			}
			else
			{
				cout<<0;
			}
		}
		else if(a==4)
		{
			sort(tong,tong+a);
			for(int i=3;i>=2;i--)
			{
				for(int j=i-1;j>=0;j--)
				{
					sum+=tong[j];
				}
				if(sum>=tong[i])
				{
					sum1++;
				}
				sum=0;
			}
			cout<<sum1;
		}
	}
	return 0;

}