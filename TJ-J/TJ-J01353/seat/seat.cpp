#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,rem,rem2,w=0,r=0;
	scanf("%d %d",&n,&m);
	int seat[n][m],li[n*m];
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			seat[i][j]=0;
			li[w]=0;
			w+=1;
		}
	}
	
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			scanf("%d",&seat[i][j]);
			if(i==0&&j==0) rem=seat[i][j];
		
		}
	}
	for(int i=0;i<=w;i++)
	{
		for(int j=0;j<=w;j++)
		{
			if(i!=j&&i<j)
			{
				if(li[j]<li[i])
				{
					li[j]+=li[i];
					li[i]=li[j]-li[i];
					li[j]-=li[i];
					if(li[i]==rem) rem2=li[i]+1;
					else if(li[j]==rem) rem2=li[j]+1;
				}
			}
		}
	}
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++,r++)
		{
			if(r==rem2)
			{
				printf("%d %d",i+1,j+1);
				return 0;
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
