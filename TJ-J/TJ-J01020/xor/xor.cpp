#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int x(int a,int b)
{
	return a^b;
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	scanf("%d%d",&n,&k);
	int a[n+5];
	int cnt=0;
	for(int i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	for(int i=0;i<n;i++)
	{
		for(int j=i;j<n;j++)
		{
			int s=a[i];
			for(int z=i+1;z<=j;z++)
			{
				s=x(s,a[z]);
			}
			if(s==k)
			{
				cnt++;
				i=j+1;
			}
		}
	}
	printf("%d",cnt);
	fclose(stdin);
	fclose(stdout);
}
