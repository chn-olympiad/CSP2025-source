#include<bits/stdc++.h>
using namespace std;
int n,k,x=1,y=1,z,i;
int a[200004];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]!=1)
			x=0;
		if(a[i]!=0&&a[i]!=1)
			y=0;
	}
	if(k==0)
	{
		if(x==1)
			cout<<n/2;
		else if(y==1)
		{
			z=0;
			for(i=1;i<=n;i++)
			{
				if(i>=n)
					break;
				if(a[i]==0&&a[i+1]==0)
				{
					z++;
					i++;
				}
				if(a[i]==1&&a[i+1]==1)
				{
					z++;
					i++;
				}
			}
			cout<<z;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
