#include <bits/stdc++.h>
#include <cstdio>
using namespace std;
int t;
int de[4][100005];
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int v=1;v<=t;v++)
	{
		for(int i=1;i<=100005;i++)de[0][i]=de[1][i]=de[2][i]=de[3][i]=0;
		int f[4]={0,0,0,0};
		int n,sum=0;
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			int x,y,z,d1,d2;
			cin>>x>>y>>z;
			if(x>=y&&y>=z)
			{
				de[1][de[0][1]+1]=x-y;
				de[0][1]++;
				f[1]++;
				sum+=x;
			}
			else if(x>=z&&z>=y)
			{
				de[1][de[0][1]+1]=x-z;
				de[0][1]++;
				f[1]++;
				sum+=x;
			}
			else if(y>=z&&z>=x)
			{
				de[2][de[0][2]+1]=y-z;
				de[0][2]++;
				f[2]++;
				sum+=y;
			}
			else if(y>=x&&x>=z)
			{
				de[2][de[0][2]+1]=y-x;
				de[0][2]++;
				f[2]++;
				sum+=y;
			}
			else if(z>=x&&x>=y)
			{
				de[3][de[0][3]+1]=z-x;
				de[0][3]++;
				f[3]++;
				sum+=z;
			}
			else if(z>=y&&y>=x)
			{
				de[3][de[0][3]+1]=z-y;
				de[0][3]++;
				f[3]++;
				sum+=z;
			}
		}
		int mx=0,x;
		for(int i=1;i<=3;i++)
		{
			if(f[i]>mx)
			{
				mx=f[i];
				x=i;
			}
		 } 
		if(mx<=n/2)cout<<sum;
		else
		{
			sort(de[x]+1,de[x]+1+de[0][x]);
			for(int i=1;i<=mx-n/2;i++)sum-=de[x][i];
			cout<<sum<<endl;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
