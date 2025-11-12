#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	scanf("%d",&n);
	int maxs=0;
	int a[n+5];
	int cnt=0;
	int s=0;
	for(int i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	int end1=0;
	for(int i=0;i<n;i++)
	{
		for(int j=i;j<n;j++)
		{
			s=0;
			for(int z=i;z<=j;z++)
			{
				maxs=max(maxs,a[z]);
				s+=a[z];
			}
			if(s/maxs>2||(s/maxs==2&&s%maxs!=0))
			{
				cnt++;
			}
		}
		end1=i;
		maxs=0;
		for(int j=i;j<n;j++)
		{
			s=0;
			if(end1+1<j)
			{
				for(int z=i;z<=end1;z++)
				{
					maxs=max(maxs,a[z]);
					s+=a[z];
				}
				if(s/maxs>2||(s/maxs==2&&s%maxs!=0))
				{
					cnt++;
				}
				end1++;
			}	
		}
		maxs=0;
	}
	printf("%d",cnt);
	fclose(stdin);
	fclose(stdout);
}
